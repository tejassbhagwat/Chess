#include <iostream>
#include <string>
#include "chess.h"
using namespace std;

//  Constructor
movement :: movement(board *brd, white_player *w, black_player *b)    {
    BOARD = brd;
    WHITE_PLAYER = w;
    BLACK_PLAYER = b;
    draw = false;   //  Variable to agree a draw in the game
    save = false;   // Variable to save the game to be played later
}

//  Checking whether input position is within the specified board dimensions
bool valid_input(string s)    {
    if(s.length() != 2)
        return false;
    if  (!(s[1] >= '1' && s[1] <= '8'))
        return false;
    if  (!(tolower(s[0]) >= 'a' && tolower(s[0]) <= 'h'))
        return false;
    return true;
}

//  Function to convert string into lowercase
string lower(string s)  {
    int n = s.length();
    for(int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
    return s;
}

//  Function to accept or reject a draw offer in the game by a player
void movement :: draw_offer()   {
    char s[10];
    do  {
        cout << "Your opponent has proposed a draw!" << endl;
        cout << "Enter Yes to accept. No to reject" << endl;
        cin >> s;
    }while(!(lower(s) == "yes" || lower(s) == "no"));
    if(lower(s) == "yes") {
        this->draw = true;
    }
    else if(lower(s) == "no") {
        this->draw = false;
    }
}

//  Returns status of draw offer
bool movement :: draw_offer_accept()    {
    return this->draw;
}

//  Function to load a saved game move
void movement :: load_move(string s1, string s2) {
    this->x1 = (int)(tolower(s1[0]) - 'a' + 1);
    this->y1 = (int)(s1[1] - '0');
    this->x2 = (int)(tolower(s2[0]) - 'a' + 1);
    this->y2 = (int)(s2[1] - '0');
    this->start = &BOARD->b[x1-1][y1-1];
    this->finish = &BOARD->b[x2-1][y2-1];
}

//  Function to save game
void movement :: save_game()    {
    this->save = true;
}

//  Returns status whether a game is saved
bool movement :: is_game_saved()    {
    return this->save;
}

//  Obtain user input of move to be made
void movement :: get_move()   {
    do{
        cout << "Enter starting position: ";
        cin >> this->s1;
        if(lower(s1) == "draw") {           //  Draw offer initiated
            draw_offer();
            if(draw_offer_accept())
                return;
        }
            if(lower(s1) == "save") {      // The game is saved, can be played later by loading the saved game
                save_game();
                return;
            }

    }while(!valid_input(s1));               //  Checks whether the input is valid
    this->x1 = (int)(tolower(s1[0]) - 'a' + 1);
    this->y1 = (int)(s1[1] - '0');
    do{
        cout << "Enter finishing position: ";
        cin >> this->s2;
    }while(!valid_input(s2));
    this->x2 = (int)(tolower(s2[0]) - 'a' + 1);
    this->y2 = (int)(s2[1] - '0');

    this->start = &BOARD->b[x1-1][y1-1];    //  Starting and finishing positions described by the user
    this->finish = &BOARD->b[x2-1][y2-1];
}

//  Returns starting position described by the user
string movement :: return_start()   {
    this->s1[0] = tolower(this->s1[0]);
    return this->s1;
}

//  Returns finishing position described by the user
string movement :: return_finish()  {
    this->s2[0] = tolower(this->s2[0]);
    return this->s2;
}

//  Function to determine whether move by white pieces is valid
bool movement :: white_valid()  {
    if(isupper(start->annotation) || (start->annotation == 'o'))  {     //  Starting position must be white (lowercase)
        return false;                                                   // o denotes empty spot
    }
    switch(this->start->annotation) {
        case 'p' :      return (white_pawn_valid() && !white_illegal_move());   //  Checks whether move by specified piece is valid and
                        break;                                                  // white king is not in check after the intended move
        case 'b' :      return (white_bishop_valid() && !white_illegal_move());
                        break;
        case 'n' :      return (white_knight_valid() && !white_illegal_move());
                        break;
        case 'r' :      return (white_rook_valid() && !white_illegal_move());
                        break;
        case 'q' :      return (white_queen_valid() && !white_illegal_move());
                        break;
        case 'k' :      return ((white_king_castle_valid() || white_queen_castle_valid() || white_king_valid()) && !white_illegal_move());
                        break;
        //  Checks whether king move is valid for castling king side or queen side
        default : return false;
    }

}

//  Function to check whether move by black pieces is valid
bool movement :: black_valid()  {
     if(islower(start->annotation) || (start->annotation == 'o'))  {
        return false;
    }
    switch(this->start->annotation) {
        case 'P' :          return (black_pawn_valid() && !black_illegal_move());
                            break;
        case 'B' :          return (black_bishop_valid() && !black_illegal_move());
                            break;
        case 'N' :          return (black_knight_valid() && !black_illegal_move());
                            break;
        case 'R' :          return (black_rook_valid() && !black_illegal_move());
                            break;
        case 'Q' :          return (black_queen_valid() && !black_illegal_move());
                            break;
        case 'K' :          return ((black_king_castle_valid() || black_queen_castle_valid() || black_king_valid()) && !black_illegal_move());
                            break;

        default : return false;
    }
}

// Function to check whether move by white pawn is valid
bool movement :: white_pawn_valid()   {
if(finish->annotation == 'K')               // Cannot capture king
    return false;
if((start->x == finish->x) && (finish->annotation == 'o')  && (finish->y == start->y + 1))  // One move ahead if legal
                        return true;
                        else if(((start->x == finish->x) && finish->annotation == 'o') && (finish->y == start->y + 2) && (start->y == 2) && BOARD->b[start->x-1][start->y].annotation == 'o')   // Two moves ahead if on starting spot
                            return true;
                        else if(start->x == (finish->x - 1) && (finish->y = start->y + 1) && (isupper(finish->annotation)))     // Capture diagonally
                            return true;
                         else if(start->x == (finish->x + 1) && (finish->y = start->y + 1) && (isupper(finish->annotation)))    // Capture diagonally
                            return true;
                            else
                                return false;
}

//  Function to check whether move by white bishop is valid
bool movement :: white_bishop_valid()   {
    if(finish->annotation == 'K')       //  Cannot capture king
        return false;
    if((islower(finish->annotation)) && finish->annotation != 'o')  // Finishing position cannot be occupied by white piece
        return false;

    //  Must move diagonally i.e. slope y/x = 1 i.e y = x
    if  (!(((this->start->x - this->finish->x) == (this->start->y - this->finish->y)) || ((this->start->x - this->finish->x) == (this->finish->y - this->start->y))))
        return false;

    //  Sub-functions to determine legal moves in all 4 diagonals from starting position
    if(start->x < finish->x && start->y < finish->y)    {
                int j = start->y + 1;
            for(int i = start->x + 1; i < finish->x; i++, j++)   {
                if(this->BOARD->b[i-1][j-1].annotation != 'o')      // If a position between start and finish is not empty, not a legal move
                    return false;
            }
        return true;
    }
    else if(start->x < finish->x && finish->y < start->y)    {
        int j = start->y - 1;
        for(int i = start->x + 1; i < finish->x; i++, j--)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')          // If a position between start and finish is not empty, not a legal move
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && start->y < finish->y)   {
        int j = start->y + 1;
        for(int i = start->x - 1; i > finish->x; i--, j++)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')          // If a position between start and finish is not empty, not a legal move
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && finish->y < start->y)   {
        int j = start->y - 1;
        for(int i = start->x - 1; i > finish->x; i--, j--) {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')          // If a position between start and finish is not empty, not a legal move
                return false;
        }
        return true;
    }
    else return false;
}

//  Function to determine whether move by black bishop is valid
bool movement :: black_bishop_valid()   {
    if(finish->annotation == 'k')           //  Cannot capture king
        return false;
    if((isupper(finish->annotation)))       // Finish position cannot be occupied by black piece
        return false;

    //  Must move diagonally
    if  (!(((this->start->x - this->finish->x) == (this->start->y - this->finish->y)) || ((this->start->x - this->finish->x) == (this->finish->y - this->start->y))))
        return false;

    if(start->x < finish->x && start->y < finish->y)    {
                int j = start->y + 1;
            for(int i = start->x + 1; i < finish->x; i++, j++)   {
                if(this->BOARD->b[i-1][j-1].annotation != 'o')  // If position between start and finish is not empty, not a legal move
                    return false;
            }
        return true;
    }
    else if(start->x < finish->x && finish->y < start->y)    {
        int j = start->y - 1;
        for(int i = start->x + 1; i < finish->x; i++, j--)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')  // If position between start and finish is not empty, not a legal move
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && start->y < finish->y)   {
        int j = start->y + 1;
        for(int i = start->x - 1; i > finish->x; i--, j++)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')  // If position between start and finish is not empty, not a legal move
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && finish->y < start->y)   {
        int j = start->y - 1;
        for(int i = start->x - 1; i > finish->x; i--, j--) {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')  // If position between start and finish is not empty, not a legal move
                return false;
        }
        return true;
    }
    else return false;
}

//  Function to determine whether move by white knight is valid
bool movement :: white_knight_valid()   {
    if(finish->annotation == 'K')       //  Cannot capture king
        return false;
    if(islower(finish->annotation) && finish->annotation != 'o')    // Finish position cannot be occupied by white piece
        return false;

    //  Knights move in L shape
    if((start->x - finish->x == 2) || (start->x - finish->x == -2))    {
        if((finish->y - start->y == 1) || (finish->y - start->y == -1))
            return true;
            else return false;
    }
    else if((start->x - finish->x == 1) || (start->x - finish->x == -1))  {
        if((finish->y - start->y == 2) || (finish->y - start->y == -2))
            return true;
            else return false;
    }
    else
        return false;

}

//  Function to check whether move by black knight is valid
bool movement :: black_knight_valid()   {
    if(finish->annotation == 'k')           //  Cannot capture king
        return false;
    if(isupper(finish->annotation))         // Finish position cannot be occupied by black piece
        return false;

    //  Knights move in L shape
    if((start->x - finish->x == 2) || (start->x - finish->x == -2))    {
        if((finish->y - start->y == 1) || (finish->y - start->y == -1))
            return true;
            else return false;
    }
    else if((start->x - finish->x == 1) || (start->x - finish->x == -1))  {
        if((finish->y - start->y == 2) || (finish->y - start->y == -2))
            return true;
            else return false;
    }
    else
        return false;

}

//  Function to check whether move by white rook is valid
bool movement :: white_rook_valid() {
    if(finish->annotation == 'K')       // Cannot capture king
        return false;
    if(islower(finish->annotation) && finish->annotation != 'o')    //  Finish position cannot be occupied by white piece
        return false;

    // Rook can generally move 4 ways from starting position - left, right, up, down
    //  1) Up
    if(start->x == finish->x)   {
            if(finish->y > start->y)    {
                for(int i = start->y + 1; i < finish->y; i++)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                        return false;
                }
                return true;
            }
            //  2) Down
            else if(finish->y < start->y)   {
                for(int i = start->y - 1; i > finish->y; i--)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                        return false;
                }
                return true;
            }
    }
    //  3) Right
    else if(start->y == finish->y)  {
        if(start->x < finish->x)    {
            for(int i = start->x + 1; i < finish->x; i++)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                    return false;
            }
            return true;
        }
        //  4) Left
        else if(start->x > finish->x)   {
            for(int i = start->x - 1; i > finish->x; i--)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                    return false;
            }
            return true;
        }
    }
        return false;
}

//  Function to check whether move by black rook is valid
bool movement :: black_rook_valid() {
    if(finish->annotation == 'k')       //  Cannot capture king
        return false;
    if(isupper(finish->annotation))     //  Finish position cannot be occupied by black piece
        return false;
    if(start->x == finish->x)   {
            //  Up
            if(finish->y > start->y)    {
                for(int i = start->y + 1; i < finish->y; i++)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                        return false;
                }
                return true;
            }
            //  Down
            else if(finish->y < start->y)   {
                for(int i = start->y - 1; i > finish->y; i--)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                        return false;
                }
                return true;
            }
    }
    else if(start->y == finish->y)  {
        //  Right
        if(start->x < finish->x)    {
            for(int i = start->x + 1; i < finish->x; i++)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                    return false;
            }
            return true;
        }
        //  Left
        else if(start->x > finish->x)   {
            for(int i = start->x - 1; i > finish->x; i--)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o') // If position between start and finish is not empty, not a legal move
                    return false;
            }
            return true;
        }
    }
        return false;
}

//  Queen moves as combination of bishop and rook - diagonally and vertically/horizontally
bool movement :: white_queen_valid()    {
    return (white_bishop_valid() || white_rook_valid());
}

//  Queen moves as combination of bishop and rook - diagonally and vertically/horizontally
bool movement :: black_queen_valid()    {
    return (black_bishop_valid() || black_rook_valid());
}

//  Function to determine whether move by black pawn is valid
bool movement :: black_pawn_valid() {
    if(finish->annotation == 'k')   //  Cannot capture king
        return false;
    if((start->x == finish->x) && (finish->annotation == 'o') && (finish->y == start->y - 1))   //  One move ahead if legal
                        return true;
                        else if((start->x == finish->x) && (finish->annotation == 'o') && (finish->y == start->y - 2) && (start->y == 7) && BOARD->b[start->x-1][start->y-2].annotation == 'o') //  Two moves ahead if on starting spot and legal
                            return true;
                        else if(start->x == (finish->x - 1) && (finish->y = start->y - 1) && (islower(finish->annotation)) && (finish->annotation != 'o'))  //  Capture diagonally
                            return true;
                         else if(start->x == (finish->x + 1) && (finish->y = start->y - 1) && (islower(finish->annotation)) && (finish->annotation != 'o')) //  Capture diagonally
                            return true;
                            else
                                return false;

}

//  Function to check whether king side castle by white king is valid
bool movement :: white_king_castle_valid()  {
    if(BOARD->white_check())    //  Cannot castle if king is in check
        return false;
    if((this->start == this->WHITE_PLAYER->white_king.s) && (this->finish == &BOARD->b[6][0]) && this->WHITE_PLAYER->white_king.castling_possible && this->WHITE_PLAYER->white_rook[1].castling_possible)  {
       if(BOARD->b[5][0].annotation == 'o' && BOARD->b[6][0].annotation == 'o') {
        board check_eval_board;
        check_eval_board = *BOARD;                      //  Check that castling squares are not attacked by
        check_eval_board.b[5][0].annotation = 'k';      // black pieces
        check_eval_board.b[4][0].annotation = 'o';
        if(check_eval_board.white_check())
            return false;
        check_eval_board.b[6][0].annotation = 'k';
        check_eval_board.b[5][0].annotation = 'o';
        if(check_eval_board.white_check())
            return false;
        return true;
       }
       else
        return false;

    }
    return false;
}

//  Function to check whether move by white king is valid
bool movement :: white_king_valid() {
    if(islower(finish->annotation) && finish->annotation != 'o')    //  Finish position cannot be occupied by white piece
        return false;
    if(this->start == this->WHITE_PLAYER->white_king.s) {
        if((finish->y - start->y == 1 || finish->y - start->y == 0 || finish->y - start->y == -1)
           && (finish->x - start->x == 1 || finish->x - start->x == 0 || finish->x - start->x == -1))   //  King can move one place in all directions if legal
            return true;
    }
    return false;
}

//  Function to check whether move by black king is valid
bool movement :: black_king_valid() {
    if(isupper(finish->annotation))
        return false;
    if(this->start == this->BLACK_PLAYER->black_king.s) {
         if((finish->y - start->y == 1 || finish->y - start->y == 0 || finish->y - start->y == -1)
           && (finish->x - start->x == 1 || finish->x - start->x == 0 || finish->x - start->x == -1))
            return true;
    }
    return false;
}

//  Function to check whether black king can castle king side
bool movement :: black_king_castle_valid()  {
    if(BOARD->black_check())
        return false;
    if((this->start == this->BLACK_PLAYER->black_king.s) && (this->finish == &BOARD->b[6][7]) && this->BLACK_PLAYER->black_king.castling_possible && this->BLACK_PLAYER->black_rook[1].castling_possible)  {
       if(BOARD->b[5][7].annotation == 'o' && BOARD->b[6][7].annotation == 'o') {
        board check_eval_board;
        check_eval_board = *BOARD;
        check_eval_board.b[5][7].annotation = 'K';
        check_eval_board.b[4][7].annotation = 'o';
        if(check_eval_board.black_check())
            return false;
        check_eval_board.b[6][7].annotation = 'K';
        check_eval_board.b[5][7].annotation = 'o';
        if(check_eval_board.black_check())
            return false;
        return true;
       }
       else
        return false;
    }
    return false;
}

//  Function to check whether white king can castle queen side
bool movement :: white_queen_castle_valid() {
    if(BOARD->white_check())
        return false;
    if((this->start == this->WHITE_PLAYER->white_king.s) && (this->finish == &BOARD->b[2][0]) && this->WHITE_PLAYER->white_king.castling_possible && this->WHITE_PLAYER->white_rook[0].castling_possible)   {
        if(BOARD->b[3][0].annotation == 'o' && BOARD->b[2][0].annotation == 'o' && BOARD->b[1][0].annotation == 'o')    {
            board check_eval_board;
            check_eval_board = *BOARD;
            check_eval_board.b[3][0].annotation = 'k';
            check_eval_board.b[4][0].annotation = 'o';
            if(check_eval_board.white_check())
                return false;
            check_eval_board.b[2][0].annotation = 'k';
            check_eval_board.b[3][0].annotation = 'o';
            if(check_eval_board.white_check())
                return false;
            check_eval_board.b[1][0].annotation = 'k';
            check_eval_board.b[2][0].annotation = 'o';
            if(check_eval_board.white_check())
                return false;
            return true;
        }
        else return false;
    }
    return false;
}

//  Function to check whether black king can castle queen side
bool movement :: black_queen_castle_valid() {
    if(BOARD->black_check())    //  Cannot castle if the king is in check
        return false;
    if((this->start == this->BLACK_PLAYER->black_king.s) && (this->finish == &BOARD->b[2][7]) && this->BLACK_PLAYER->black_king.castling_possible && this->BLACK_PLAYER->black_rook[0].castling_possible)   {
        if(BOARD->b[3][7].annotation == 'o' && BOARD->b[2][7].annotation == 'o' && BOARD->b[1][7].annotation == 'o')    {
            board check_eval_board;
            check_eval_board = *BOARD;
            check_eval_board.b[3][7].annotation = 'K';      //  Check whether any of the castling places are
            check_eval_board.b[4][7].annotation = 'o';      //  attacked by white pieces
            if(check_eval_board.black_check())
                return false;
            check_eval_board.b[2][7].annotation = 'K';
            check_eval_board.b[3][7].annotation = 'o';
            if(check_eval_board.black_check())
                return false;
            check_eval_board.b[1][7].annotation = 'K';
            check_eval_board.b[2][7].annotation = 'o';
            if(check_eval_board.black_check())
                return false;
            return true;
        }
        else return false;
    }
    return false;
}

//  Function to execute a move
void movement :: move_piece()   {
    if(this->white_valid()) {
        switch(this->start->annotation) {
        //  Pawn move
        case 'p': for(int i = 0; i < 8; i++)    {
                        if(this->WHITE_PLAYER->white_pawn[i].s == this->start)  {
                            if(finish->y == 8 && !(this->WHITE_PLAYER->white_pawn[i].promotion))  {
                                this->WHITE_PLAYER->white_pawn[i].promotion = true;         //  If pawn reaches last row, promote to queen
                                if(isupper(finish->annotation)) {
                                    this->BLACK_PLAYER->capture(finish);                    // Capture black piece diagonally
                                }
                                this->WHITE_PLAYER->white_pawn[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                                this->start->annotation = 'o';
                                this->finish->annotation = 'q';
                            }
                            else    {
                            if(isupper(finish->annotation)) {

                                this->BLACK_PLAYER->capture(finish);        //  If finishing position is occupied by opponent piece, capture it
                            }
                            this->WHITE_PLAYER->white_pawn[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];  //  Move piece
                            this->start->annotation = 'o';
                            this->finish->annotation = 'p';
                            }
                        }
                    }
                    break;

            //  Bishop move
            case 'b' :  for(int i = 0; i < 2; i++)   {
                        if(this->WHITE_PLAYER->white_bishop[i].s == this->start)    {
                            if(isupper(finish->annotation)) {
                                this->BLACK_PLAYER->capture(finish);
                            }
                             this->WHITE_PLAYER->white_bishop[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'b';
                            }
                        }
                        break;

            //  Knight move
            case 'n' : for(int i = 0; i < 2; i++)   {
                        if(this->WHITE_PLAYER->white_knight[i].s == this->start)    {
                            if(isupper(finish->annotation)) {
                                this->BLACK_PLAYER->capture(finish);
                            }
                            this->WHITE_PLAYER->white_knight[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'n';
                        }
                    }
                    break;

            //  Rook move
            case 'r'  : for(int i = 0; i < 2; i++)  {
                            if(this->WHITE_PLAYER->white_rook[i].s == this->start)    {
                                if(isupper(finish->annotation)) {
                                    this->BLACK_PLAYER->capture(finish);
                                }
                            this->WHITE_PLAYER->white_rook[i].castling_possible = false;
                            this->WHITE_PLAYER->white_rook[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'r';
                            }
                        }
                        break;

            //  Queen move (including promoted pawn)
            case 'q'   : if(this->WHITE_PLAYER->white_queen.s == this->start)   {
                        if(isupper(finish->annotation)) {
                            this->BLACK_PLAYER->capture(finish);
                            }
                            this->WHITE_PLAYER->white_queen.s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'q';
                        }
                        else    {
                            for(int i = 0; i < 8; i++)  {
                                if(this->WHITE_PLAYER->white_pawn[i].promotion && this->WHITE_PLAYER->white_pawn[i].s == this->start)  {
                                    if(isupper(finish->annotation)) {
                                        this->BLACK_PLAYER->capture(finish);
                                    }
                                    this->WHITE_PLAYER->white_pawn[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                                    this->start->annotation = 'o';
                                    this->finish->annotation = 'q';
                                }
                            }
                        }
                        break;

            //  King move
            case 'k' :  if(white_king_castle_valid())   {
                            this->WHITE_PLAYER->white_king.castling_possible = false;
                            this->WHITE_PLAYER->white_rook[1].castling_possible = false;
                            this->WHITE_PLAYER->white_king.s = &BOARD->b[6][0];
                            this->WHITE_PLAYER->white_rook[1].s = &BOARD->b[5][0];
                            BOARD->b[6][0].annotation = 'k';
                            BOARD->b[5][0].annotation = 'r';
                            BOARD->b[4][0].annotation = 'o';
                            BOARD->b[7][0].annotation = 'o';
                        }
                        else if(white_queen_castle_valid()) {
                            this->WHITE_PLAYER->white_king.castling_possible = false;
                            this->WHITE_PLAYER->white_rook[0].castling_possible = false;
                            this->WHITE_PLAYER->white_king.s = &BOARD->b[2][0];
                            this->WHITE_PLAYER->white_rook[0].s = &BOARD->b[3][0];
                            BOARD->b[2][0].annotation = 'k';
                            BOARD->b[3][0].annotation = 'r';
                            BOARD->b[0][0].annotation = 'o';
                            BOARD->b[4][0].annotation = 'o';
                        }
                        else if(white_king_valid()) {
                            this->WHITE_PLAYER->white_king.castling_possible = false;
                            if(isupper(finish->annotation)) {
                                this->BLACK_PLAYER->capture(finish);
                            }
                            this->WHITE_PLAYER->white_king.s = &BOARD->b[this->finish->x-1][this->finish->y-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'k';
                        }

            }

            }
            //  Black piece moves
             if(this->black_valid()) {
                    switch(this->start->annotation) {
                  case 'P' : for(int i = 0; i < 8; i++)   {
                                if(this->BLACK_PLAYER->black_pawn[i].s == this->start)  {
                                    if(islower(finish->annotation) && finish->annotation != 'o')    {
                                        this->WHITE_PLAYER->capture(finish);
                                    }

                                this->BLACK_PLAYER->black_pawn[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                                this->start->annotation = 'o';
                                this->finish->annotation = 'P';
                                }
                            }
                              break;

                     case 'B': for(int i = 0; i < 2; i++)    {
                                if(this->BLACK_PLAYER->black_bishop[i].s == this->start)    {
                                    if(islower(finish->annotation) && finish->annotation != 'o')    {
                                        this->WHITE_PLAYER->capture(finish);
                                    }
                                    this->BLACK_PLAYER->black_bishop[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                                    this->start->annotation = 'o';
                                    this->finish->annotation = 'B';
                                }
                            }
                            break;

                        case 'N': for(int i = 0; i < 2; i++)    {
                                if(this->BLACK_PLAYER->black_knight[i].s == this->start)    {
                                    if(islower(finish->annotation) && finish->annotation != 'o')    {
                                        this->WHITE_PLAYER->capture(finish);
                                    }
                                    this->BLACK_PLAYER->black_knight[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                                    this->start->annotation = 'o';
                                    this->finish->annotation = 'N';
                                }
                            }
                            break;

                        case 'R' :  for(int i = 0; i < 2; i++)    {
                                    if(this->BLACK_PLAYER->black_rook[i].s == this->start)    {
                                    if(islower(finish->annotation) && finish->annotation != 'o')    {
                                        this->WHITE_PLAYER->capture(finish);
                                    }
                                    this->BLACK_PLAYER->black_rook[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                                    this->start->annotation = 'o';
                                    this->finish->annotation = 'R';
                                }
                            }
                            break;

                        case 'Q' : if(this->BLACK_PLAYER->black_queen.s == this->start)   {
                                if(islower(finish->annotation) && finish->annotation != 'o') {
                            this->WHITE_PLAYER->capture(finish);
                            }
                            this->BLACK_PLAYER->black_queen.s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'Q';
                        }
                        break;

                        case 'K' :  if(black_king_castle_valid())   {
                            this->BLACK_PLAYER->black_king.castling_possible = false;
                            this->BLACK_PLAYER->black_rook[1].castling_possible = false;
                            this->BLACK_PLAYER->black_king.s = &BOARD->b[6][7];
                            this->BLACK_PLAYER->black_rook[1].s = &BOARD->b[5][7];
                            BOARD->b[6][7].annotation = 'K';
                            BOARD->b[5][7].annotation = 'R';
                            BOARD->b[4][7].annotation = 'o';
                            BOARD->b[7][7].annotation = 'o';
                        }
                        else if(black_queen_castle_valid()) {
                            this->BLACK_PLAYER->black_king.castling_possible = false;
                            this->BLACK_PLAYER->black_rook[0].castling_possible = false;
                            this->BLACK_PLAYER->black_king.s = &BOARD->b[2][7];
                            this->BLACK_PLAYER->black_rook[0].s = &BOARD->b[3][7];
                            BOARD->b[2][7].annotation = 'K';
                            BOARD->b[3][7].annotation = 'R';
                            BOARD->b[0][7].annotation = 'o';
                            BOARD->b[4][7].annotation = 'o';
                        }
                        else if(black_king_valid()) {
                            this->BLACK_PLAYER->black_king.castling_possible = false;
                            if(islower(finish->annotation) && finish->annotation != 'o')    {
                                this->WHITE_PLAYER->capture(finish);
                            }
                            this->BLACK_PLAYER->black_king.s = &BOARD->b[this->finish->x-1][this->finish->y-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'K';
                        }
                        }

    }
}

//  Function to check whether white king would be in check after intended move i.e. whether it is illegal
bool movement :: white_illegal_move()   {
    board check_eval_board = *BOARD;
    check_eval_board.b[this->finish->x-1][this->finish->y-1].annotation = check_eval_board.b[this->start->x-1][this->start->y-1].annotation;
    check_eval_board.b[this->start->x-1][this->start->y-1].annotation = 'o';
    if(check_eval_board.white_check())
        return true;
    return false;
}

//  Function to check whether black king would be in check after intended move i.e. whether it is illegal
bool movement :: black_illegal_move()   {
    board check_eval_board = *BOARD;
    check_eval_board.b[this->finish->x-1][this->finish->y-1].annotation = check_eval_board.b[this->start->x-1][this->start->y-1].annotation;
    check_eval_board.b[this->start->x-1][this->start->y-1].annotation = 'o';
    if(check_eval_board.black_check())
        return true;
    return false;
}

//  Function to determine end of the game
bool movement :: game_over()    {
    return (white_stalemate() || black_stalemate());
}

//  Function to determine whether white has no more valid moves
// If not in check and no more valid moves, it is stalemate
//  If in check and no more valid moves, it is checkmate
bool movement :: white_stalemate()  {
    int x, y, bishop_x, bishop_y, rook_x, rook_y, knight_x, knight_y, king_x, king_y;

    board check_eval_board;

    king_x = this->WHITE_PLAYER->white_king.s->x - 1;   //  Position of the king
    king_y = this->WHITE_PLAYER->white_king.s->y - 1;

    //  Checking whether king can move to avoid a check
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            if(i == 0 && j == 0)
                continue;
            if((king_x+i <= 7) && (king_x+i >= 0) && (king_y+j <= 7) && (king_y+j >= 0) && !(islower(BOARD->b[king_x+i][king_y+j].annotation) && BOARD->b[king_x+i][king_y+j].annotation != 'o')) {
                    check_eval_board = *BOARD;
                    check_eval_board.b[king_x+i][king_y+j].annotation = 'k';
                    check_eval_board.b[king_x][king_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;

            }
        }
    }

    //  Checking whether any of the pawn moves avoids a check
    for(int i = 0; i < 8; i++)  {
        if(!this->WHITE_PLAYER->white_pawn[i].is_captured && !this->WHITE_PLAYER->white_pawn[i].promotion)  {
            int pawn_x = this->WHITE_PLAYER->white_pawn[i].s->x - 1;    //  Pawn position
            int pawn_y = this->WHITE_PLAYER->white_pawn[i].s->y - 1;
            if(BOARD->b[pawn_x][pawn_y+1].annotation == 'o')    {
                check_eval_board = *BOARD;
                check_eval_board.b[pawn_x][pawn_y+1].annotation = 'p';
                check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                if(!check_eval_board.white_check())
                    return false;
            }
            if(pawn_y == 1 && BOARD->b[pawn_x][pawn_y+1].annotation == 'o' && BOARD->b[pawn_x][pawn_y+2].annotation == 'o') {
                check_eval_board = *BOARD;
                check_eval_board.b[pawn_x][pawn_y+2].annotation = 'p';
                check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                if(!check_eval_board.white_check())
                    return false;
            }
            if(pawn_y > 0 && pawn_y < 7)    {
                if(isupper(BOARD->b[pawn_x-1][pawn_y+1].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x-1][pawn_y+1].annotation = 'p';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
                if(isupper(BOARD->b[pawn_x+1][pawn_y+1].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x+1][pawn_y+1].annotation = 'p';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
            }
            else if(pawn_x == 0)    {
                 if(isupper(BOARD->b[pawn_x+1][pawn_y+1].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x+1][pawn_y+1].annotation = 'p';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
            }
            else if(pawn_x == 7)    {
                 if(isupper(BOARD->b[pawn_x-1][pawn_y+1].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x-1][pawn_y+1].annotation = 'p';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
            }
        }
    }

    //  Checking whether any of the bishop, queen or promoted pawn(queen) moves avoid a check
    for(int i = 0; i < 11; i++)  {
            if(i < 2)   {
            if(this->WHITE_PLAYER->white_bishop[i].is_captured)
                continue;
             bishop_x = this->WHITE_PLAYER->white_bishop[i].s->x - 1;
             bishop_y = this->WHITE_PLAYER->white_bishop[i].s->y - 1;
            }
            if(i == 2)  {
                if(this->WHITE_PLAYER->white_queen.is_captured)
                    break;
                bishop_x = this->WHITE_PLAYER->white_queen.s->x - 1;
                bishop_y = this->WHITE_PLAYER->white_queen.s->y - 1;
            }
            if(i > 2 && i < 11) {
                if(this->WHITE_PLAYER->white_pawn[i-3].promotion && !this->WHITE_PLAYER->white_pawn[i-3].is_captured)   {
                    bishop_x = this->WHITE_PLAYER->white_pawn[i-3].s->x - 1;
                    bishop_y = this->WHITE_PLAYER->white_pawn[i-3].s->y - 1;
                }
                else    {
                    continue;
                }
            }

            x = bishop_x + 1;
            y = bishop_y + 1;
            while(x <= 7 && y <=7)  {
                if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'b';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                        if(isupper(BOARD->b[x][y].annotation))
                            break;
                }
                if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                    break;
                x++;
                y++;
            }

            x = bishop_x - 1;
            y = bishop_y + 1;
            while(x >= 0 && y <= 7)  {
                if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'b';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                    if(isupper(BOARD->b[x][y].annotation))
                        break;
                }
                if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                    break;

                x--;
                y++;
            }

            x = bishop_x - 1;
            y = bishop_y - 1;
            while(x >= 0 && y >= 0)  {
                if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'b';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                    if(isupper(BOARD->b[x][y].annotation))
                        break;
                }
                if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                    break;
                x--;
                y--;
            }

            x = bishop_x + 1;
            y = bishop_y - 1;
            while(x <= 7 && y >= 0)  {
                if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'b';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                    if(isupper(BOARD->b[x][y].annotation))
                        break;
                }
                if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                    break;
                x++;
                y--;
            }
    }

    //  Checking whether any of rook, queen or promoted pawn(queen) moves avoid a check
            for(int i = 0; i < 11; i++)  {
                if(i < 2)   {
                    if(this->WHITE_PLAYER->white_rook[i].is_captured)
                        continue;
                    rook_x = this->WHITE_PLAYER->white_rook[i].s->x - 1;
                    rook_y = this->WHITE_PLAYER->white_rook[i].s->y - 1;
                }
                if(i == 2)  {
                    if(this->WHITE_PLAYER->white_queen.is_captured)
                        break;
                    rook_x = this->WHITE_PLAYER->white_queen.s->x - 1;
                    rook_y = this->WHITE_PLAYER->white_queen.s->y - 1;
                }
                if(i > 2 && i < 11) {
                    if(this->WHITE_PLAYER->white_pawn[i-3].promotion && !this->WHITE_PLAYER->white_pawn[i-3].is_captured)   {
                        rook_x = this->WHITE_PLAYER->white_pawn[i-3].s->x - 1;
                        rook_y = this->WHITE_PLAYER->white_pawn[i-3].s->y - 1;
                    }
                    else    {
                        continue;
                    }
                }

                x = rook_x - 1;
                y = rook_y;
                while(x >= 0)   {
                    if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'r';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.white_check())
                            return false;
                        if(isupper(BOARD->b[x][y].annotation))
                            break;
                    }
                    if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                        break;
                  x--;
                }
                x = rook_x + 1;
                y = rook_y;
                while(x <= 7)   {
                    if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'r';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.white_check())
                            return false;
                        if(isupper(BOARD->b[x][y].annotation))
                            break;
                    }
                    if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                        break;
                    x++;
                }

                x = rook_x;
                y = rook_y - 1;
                while(y >= 0)   {
                    if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'r';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.white_check())
                            return false;
                        if(isupper(BOARD->b[x][y].annotation))
                            break;
                    }
                    if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                        break;
                    y--;
                }

                x = rook_x;
                y = rook_y + 1;
                while(y <= 7)   {
                    if(BOARD->b[x][y].annotation == 'o' || isupper(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'r';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.white_check())
                            return false;
                        if(isupper(BOARD->b[x][y].annotation))
                            break;
                    }
                    if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                        break;
                    y++;
                }

                }

        //  Checking whether any of the knight moves avoid a check
        for(int i = 0; i < 2; i++)  {
            if(!this->WHITE_PLAYER->white_knight[i].is_captured)    {
                knight_x = this->WHITE_PLAYER->white_knight[i].s->x - 1;
                knight_y = this->WHITE_PLAYER->white_knight[i].s->y - 1;

                if((knight_x+2 <= 7) && (knight_y+1 <= 7) && !(islower(BOARD->b[knight_x+2][knight_y+1].annotation) && BOARD->b[knight_x+2][knight_y+1].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+2][knight_y+1].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }

                if((knight_x+2 <= 7) && (knight_y-1 >= 0) && !(islower(BOARD->b[knight_x+2][knight_y-1].annotation) && BOARD->b[knight_x+2][knight_y-1].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+2][knight_y-1].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }

                if((knight_x-2 >= 0) && (knight_y+1 <= 7) && !(islower(BOARD->b[knight_x-2][knight_y+1].annotation) && BOARD->b[knight_x-2][knight_y+1].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-2][knight_y+1].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }

                if((knight_x-2 >= 0) && (knight_y-1 >= 0) && !(islower(BOARD->b[knight_x-2][knight_y-1].annotation) && BOARD->b[knight_x-2][knight_y-1].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-2][knight_y-1].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }

                if((knight_x+1 <= 7) && (knight_y+2 <= 7) && !(islower(BOARD->b[knight_x+1][knight_y+2].annotation) && BOARD->b[knight_x+1][knight_y+2].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+1][knight_y+2].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
                if((knight_x+1 <= 7) && (knight_y-2 >= 0) && !(islower(BOARD->b[knight_x+1][knight_y-2].annotation) && BOARD->b[knight_x+1][knight_y-2].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+1][knight_y-2].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
                if((knight_x-1 >= 0) && (knight_y+2 <= 7) && !(islower(BOARD->b[knight_x-1][knight_y+2].annotation) && BOARD->b[knight_x-1][knight_y+2].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-1][knight_y+2].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
                if((knight_x-1 >= 0) && (knight_y-2 >= 0) && !(islower(BOARD->b[knight_x-1][knight_y-2].annotation) && BOARD->b[knight_x-1][knight_y-2].annotation != 'o'))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-1][knight_y-2].annotation = 'n';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.white_check())
                        return false;
                }
            }
        }
        return true;
}

//  Function to determine whether black has no more valid moves
// If not in check and no more valid moves, it is stalemate
//  If in check and no more valid moves, it is checkmate
bool movement :: black_stalemate()  {
    int x, y, bishop_x, bishop_y, rook_x, rook_y, knight_x, knight_y, king_x, king_y;
    board check_eval_board;

    king_x = this->BLACK_PLAYER->black_king.s->x - 1;       //  Determining position of the king
    king_y = this->BLACK_PLAYER->black_king.s->y - 1;

    //  Determining whether any of the king moves avoid a check
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            if(i == 0 && j == 0)
                continue;
            if((king_x+i <= 7) && (king_x+i >= 0) && (king_y+j <= 7) && (king_y+j >= 0) && !(isupper(BOARD->b[king_x+i][king_y+j].annotation))) {
                    check_eval_board = *BOARD;
                    check_eval_board.b[king_x+i][king_y+j].annotation = 'K';
                    check_eval_board.b[king_x][king_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }

            }
        }
    }

    //  Checking whether any of the pawn moves avoid a check
    for(int i = 0; i < 8; i++)  {
        if(!this->BLACK_PLAYER->black_pawn[i].is_captured && !this->BLACK_PLAYER->black_pawn[i].promotion)  {
            int pawn_x = this->BLACK_PLAYER->black_pawn[i].s->x - 1;
            int pawn_y = this->BLACK_PLAYER->black_pawn[i].s->y - 1;
            if(BOARD->b[pawn_x][pawn_y-1].annotation == 'o')    {
                check_eval_board = *BOARD;
                check_eval_board.b[pawn_x][pawn_y-1].annotation = 'P';
                check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                if(!check_eval_board.black_check()) {
                    return false;
                }
            }
            if(pawn_y == 6 && BOARD->b[pawn_x][pawn_y-1].annotation == 'o' && BOARD->b[pawn_x][pawn_y-2].annotation == 'o') {
                check_eval_board = *BOARD;
                check_eval_board.b[pawn_x][pawn_y-2].annotation = 'P';
                check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                if(!check_eval_board.black_check()) {
                    return false;
                }
            }
            if(pawn_y > 0 && pawn_y < 7)    {
                if(islower(BOARD->b[pawn_x-1][pawn_y-1].annotation) && BOARD->b[pawn_x-1][pawn_y-1].annotation != 'o')    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x-1][pawn_y-1].annotation = 'P';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }
                if(islower(BOARD->b[pawn_x+1][pawn_y-1].annotation) && BOARD->b[pawn_x+1][pawn_y-1].annotation != 'o')    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x+1][pawn_y-1].annotation = 'P';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }
            }
            else if(pawn_x == 0)    {
                 if(islower(BOARD->b[pawn_x+1][pawn_y-1].annotation) && BOARD->b[pawn_x+1][pawn_y-1].annotation != 'o')    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x+1][pawn_y-1].annotation = 'P';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.black_check()){
                        return false;
                    }
                }
            }
            else if(pawn_x == 7)    {
                 if(islower(BOARD->b[pawn_x-1][pawn_y-1].annotation) && BOARD->b[pawn_x-1][pawn_y-1].annotation != 'o')    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[pawn_x-1][pawn_y-1].annotation = 'P';
                    check_eval_board.b[pawn_x][pawn_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }
            }
        }
    }

    //  Checking whether any of bishop or queen moves avoid a check
    for(int i = 0; i < 11; i++)  {
            if(i < 2)   {
            if(this->BLACK_PLAYER->black_bishop[i].is_captured)
                continue;
             bishop_x = this->BLACK_PLAYER->black_bishop[i].s->x - 1;
             bishop_y = this->BLACK_PLAYER->black_bishop[i].s->y - 1;
            }
            if(i == 2)  {
                if(this->BLACK_PLAYER->black_queen.is_captured)
                    break;
                bishop_x = this->BLACK_PLAYER->black_queen.s->x - 1;
                bishop_y = this->BLACK_PLAYER->black_queen.s->y - 1;
            }
            if(i > 2 && i < 11) {
                if(this->BLACK_PLAYER->black_pawn[i-3].promotion && !this->BLACK_PLAYER->black_pawn[i-3].is_captured)   {
                    bishop_x = this->BLACK_PLAYER->black_pawn[i-3].s->x - 1;
                    bishop_y = this->BLACK_PLAYER->black_pawn[i-3].s->y - 1;
                }
                else{
                    continue;
                }
            }

            x = bishop_x + 1;
            y = bishop_y + 1;
            while(x <= 7 && y <=7)  {
                if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'B';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                        if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                            break;
                }
                if(isupper(BOARD->b[x][y].annotation))
                    break;
                x++;
                y++;
            }

            x = bishop_x - 1;
            y = bishop_y + 1;
            while(x >= 0 && y <= 7)  {
                if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'B';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.black_check())
                        return false;
                    if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                        break;
                }
                if(isupper(BOARD->b[x][y].annotation))
                    break;

                x--;
                y++;
            }

            x = bishop_x - 1;
            y = bishop_y - 1;
            while(x >= 0 && y >= 0)  {
                if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'B';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.black_check())
                        return false;
                    if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                        break;
                }
                if(isupper(BOARD->b[x][y].annotation))
                    break;
                x--;
                y--;
            }

            x = bishop_x + 1;
            y = bishop_y - 1;
            while(x <= 7 && y >= 0)  {
                if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                    check_eval_board = *BOARD;
                    check_eval_board.b[x][y].annotation = 'B';
                    check_eval_board.b[bishop_x][bishop_y].annotation = 'o';
                    if(!check_eval_board.black_check())
                        return false;
                    if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                        break;
                }
                if(isupper(BOARD->b[x][y].annotation))
                    break;
                x++;
                y--;
            }
    }

        //  Checking whether any of rook or queen moves avoid a check
            for(int i = 0; i < 11; i++)  {
                if(i < 2)   {
                    if(this->BLACK_PLAYER->black_rook[i].is_captured)
                        continue;
                    rook_x = this->BLACK_PLAYER->black_rook[i].s->x - 1;
                    rook_y = this->BLACK_PLAYER->black_rook[i].s->y - 1;
                }
                if(i == 2)  {
                    if(this->BLACK_PLAYER->black_queen.is_captured)
                        break;
                    rook_x = this->BLACK_PLAYER->black_queen.s->x - 1;
                    rook_y = this->BLACK_PLAYER->black_queen.s->y - 1;
                }
                if(i > 2 && i < 11) {
                    if(this->BLACK_PLAYER->black_pawn[i-3].promotion && !this->BLACK_PLAYER->black_pawn[i-3].is_captured)   {
                        rook_x = this->BLACK_PLAYER->black_pawn[i-3].s->x - 1;
                        rook_y = this->BLACK_PLAYER->black_pawn[i-3].s->y - 1;
                    }
                    else    {
                        continue;
                    }
                }

                x = rook_x - 1;
                y = rook_y;
                while(x >= 0)   {
                    if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'R';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.black_check())
                            return false;
                        if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                            break;
                    }
                    if(isupper(BOARD->b[x][y].annotation))
                        break;
                  x--;
                }
                x = rook_x + 1;
                y = rook_y;
                while(x <= 7)   {
                    if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'R';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.black_check())
                            return false;
                        if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                            break;
                    }
                    if(isupper(BOARD->b[x][y].annotation))
                        break;
                    x++;
                }

                x = rook_x;
                y = rook_y - 1;
                while(y >= 0)   {
                    if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'R';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.black_check())
                            return false;
                        if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                            break;
                    }
                    if(isupper(BOARD->b[x][y].annotation))
                        break;
                    y--;
                }

                x = rook_x;
                y = rook_y + 1;
                while(y <= 7)   {
                    if(BOARD->b[x][y].annotation == 'o' || islower(BOARD->b[x][y].annotation))    {
                        check_eval_board = *BOARD;
                        check_eval_board.b[x][y].annotation = 'R';
                        check_eval_board.b[rook_x][rook_y].annotation = 'o';
                        if(!check_eval_board.black_check())
                            return false;
                        if(islower(BOARD->b[x][y].annotation) && BOARD->b[x][y].annotation != 'o')
                            break;
                    }
                    if(isupper(BOARD->b[x][y].annotation))
                        break;
                    y++;
                }

                }

        //  Checking whether any of the knight moves avoid a check
        for(int i = 0; i < 2; i++)  {
            if(!this->BLACK_PLAYER->black_knight[i].is_captured)    {
                knight_x = this->BLACK_PLAYER->black_knight[i].s->x - 1;
                knight_y = this->BLACK_PLAYER->black_knight[i].s->y - 1;

                if((knight_x+2 <= 7) && (knight_y+1 <= 7) && !(isupper(BOARD->b[knight_x+2][knight_y+1].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+2][knight_y+1].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }

                if((knight_x+2 <= 7) && (knight_y-1 >= 0) && !(isupper(BOARD->b[knight_x+2][knight_y-1].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+2][knight_y-1].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }

                if((knight_x-2 >= 0) && (knight_y+1 <= 7) && !(isupper(BOARD->b[knight_x-2][knight_y+1].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-2][knight_y+1].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }

                if((knight_x-2 >= 0) && (knight_y-1 >= 0) && !(isupper(BOARD->b[knight_x-2][knight_y-1].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-2][knight_y-1].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }

                if((knight_x+1 <= 7) && (knight_y+2 <= 7) && !(isupper(BOARD->b[knight_x+1][knight_y+2].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+1][knight_y+2].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }
                if((knight_x+1 <= 7) && (knight_y-2 >= 0) && !(isupper(BOARD->b[knight_x+1][knight_y-2].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x+1][knight_y-2].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }
                if((knight_x-1 >= 0) && (knight_y+2 <= 7) && !(isupper(BOARD->b[knight_x-1][knight_y+2].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-1][knight_y+2].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }
                if((knight_x-1 >= 0) && (knight_y-2 >= 0) && !(isupper(BOARD->b[knight_x-1][knight_y-2].annotation)))  {
                   check_eval_board = *BOARD;
                    check_eval_board.b[knight_x-1][knight_y-2].annotation = 'N';
                    check_eval_board.b[knight_x][knight_y].annotation = 'o';
                    if(!check_eval_board.black_check()) {
                        return false;
                    }
                }
            }
        }
        return true;
}
