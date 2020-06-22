/*

#include <iostream>

#include <iomanip>
#include <string>
#include "chess.h"
using namespace std;

/*
spot :: spot(int x, int y)   {
    this->x = x;
    this->y = y;
    annotation = 'o';
}

spot :: spot()  {
    annotation = 'o';
}
*/
/*
piece :: piece()   {
    is_captured = false;
}
*/
/*
rook :: rook()  {
    castling_possible = true;
}
*/
/*
piece :: piece(int x, int y)  {
    is_captured = false;
    s = new spot(x, y);
}
*/


/*
pawn :: pawn(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
    this->promotion = false;
}

bishop :: bishop(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
}

knight :: knight(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
}

rook :: rook(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
    this->castling_possible = true;
}

queen :: queen(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
}
king :: king(int a, int b)  {
    this->is_captured = false;
    check = false;
    s = new spot(a, b);
    this->castling_possible = true;
}

pawn :: pawn()  {
    this->promotion = false;
}

king :: king()  {
    this->check = false;
    this->castling_possible = true;
}


pawn :: pawn(int x, int y, spot *a)    {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
    this->promotion = false;
}

bishop :: bishop(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
}

knight :: knight(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
}

rook :: rook(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
    this->castling_possible = true;
}

queen :: queen(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
}

king :: king(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
    check = false;
    this->castling_possible = true;
}
*/
/*
void piece :: captured()    {
    this->is_captured = true;
    this->s = NULL;
}
*/


/*
board :: board  ()  {
    for(int i = 0; i < 8; i++)  {
        for(int j= 0; j < 8; j++)   {
            b[i][j].x = i+1;
            b[i][j].y = j+1;
        }
    }
}
*/
/*
white_player :: white_player(board *brd)    {
    BOARD = brd;
    for(int i = 0; i < 8; i++)  {
        white_pawn[i].s = &brd->b[i][1];
        white_pawn[i].s->annotation = 'p';
    }
    white_bishop[0].s = &brd->b[2][0];
    white_bishop[0].s->annotation = 'b';
    white_bishop[1].s = &brd->b[5][0];
    white_bishop[1].s->annotation = 'b';
    white_knight[0].s = &brd->b[1][0];
    white_knight[0].s->annotation = 'n';
    white_knight[1].s = &brd->b[6][0];
    white_knight[1].s->annotation = 'n';
    white_rook[0].s = &brd->b[0][0];
    white_rook[0].s->annotation = 'r';
    white_rook[1].s = &brd->b[7][0];
    white_rook[1].s->annotation = 'r';
    white_queen.s = &brd->b[3][0];
    white_queen.s->annotation = 'q';
    white_king.s = &brd->b[4][0];
    white_king.s->annotation = 'k';

}


black_player :: black_player(board *brd)    {
    BOARD = brd;
    for(int i = 0; i < 8; i++)  {
        black_pawn[i].s = &brd->b[i][6];
        black_pawn[i].s->annotation = 'P';
    }
    black_bishop[0].s = &brd->b[2][7];
    black_bishop[0].s->annotation = 'B';
    black_bishop[1].s = &brd->b[5][7];
    black_bishop[1].s->annotation = 'B';
    black_knight[0].s = &brd->b[1][7];
    black_knight[0].s->annotation = 'N';
    black_knight[1].s = &brd->b[6][7];
    black_knight[1].s->annotation = 'N';
    black_rook[0].s = &brd->b[0][7];
    black_rook[0].s->annotation = 'R';
    black_rook[1].s = &brd->b[7][7];
    black_rook[1].s->annotation = 'R';
    black_queen.s = &brd->b[3][7];
    black_queen.s->annotation = 'Q';
    black_king.s = &brd->b[4][7];
    black_king.s->annotation = 'K';
}
*/
/*
void board :: display() {
    cout << "  A     B     C      D    E     F      G      H" << endl;
    for(int i = 7; i >=0; i--)  {
        if(i%2 == 0)    {
            for(int j = 0; j < 3; j++)  {
            for(int w = 0; w < 4; w++)  {
            for(int k = 0; k < 6; k++)  {
                    if(j == 1 && k == 3)    {
                            if(this->b[2*w][i].annotation != 'o')
                                cout << this->b[2*w][i].annotation;
                            else cout << (char) BLACK_SQUARE;
                    }
                    else
                            cout << (char)BLACK_SQUARE;
            }
            for(int k = 0; k < 6; k++)  {
                    if(j == 1 && k == 3)    {
                        if(this->b[2*w+1][i].annotation != 'o')
                            cout << this->b[2*w+1][i].annotation;
                        else
                            cout << (char)WHITE_SQUARE;
                    }
                    else
                        cout << (char)WHITE_SQUARE;
            }
            }
                if(j == 1)
                    cout << "  " << i+1;
                cout << endl;
        }

    }
    else {
        for(int j = 0; j < 3; j++)  {
            for(int w = 0; w < 4; w++)  {
            for(int k = 0; k < 6; k++)  {
                    if(j == 1 && k == 3)    {
                        if(this->b[2*w][i].annotation != 'o')
                            cout << this->b[2*w][i].annotation;
                        else
                            cout << (char)WHITE_SQUARE;
                    }
                    else
                        cout << (char)WHITE_SQUARE;
            }

            for(int k = 0; k < 6; k++)  {
                if(j == 1 && k == 3)    {
                    if(this->b[2*w+1][i].annotation != 'o')
                        cout << this->b[2*w+1][i].annotation;
                    else
                        cout << (char)BLACK_SQUARE;
                }
                else
                    cout << (char)BLACK_SQUARE;
            }
                }
                if(j == 1)
                cout << "  " << i+1;
                cout << endl;
        }

    }

    }
    cout << endl;
}
*/
/*

void white_player :: capture (spot *capture_spot)  {
    for(int i = 0; i < 8; i++)  {
        if(this->white_pawn[i].s == capture_spot)    {
            this->white_pawn[i].captured();
            return;
        }
    }
    for(int i = 0; i < 2; i++)  {
        if(this->white_knight[i].s == capture_spot)  {
            this->white_knight[i].captured();
            return;
        }
    }
    for(int i = 0; i < 2; i++)  {
        if(this->white_bishop[i].s == capture_spot)  {
            this->white_bishop[i].captured();
            return;
        }
    }

    for(int i = 0; i < 2; i++)  {
        if(this->white_rook[i].s == capture_spot)  {
            this->white_rook[i].captured();
            return;
        }
    }
    if(this->white_queen.s == capture_spot)  {
        this->white_queen.captured();
    }
}

void black_player :: capture (spot *capture_spot)  {
    for(int i = 0; i < 8; i++)  {
        if(this->black_pawn[i].s == capture_spot)    {
            this->black_pawn[i].captured();
            return;
        }
    }
    for(int i = 0; i < 2; i++)  {
        if(this->black_knight[i].s == capture_spot)  {
            this->black_knight[i].captured();
            return;
        }
    }
    for(int i = 0; i < 2; i++)  {
        if(this->black_bishop[i].s == capture_spot)  {
            this->black_bishop[i].captured();
            return;
        }
    }

    for(int i = 0; i < 2; i++)  {
        if(this->black_rook[i].s == capture_spot)  {
            this->black_rook[i].captured();
            return;
        }
    }
    if(this->black_queen.s == capture_spot)  {
        this->black_queen.captured();
    }
}
*/


/*
movement :: movement(board *brd, white_player *w, black_player *b)    {
    BOARD = brd;
    WHITE_PLAYER = w;
    BLACK_PLAYER = b;
    draw = false;
}

bool movement :: out_of_bounds(int x1, int y1, int x2, int y2)  {
    if((x1 > 8) || (x1 < 1) || (x2 > 8) || (x2 < 1) || (y1 > 8) || (y1 < 1) || (y2 > 8) || (y2 < 1))
        return true;
    else
        return false;
}

bool valid_input(string s)    {
    if(s.length() != 2)
        return false;
    if  (!(s[1] >= '1' && s[1] <= '8'))
        return false;
    if  (!(tolower(s[0]) >= 'a' && tolower(s[0]) <= 'h'))
        return false;
    return true;
}

string lower(string s)  {
    int n = s.length();
    for(int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
    return s;
}

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


bool movement :: draw_offer_accept()    {
    return this->draw;
}

void movement :: get_move()   {
    do{
        cout << "Enter starting position: ";
        cin >> this->s1;
        if(lower(s1) == "draw") {
            draw_offer();
            if(draw_offer_accept())
                return;
        }
    }while(!valid_input(s1));
    this->x1 = (int)(tolower(s1[0]) - 'a' + 1);
    this->y1 = (int)(s1[1] - '0');
    do{
        cout << "Enter finishing position: ";
        cin >> this->s2;
    }while(!valid_input(s2));
    this->x2 = (int)(tolower(s2[0]) - 'a' + 1);
    this->y2 = (int)(s2[1] - '0');

    this->start = &BOARD->b[x1-1][y1-1];
    this->finish = &BOARD->b[x2-1][y2-1];
}

string movement :: return_start()   {
    this->s1[0] = tolower(this->s1[0]);
    return this->s1;
}

string movement :: return_finish()  {
    this->s2[0] = tolower(this->s2[0]);
    return this->s2;
}


bool movement :: white_valid()  {
    if(isupper(start->annotation) || (start->annotation == 'o'))  {
        return false;
    }
    switch(this->start->annotation) {
        case 'p' :      return (white_pawn_valid() && !white_illegal_move());
                        break;
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

        default : return false;
    }

}

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


bool movement :: white_pawn_valid()   {
if(finish->annotation == 'K')
    return false;
if((start->x == finish->x) && (finish->annotation == 'o')  && (finish->y == start->y + 1))
                        return true;
                        else if(((start->x == finish->x) && finish->annotation == 'o') && (finish->y == start->y + 2) && (start->y == 2) && BOARD->b[start->x-1][start->y].annotation == 'o')
                            return true;
                        else if(start->x == (finish->x - 1) && (finish->y = start->y + 1) && (isupper(finish->annotation)))
                            return true;
                         else if(start->x == (finish->x + 1) && (finish->y = start->y + 1) && (isupper(finish->annotation)))
                            return true;
                            else
                                return false;
}

bool movement :: white_bishop_valid()   {
    if(finish->annotation == 'K')
        return false;
    if((islower(finish->annotation)) && finish->annotation != 'o')
        return false;

    if  (!(((this->start->x - this->finish->x) == (this->start->y - this->finish->y)) || ((this->start->x - this->finish->x) == (this->finish->y - this->start->y))))
        return false;
    if(start->x < finish->x && start->y < finish->y)    {
                int j = start->y + 1;
            for(int i = start->x + 1; i < finish->x; i++, j++)   {
                if(this->BOARD->b[i-1][j-1].annotation != 'o')
                    return false;
            }
        return true;
    }
    else if(start->x < finish->x && finish->y < start->y)    {
        int j = start->y - 1;
        for(int i = start->x + 1; i < finish->x; i++, j--)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && start->y < finish->y)   {
        int j = start->y + 1;
        for(int i = start->x - 1; i > finish->x; i--, j++)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && finish->y < start->y)   {
        int j = start->y - 1;
        for(int i = start->x - 1; i > finish->x; i--, j--) {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')
                return false;
        }
        return true;
    }
    else return false;
}

bool movement :: black_bishop_valid()   {
    if(finish->annotation == 'k')
        return false;
    if((isupper(finish->annotation)))
        return false;

    if  (!(((this->start->x - this->finish->x) == (this->start->y - this->finish->y)) || ((this->start->x - this->finish->x) == (this->finish->y - this->start->y))))
        return false;

    if(start->x < finish->x && start->y < finish->y)    {
                int j = start->y + 1;
            for(int i = start->x + 1; i < finish->x; i++, j++)   {
                if(this->BOARD->b[i-1][j-1].annotation != 'o')
                    return false;
            }
        return true;
    }
    else if(start->x < finish->x && finish->y < start->y)    {
        int j = start->y - 1;
        for(int i = start->x + 1; i < finish->x; i++, j--)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && start->y < finish->y)   {
        int j = start->y + 1;
        for(int i = start->x - 1; i > finish->x; i--, j++)  {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')
                return false;
        }
        return true;
    }
    else if(start->x > finish->x && finish->y < start->y)   {
        int j = start->y - 1;
        for(int i = start->x - 1; i > finish->x; i--, j--) {
            if(this->BOARD->b[i-1][j-1].annotation != 'o')
                return false;
        }
        return true;
    }
    else return false;
}


bool movement :: white_knight_valid()   {
    if(finish->annotation == 'K')
        return false;
    if(islower(finish->annotation) && finish->annotation != 'o')
        return false;
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

bool movement :: black_knight_valid()   {
    if(finish->annotation == 'k')
        return false;
    if(isupper(finish->annotation))
        return false;
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

bool movement :: white_rook_valid() {
    if(finish->annotation == 'K')
        return false;
    if(islower(finish->annotation) && finish->annotation != 'o')
        return false;
    if(start->x == finish->x)   {
            if(finish->y > start->y)    {
                for(int i = start->y + 1; i < finish->y; i++)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o')
                        return false;
                }
                return true;
            }
            else if(finish->y < start->y)   {
                for(int i = start->y - 1; i > finish->y; i--)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o')
                        return false;
                }
                return true;
            }
    }
    else if(start->y == finish->y)  {
        if(start->x < finish->x)    {
            for(int i = start->x + 1; i < finish->x; i++)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o')
                    return false;
            }
            return true;
        }
        else if(start->x > finish->x)   {
            for(int i = start->x - 1; i > finish->x; i--)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o')
                    return false;
            }
            return true;
        }
    }
        return false;
}

bool movement :: black_rook_valid() {
    if(finish->annotation == 'k')
        return false;
    if(isupper(finish->annotation))
        return false;
    if(start->x == finish->x)   {
            if(finish->y > start->y)    {
                for(int i = start->y + 1; i < finish->y; i++)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o')
                        return false;
                }
                return true;
            }
            else if(finish->y < start->y)   {
                for(int i = start->y - 1; i > finish->y; i--)   {
                    if(this->BOARD->b[start->x - 1][i-1].annotation != 'o')
                        return false;
                }
                return true;
            }
    }
    else if(start->y == finish->y)  {
        if(start->x < finish->x)    {
            for(int i = start->x + 1; i < finish->x; i++)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o')
                    return false;
            }
            return true;
        }
        else if(start->x > finish->x)   {
            for(int i = start->x - 1; i > finish->x; i--)   {
                if(this->BOARD->b[i-1][start->y - 1].annotation != 'o')
                    return false;
            }
            return true;
        }
    }
        return false;
}


bool movement :: white_queen_valid()    {
    return (white_bishop_valid() || white_rook_valid());
}

bool movement :: black_queen_valid()    {
    return (black_bishop_valid() || black_rook_valid());
}


bool movement :: black_pawn_valid() {
    if(finish->annotation == 'k')
        return false;
    if((start->x == finish->x) && (finish->annotation == 'o') && (finish->y == start->y - 1))
                        return true;
                        else if((start->x == finish->x) && (finish->annotation == 'o') && (finish->y == start->y - 2) && (start->y == 7) && BOARD->b[start->x-1][start->y-2].annotation == 'o')
                            return true;
                        else if(start->x == (finish->x - 1) && (finish->y = start->y - 1) && (islower(finish->annotation)) && (finish->annotation != 'o'))
                            return true;
                         else if(start->x == (finish->x + 1) && (finish->y = start->y - 1) && (islower(finish->annotation)) && (finish->annotation != 'o'))
                            return true;
                            else
                                return false;

}

bool movement :: white_king_castle_valid()  {
    if(BOARD->white_check())
        return false;
    if((this->start == this->WHITE_PLAYER->white_king.s) && (this->finish == &BOARD->b[6][0]) && this->WHITE_PLAYER->white_king.castling_possible && this->WHITE_PLAYER->white_rook[1].castling_possible)  {
       if(BOARD->b[5][0].annotation == 'o' && BOARD->b[6][0].annotation == 'o') {
        board check_eval_board;
        check_eval_board = *BOARD;
        check_eval_board.b[5][0].annotation = 'k';
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

bool movement :: white_king_valid() {
    if(islower(finish->annotation) && finish->annotation != 'o')
        return false;
    if(this->start == this->WHITE_PLAYER->white_king.s) {
        if((finish->y - start->y == 1 || finish->y - start->y == 0 || finish->y - start->y == -1)
           && (finish->x - start->x == 1 || finish->x - start->x == 0 || finish->x - start->x == -1))
            return true;
    }
    return false;
}

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

bool movement :: black_queen_castle_valid() {
    if(BOARD->black_check())
        return false;
    if((this->start == this->BLACK_PLAYER->black_king.s) && (this->finish == &BOARD->b[2][7]) && this->BLACK_PLAYER->black_king.castling_possible && this->BLACK_PLAYER->black_rook[0].castling_possible)   {
        if(BOARD->b[3][7].annotation == 'o' && BOARD->b[2][7].annotation == 'o' && BOARD->b[1][7].annotation == 'o')    {
            board check_eval_board;
            check_eval_board = *BOARD;
            check_eval_board.b[3][7].annotation = 'K';
            check_eval_board.b[4][7].annotation = 'o';
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


void movement :: move_piece()   {
    if(this->white_valid()) {
        switch(this->start->annotation) {
        case 'p': for(int i = 0; i < 8; i++)    {
                        if(this->WHITE_PLAYER->white_pawn[i].s == this->start)  {
                            if(finish->y == 8 && !(this->WHITE_PLAYER->white_pawn[i].promotion))  {
                                this->WHITE_PLAYER->white_pawn[i].promotion = true;
                                if(isupper(finish->annotation)) {
                                    this->BLACK_PLAYER->capture(finish);
                                }
                                this->WHITE_PLAYER->white_pawn[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                                this->start->annotation = 'o';
                                this->finish->annotation = 'q';
                            }
                            else    {
                            if(isupper(finish->annotation)) {

                                this->BLACK_PLAYER->capture(finish);
                            }
                            this->WHITE_PLAYER->white_pawn[i].s = &BOARD->b[(this->finish->x)-1][(this->finish->y)-1];
                            this->start->annotation = 'o';
                            this->finish->annotation = 'p';
                            }
                        }
                    }
                    break;

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
*/
/*
bool board :: white_check() {
    int white_king_x = 0, white_king_y = 0, black_king_x = 0, black_king_y = 0, i, j;
    for(i = 0; i < 8; i++)  {
        for(j = 0; j < 8; j++)  {
            if(this->b[i][j].annotation == 'k') {
                white_king_x = i;
                white_king_y = j;
            }
            if(this->b[i][j].annotation == 'K') {
                black_king_x = i;
                black_king_y = j;
            }

        }
    }
    if((black_king_x - white_king_x == 1 || black_king_x - white_king_x == 0 || black_king_x - white_king_x == -1)
       && (black_king_y - white_king_y == 1 || black_king_y - white_king_y == 0 || black_king_y - white_king_y == -1))
       return true;

    if(white_king_y != 7 || white_king_y != 6) {
        if(white_king_x == 0) {
            if(this->b[1][white_king_y+1].annotation == 'P')
                return true;
        }
            else if(white_king_x == 7)    {
                if(this->b[6][white_king_y+1].annotation == 'P')
                    return true;
            }
                else    {
                    if((this->b[white_king_x-1][white_king_y+1].annotation == 'P') || (this->b[white_king_x+1][white_king_y+1].annotation == 'P'))
                        return true;
                }

    }
    j = white_king_y - 1;
    while(j >= 0)   {
        if(islower(this->b[white_king_x][j].annotation) && this->b[white_king_x][j].annotation != 'o')
            break;
        if(isupper(this->b[white_king_x][j].annotation))  {
            if(this->b[white_king_x][j].annotation == 'N' || this->b[white_king_x][j].annotation == 'P' || this->b[white_king_x][j].annotation == 'B')
                break;
            if(this->b[white_king_x][j].annotation == 'R' || this->b[white_king_x][j].annotation == 'Q')
                return true;
        }
        j--;
    }
    j = white_king_y + 1;
     while(j <= 7)   {
        if(islower(this->b[white_king_x][j].annotation) && this->b[white_king_x][j].annotation != 'o')
            break;
         if(isupper(this->b[white_king_x][j].annotation))  {
            if(this->b[white_king_x][j].annotation == 'N' || this->b[white_king_x][j].annotation == 'P' || this->b[white_king_x][j].annotation == 'B')
                break;
            if(this->b[white_king_x][j].annotation == 'R' || this->b[white_king_x][j].annotation == 'Q')
                return true;
        }
        j++;
    }
    i = white_king_x - 1;
     while(i >= 0)   {
        if(islower(this->b[i][white_king_y].annotation) && this->b[i][white_king_y].annotation != 'o')
            break;
            if(isupper(this->b[i][white_king_y].annotation))  {
            if(this->b[i][white_king_y].annotation == 'N' || this->b[i][white_king_y].annotation == 'P' || this->b[i][white_king_y].annotation == 'B')
                break;
            if(this->b[i][white_king_y].annotation == 'R' || this->b[i][white_king_y].annotation == 'Q')
                return true;
        }

        i--;
    }
    i = white_king_x + 1;
    while(i <= 7)   {
        if(islower(this->b[i][white_king_y].annotation) && this->b[i][white_king_y].annotation != 'o')
            break;
            if(isupper(this->b[i][white_king_y].annotation))  {
            if(this->b[i][white_king_y].annotation == 'N' || this->b[i][white_king_y].annotation == 'P' || this->b[i][white_king_y].annotation == 'B')
                break;
            if(this->b[i][white_king_y].annotation == 'R' || this->b[i][white_king_y].annotation == 'Q')
                return true;
        }
        i++;
    }
    i = white_king_x + 1;
    j = white_king_y + 1;
    while(i <= 7 && j <= 7) {
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')
            break;
        if(isupper(this->b[i][j].annotation))   {
            if(this->b[i][j].annotation == 'N' || this->b[i][j].annotation == 'R' || this->b[i][j].annotation == 'P')
                break;
            if(this->b[i][j].annotation == 'B' || this->b[i][j].annotation == 'Q')
                return true;
        }
        i++;
        j++;
    }
    i = white_king_x - 1;
    j = white_king_y + 1;
    while(i >= 0 && j <= 7) {
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')
            break;
        if(isupper(this->b[i][j].annotation))   {
            if(this->b[i][j].annotation == 'N' || this->b[i][j].annotation == 'R' || this->b[i][j].annotation == 'P')
                break;
            if(this->b[i][j].annotation == 'B' || this->b[i][j].annotation == 'Q')
                return true;
        }
        i--;
        j++;
    }
    i = white_king_x + 1;
    j = white_king_y - 1;
    while(i <= 7 && j >= 0) {
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')
            break;
        if(isupper(this->b[i][j].annotation))   {
            if(this->b[i][j].annotation == 'N' || this->b[i][j].annotation == 'R' || this->b[i][j].annotation == 'P')
                break;
            if(this->b[i][j].annotation == 'B' || this->b[i][j].annotation == 'Q')
                return true;
        }
        i++;
        j--;
    }
    i = white_king_x - 1;
    j = white_king_y - 1;
    while(i >= 0 && j >= 0) {
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')
            break;
        if(isupper(this->b[i][j].annotation))   {
            if(this->b[i][j].annotation == 'N' || this->b[i][j].annotation == 'R' || this->b[i][j].annotation == 'P')
                break;
            if(this->b[i][j].annotation == 'B' || this->b[i][j].annotation == 'Q')
                return true;
        }
        i--;
        j--;
    }
    if(white_king_x > 1 && white_king_x < 6 && white_king_y > 1 && white_king_y < 6) {
        if(this->b[white_king_x-2][white_king_y-1].annotation == 'N' || this->b[white_king_x-2][white_king_y+1].annotation == 'N'
        || this->b[white_king_x+2][white_king_y-1].annotation == 'N' || this->b[white_king_x+2][white_king_y+1].annotation == 'N'
        || this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x-1][white_king_y-2].annotation == 'N'
        || this->b[white_king_x+1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N')
            return true;
    }
        if(white_king_y == 0 && white_king_x > 1 && white_king_x < 6) {
            if(this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y+2].annotation == 'N'
            || (this->b[white_king_x-2][white_king_y+1].annotation == 'N' || this->b[white_king_x+2][white_king_y+1].annotation == 'N'))
                return true;
        }

        if(white_king_y == 0 && white_king_x == 1)  {
            if(this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y + 2].annotation == 'N'
               || this->b[white_king_x+2][white_king_y+1].annotation == 'N')
                return true;
        }
        if(white_king_y == 0 && white_king_x == 6)  {
             if(this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y + 2].annotation == 'N'
               || this->b[white_king_x-2][white_king_y+1].annotation == 'N')
                return true;
        }
        if(white_king_y == 0 && white_king_x == 0)  {
            if(this->b[white_king_x+2][white_king_y+1].annotation == 'N' || this->b[white_king_x+1][white_king_y+2].annotation == 'N')
                return true;
        }
        if(white_king_y == 0 && white_king_x == 7)  {
            if(this->b[white_king_x-2][white_king_y+1].annotation == 'N' || this->b[white_king_x-1][white_king_y+2].annotation == 'N')
                return true;
        }
        if(white_king_y == 1 && white_king_x < 6 && white_king_x > 1) {
            if(this->b[white_king_x-2][white_king_y+1].annotation == 'N' || this->b[white_king_x+2][white_king_y+1].annotation == 'N'
            || this->b[white_king_x-2][white_king_y-1].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'
            || this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y+2].annotation == 'N')
                return true;
        }
        if(white_king_y == 1 && white_king_x == 0)  {
            if(this->b[white_king_x+1][white_king_y+2].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'
               || this->b[white_king_x+2][white_king_y+1].annotation == 'N')
                return true;
        }
        if(white_king_y == 1 && white_king_x == 7)  {
            if(this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x-2][white_king_y-1].annotation == 'N'
               || this->b[white_king_x-2][white_king_y+1].annotation == 'N')
                return true;
        }
        if(white_king_y == 1 && white_king_x == 1)  {
            if(this->b[white_king_x+2][white_king_y+1].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'
            || this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y+2].annotation == 'N')
            return true;
        }
        if(white_king_y == 1 && white_king_x == 6)  {
            if(this->b[white_king_x-2][white_king_y+1].annotation == 'N' || this->b[white_king_x-2][white_king_y-1].annotation == 'N'
            || this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y+2].annotation == 'N')
            return true;
        }

        if(white_king_y == 7 && white_king_x > 1 && white_king_x < 6) {
            if(this->b[white_king_x-1][white_king_y-2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N'
            || (this->b[white_king_x-2][white_king_y-1].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'))
                return true;
        }
        if(white_king_y == 7 && white_king_x == 1)  {
            if(this->b[white_king_x-1][white_king_y-2].annotation == 'N' || this->b[white_king_x+1][white_king_y - 2].annotation == 'N'
               || this->b[white_king_x+2][white_king_y-1].annotation == 'N')
                return true;
        }
        if(white_king_y == 7 && white_king_x == 6)  {
             if(this->b[white_king_x-1][white_king_y-2].annotation == 'N' || this->b[white_king_x+1][white_king_y - 2].annotation == 'N'
               || this->b[white_king_x-2][white_king_y-1].annotation == 'N')
                return true;
        }
        if(white_king_y == 7 && white_king_x == 0)  {
            if(this->b[white_king_x+2][white_king_y-1].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N')
                return true;
        }
        if(white_king_y == 7 && white_king_x == 7)  {
            if(this->b[white_king_x-2][white_king_y-1].annotation == 'N' || this->b[white_king_x-1][white_king_y-2].annotation == 'N')
                return true;
        }
        if(white_king_y == 6 && white_king_x < 6 && white_king_x > 1) {
            if(this->b[white_king_x-2][white_king_y+1].annotation == 'N' || this->b[white_king_x+2][white_king_y+1].annotation == 'N'
            || this->b[white_king_x-2][white_king_y-1].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'
            || this->b[white_king_x-1][white_king_y-2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N')
                return true;
        }
        if(white_king_y == 6 && white_king_x == 0)  {
            if(this->b[white_king_x+1][white_king_y-2].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'
               || this->b[white_king_x+2][white_king_y+1].annotation == 'N')
                return true;
        }
        if(white_king_y == 6 && white_king_x == 7)  {
            if(this->b[white_king_x-1][white_king_y-2].annotation == 'N' || this->b[white_king_x-2][white_king_y-1].annotation == 'N'
               || this->b[white_king_x-2][white_king_y+1].annotation == 'N')
                return true;
        }
        if(white_king_y == 6 && white_king_x == 1)  {
            if(this->b[white_king_x+2][white_king_y+1].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'
            || this->b[white_king_x-1][white_king_y-2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N')
            return true;
        }
        if(white_king_y == 6 && white_king_x == 6)  {
            if(this->b[white_king_x-2][white_king_y+1].annotation == 'N' || this->b[white_king_x-2][white_king_y-1].annotation == 'N'
            || this->b[white_king_x-1][white_king_y-2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N')
            return true;
        }
        if(white_king_x == 0 && white_king_y > 1 && white_king_y < 6) {
            if(this->b[white_king_x+2][white_king_y-1].annotation == 'N' || this->b[white_king_x+2][white_king_y+1].annotation == 'N'
               ||this->b[white_king_x+1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N')
                return true;
        }
        if(white_king_x == 7 && white_king_y > 1 && white_king_y < 6) {
            if(this->b[white_king_x-2][white_king_y-1].annotation == 'N' || this->b[white_king_x-2][white_king_y+1].annotation == 'N'
               ||this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x-1][white_king_y-2].annotation == 'N')
                return true;
        }
        if(white_king_x == 1 && white_king_y > 1 && white_king_y < 6) {
            if(this->b[white_king_x+2][white_king_y+1].annotation == 'N' || this->b[white_king_x+2][white_king_y-1].annotation == 'N'
               || this->b[white_king_x+1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N'
               || this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x-1][white_king_y-2].annotation == 'N')
                return true;
        }
         if(white_king_x == 6 && white_king_y > 1 && white_king_y < 6) {
            if(this->b[white_king_x-2][white_king_y+1].annotation == 'N' || this->b[white_king_x-2][white_king_y-1].annotation == 'N'
               || this->b[white_king_x+1][white_king_y+2].annotation == 'N' || this->b[white_king_x+1][white_king_y-2].annotation == 'N'
               || this->b[white_king_x-1][white_king_y+2].annotation == 'N' || this->b[white_king_x-1][white_king_y-2].annotation == 'N')
                return true;
        }

    return false;
}
*/

/*

bool board :: black_check() {
    int king_x = 0, king_y = 0, opp_king_x = 0, opp_king_y = 0, i, j;
    for(i = 0; i < 8; i++)  {
        for(j = 0; j < 8; j++)  {
            if(this->b[i][j].annotation == 'K') {
                king_x = i;
                king_y = j;
            }
            if(this->b[i][j].annotation == 'k') {
                opp_king_x = i;
                opp_king_y = j;
            }
        }
    }

    if((opp_king_x - king_x == 1 || opp_king_x - king_x == 0 || opp_king_x - king_x == -1) &&
       (opp_king_y - king_y == 1 || opp_king_y - king_y == 0 || opp_king_y - king_y == -1))
       return true;

    if(king_y != 1 || king_y != 0) {
        if(king_x == 0) {
            if(this->b[1][king_y-1].annotation == 'p')
                return true;
        }
            else if(king_x == 7)    {
                if(this->b[6][king_y-1].annotation == 'p')
                    return true;
            }
                else    {
                    if((this->b[king_x-1][king_y-1].annotation == 'p') || (this->b[king_x+1][king_y-1].annotation == 'p'))
                        return true;
                }


    }
    j = king_y - 1;
    while(j >= 0)   {
        if(isupper(this->b[king_x][j].annotation))
            break;
        if(islower(this->b[king_x][j].annotation) && this->b[king_x][j].annotation != 'o')  {
            if(this->b[king_x][j].annotation == 'n' || this->b[king_x][j].annotation == 'p' || this->b[king_x][j].annotation == 'b')
                break;
            if(this->b[king_x][j].annotation == 'r' || this->b[king_x][j].annotation == 'q')
                return true;
        }
        j--;
    }
    j = king_y + 1;
     while(j <= 7)   {
        if(isupper(this->b[king_x][j].annotation))
            break;
         if(islower(this->b[king_x][j].annotation) && this->b[king_x][j].annotation != 'o')  {
            if(this->b[king_x][j].annotation == 'n' || this->b[king_x][j].annotation == 'p' || this->b[king_x][j].annotation == 'b')
                break;
            if(this->b[king_x][j].annotation == 'r' || this->b[king_x][j].annotation == 'q')
                return true;
        }
        j++;
    }
    i = king_x - 1;
     while(i >= 0)   {
        if(isupper(this->b[i][king_y].annotation))
            break;
            if(islower(this->b[i][king_y].annotation) && this->b[i][king_y].annotation != 'o')  {
            if(this->b[i][king_y].annotation == 'n' || this->b[i][king_y].annotation == 'p' || this->b[i][king_y].annotation == 'b')
                break;
            if(this->b[i][king_y].annotation == 'r' || this->b[i][king_y].annotation == 'q')
                return true;
        }

        i--;
    }
    i = king_x + 1;
    while(i <= 7)   {
        if(isupper(this->b[i][king_y].annotation))
            break;
            if(islower(this->b[i][king_y].annotation) && this->b[i][king_y].annotation != 'o')  {
            if(this->b[i][king_y].annotation == 'n' || this->b[i][king_y].annotation == 'p' || this->b[i][king_y].annotation == 'b')
                break;
            if(this->b[i][king_y].annotation == 'r' || this->b[i][king_y].annotation == 'q')
                return true;
        }
        i++;
    }

    i = king_x + 1;
    j = king_y + 1;
    while(i <= 7 && j <= 7) {
        if(isupper(this->b[i][j].annotation))
            break;
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')   {
            if(this->b[i][j].annotation == 'n' || this->b[i][j].annotation == 'r' || this->b[i][j].annotation == 'p')
                break;
            if(this->b[i][j].annotation == 'b' || this->b[i][j].annotation == 'q')
                return true;
        }
        i++;
        j++;
    }

    i = king_x - 1;
    j = king_y + 1;
    while(i >= 0 && j <= 7) {
        if(isupper(this->b[i][j].annotation))
            break;
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')   {
            if(this->b[i][j].annotation == 'n' || this->b[i][j].annotation == 'r' || this->b[i][j].annotation == 'p')
                break;
            if(this->b[i][j].annotation == 'b' || this->b[i][j].annotation == 'q')
                return true;
        }
        i--;
        j++;
    }


    i = king_x + 1;
    j = king_y - 1;
    while(i <= 7 && j >= 0) {
        if(isupper(this->b[i][j].annotation))
            break;
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')   {
            if(this->b[i][j].annotation == 'n' || this->b[i][j].annotation == 'r' || this->b[i][j].annotation == 'p')
                break;
            if(this->b[i][j].annotation == 'b' || this->b[i][j].annotation == 'q')
                return true;
        }
        i++;
        j--;
    }

    i = king_x - 1;
    j = king_y - 1;
    while(i >= 0 && j >= 0) {
        if(isupper(this->b[i][j].annotation))
            break;
        if(islower(this->b[i][j].annotation) && this->b[i][j].annotation != 'o')   {
            if(this->b[i][j].annotation == 'n' || this->b[i][j].annotation == 'r' || this->b[i][j].annotation == 'p')
                break;
            if(this->b[i][j].annotation == 'b' || this->b[i][j].annotation == 'q')
                return true;
        }
        i--;
        j--;
    }


    if(king_x > 1 && king_x < 6 && king_y > 1 && king_y < 6) {
        if(this->b[king_x-2][king_y-1].annotation == 'n' || this->b[king_x-2][king_y+1].annotation == 'n'
        || this->b[king_x+2][king_y-1].annotation == 'n' || this->b[king_x+2][king_y+1].annotation == 'n'
        || this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x-1][king_y-2].annotation == 'n'
        || this->b[king_x+1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n')
            return true;
    }
        if(king_y == 0 && king_x > 1 && king_x < 6) {
            if(this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y+2].annotation == 'n'
            || (this->b[king_x-2][king_y+1].annotation == 'n' || this->b[king_x+2][king_y+1].annotation == 'n'))
                return true;
        }
        if(king_y == 0 && king_x == 1)  {
            if(this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y + 2].annotation == 'n'
               || this->b[king_x+2][king_y+1].annotation == 'n')
                return true;
        }
        if(king_y == 0 && king_x == 6)  {
             if(this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y + 2].annotation == 'n'
               || this->b[king_x-2][king_y+1].annotation == 'n')
                return true;
        }
        if(king_y == 0 && king_x == 0)  {
            if(this->b[king_x+2][king_y+1].annotation == 'n' || this->b[king_x+1][king_y+2].annotation == 'n')
                return true;
        }
        if(king_y == 0 && king_x == 7)  {
            if(this->b[king_x-2][king_y+1].annotation == 'n' || this->b[king_x-1][king_y+2].annotation == 'n')
                return true;
        }
        if(king_y == 1 && king_x < 6 && king_x > 1) {
            if(this->b[king_x-2][king_y+1].annotation == 'n' || this->b[king_x+2][king_y+1].annotation == 'n'
            || this->b[king_x-2][king_y-1].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'
            || this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y+2].annotation == 'n')
                return true;
        }
        if(king_y == 1 && king_x == 0)  {
            if(this->b[king_x+1][king_y+2].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'
               || this->b[king_x+2][king_y+1].annotation == 'n')
                return true;
        }
        if(king_y == 1 && king_x == 7)  {
            if(this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x-2][king_y-1].annotation == 'n'
               || this->b[king_x-2][king_y+1].annotation == 'n')
                return true;
        }
        if(king_y == 1 && king_x == 1)  {
            if(this->b[king_x+2][king_y+1].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'
            || this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y+2].annotation == 'n')
            return true;
        }
        if(king_y == 1 && king_x == 6)  {
            if(this->b[king_x-2][king_y+1].annotation == 'n' || this->b[king_x-2][king_y-1].annotation == 'n'
            || this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y+2].annotation == 'n')
            return true;
        }

        if(king_y == 7 && king_x > 1 && king_x < 6) {
            if(this->b[king_x-1][king_y-2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n'
            || (this->b[king_x-2][king_y-1].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'))
                return true;
        }
        if(king_y == 7 && king_x == 1)  {
            if(this->b[king_x-1][king_y-2].annotation == 'n' || this->b[king_x+1][king_y - 2].annotation == 'n'
               || this->b[king_x+2][king_y-1].annotation == 'n')
                return true;
        }
        if(king_y == 7 && king_x == 6)  {
             if(this->b[king_x-1][king_y-2].annotation == 'n' || this->b[king_x+1][king_y - 2].annotation == 'n'
               || this->b[king_x-2][king_y-1].annotation == 'n')
                return true;
        }
        if(king_y == 7 && king_x == 0)  {
            if(this->b[king_x+2][king_y-1].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n')
                return true;
        }
        if(king_y == 7 && king_x == 7)  {
            if(this->b[king_x-2][king_y-1].annotation == 'n' || this->b[king_x-1][king_y-2].annotation == 'n')
                return true;
        }
        if(king_y == 6 && king_x < 6 && king_x > 1) {
            if(this->b[king_x-2][king_y+1].annotation == 'n' || this->b[king_x+2][king_y+1].annotation == 'n'
            || this->b[king_x-2][king_y-1].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'
            || this->b[king_x-1][king_y-2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n')
                return true;
        }
        if(king_y == 6 && king_x == 0)  {
            if(this->b[king_x+1][king_y-2].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'
               || this->b[king_x+2][king_y+1].annotation == 'n')
                return true;
        }
        if(king_y == 6 && king_x == 7)  {
            if(this->b[king_x-1][king_y-2].annotation == 'n' || this->b[king_x-2][king_y-1].annotation == 'n'
               || this->b[king_x-2][king_y+1].annotation == 'n')
                return true;
        }
        if(king_y == 6 && king_x == 1)  {
            if(this->b[king_x+2][king_y+1].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'
            || this->b[king_x-1][king_y-2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n')
            return true;
        }
        if(king_y == 6 && king_x == 6)  {
            if(this->b[king_x-2][king_y+1].annotation == 'n' || this->b[king_x-2][king_y-1].annotation == 'n'
            || this->b[king_x-1][king_y-2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n')
            return true;
        }
        if(king_x == 0 && king_y > 1 && king_y < 6) {
            if(this->b[king_x+2][king_y-1].annotation == 'n' || this->b[king_x+2][king_y+1].annotation == 'n'
               ||this->b[king_x+1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n')
                return true;
        }
        if(king_x == 7 && king_y > 1 && king_y < 6) {
            if(this->b[king_x-2][king_y-1].annotation == 'n' || this->b[king_x-2][king_y+1].annotation == 'n'
               ||this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x-1][king_y-2].annotation == 'n')
                return true;
        }
        if(king_x == 1 && king_y > 1 && king_y < 6) {
            if(this->b[king_x+2][king_y+1].annotation == 'n' || this->b[king_x+2][king_y-1].annotation == 'n'
               || this->b[king_x+1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n'
               || this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x-1][king_y-2].annotation == 'n')
                return true;
        }
         if(king_x == 6 && king_y > 1 && king_y < 6) {
            if(this->b[king_x-2][king_y+1].annotation == 'n' || this->b[king_x-2][king_y-1].annotation == 'n'
               || this->b[king_x+1][king_y+2].annotation == 'n' || this->b[king_x+1][king_y-2].annotation == 'n'
               || this->b[king_x-1][king_y+2].annotation == 'n' || this->b[king_x-1][king_y-2].annotation == 'n')
                return true;
        }

    return false;
}
*/





