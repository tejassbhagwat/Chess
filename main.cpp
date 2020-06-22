#include <iostream>
#include <fstream>
#include "chess.h"
using namespace std;


int main()  {
    board brd;
    white_player w(&brd);                   //  Class variables
    black_player blk(&brd);
    movement m(&brd, &w, &blk);
    char white[50], black[50], c;
    string s1, s2;
    ofstream file("chess_game.txt", ios::app);      //  File to save record of games
    ofstream save("save.txt", ios::out);            //  File to save game that can be played later
    if(!file)   {
        cout << "File could not be opened" << endl;
        return 0;
    }
    if(!save)   {
        cout << "File could not be opened" << endl;
        return 0;
    }
    cout << "Welcome to the GAME OF CHESS - 2 PLAYER GAME!" << endl;
    cout << "The moves are implemented using Coordinate Notation!" << endl;
    cout << "For example, enter starting position as 'E2' or 'e2'." << endl;
    cout << "Enter finishing position as 'E4' or 'e4'." << endl;
    cout << "Hence after specifying the positions E2-E4 will be played" << endl;
    cout << "You will be prompted to enter moves till you enter a valid move" << endl;
    cout << "Castling can be initiated through the king" << endl;
    cout << "Pawns are auto promoted to Queen" << endl;
    cout << "Lowercase initials denote white pieces and Uppercase initials denote black pieces" << endl;
    cout << "To offer a draw, enter 'Draw' in the starting position" << endl;
    cout << "You may save a game to be played later by entering 'Save' in the starting position" << endl;
    cout << "If you choose to start a new game before completing saved game, progress of that game will be lost" << endl;
    cout << "The games will be recorded in a text file called 'chess_game.txt'" << endl << endl;

    do{
        cout << "Enter a choice :" << endl;
        cout << "N : New Game   L : Load a saved game" << endl;
        cout << "Choice : ";
        cin >> c;
    }while(!(tolower(c) == 'n' || tolower(c) == 'l'));

    if(tolower(c) == 'l')   {
        int k = 0;
          ifstream load("load.txt", ios :: in);
          brd.display();
          if(!load) {
            cout << "No game saved to load!" << endl;
            return 0;
          }
          while(!load.eof())    {
            k++;
            load >> s1 >> s2;
            if(load.eof())
                break;
            save << s1 << " " << s2 << " ";
            m.load_move(s1, s2);                //  Play out the saved moves from the loaded game
            m.move_piece();
            brd.display();
          }
          k--;
          load.close();
            remove("load.txt");
          if(m.game_over()) {
            cout << "Game has been completed" << endl;      //  If saved game is already complete
            return 0;
          }
          if(k%2 == 0)  {
            cout << "WHITE TO PLAY" << endl;
          }
          if(k%2 != 0)  {
            cout << "BLACK TO MOVE" << endl;                //  If saved game is to be continued with black to play
            goto black_move;
          }
    }
     remove("load.txt");
    if(tolower(c) == 'n')   {
    cout << "Enter White Player Name : ";
    gets(white);                                //  Clear out buffer from enter
    cin.getline(white, 50);                     //  White player name input
    cout << "Enter Black Player Name : ";
    cin.getline(black, 50);                     //  Black player name input
    file << "\n\nGame: " << white <<"(White)" << " vs " << black << "(Black)\n\n";
    brd.display();
    }

    while(!(m.game_over())) {           // Continue playing the game till a result is reached (including draw agreement or game save)
        do{
            m.get_move();
            if(m.draw_offer_accept())   {                       // If a draw has been agreed
                cout << "Draw by Agreement" << endl;
                file <<"\nResult : 1/2 - 1/2 \nDraw by Agreement";
                file.close();
                save.close();
                rename("save.txt", "load.txt");
                return 0;
            }
            if(m.is_game_saved())   {                          // If a game is saved
                cout << "Game saved" << endl;
                file.close();
                save.close();
                rename("save.txt", "load.txt");
                return 0;
            }
        }while(!m.white_valid());   //  Continue taking user input until a valid move has been entered
        m.move_piece();
        brd.display();
        file << m.return_start() << "-" << m.return_finish() << " ";        //  Save moves in record of games
        save << m.return_start() << " " << m.return_finish() << " ";        //  Save moves of a game that may be saved to be played later
        if(brd.black_check())
            cout << "CHECK : BLACK!" << endl;
            if(m.black_stalemate()) {               //  If black has no legal moves but not in check, it is stalemate
                if(brd.black_check())   {           //  If black has no legal moves but in check, it is checkmate
                cout << "Checkmate : White Wins!" << endl;
                file << "\nResult: 1-0 \nCheckmate : " << white <<" Won!\n\n";
                break;
                }
                else    {
                    cout << "Draw by Stalemate" << endl;
                    file << "\nResult: 1/2 - 1/2 \nDraw by Stalemate\n\n";
                    return 0;
                }
            }
    black_move:
        do{
            m.get_move();
             if(m.draw_offer_accept())   {                  //  If a draw is agreed
                cout << "Draw by Agreement" << endl;
               file <<"\nResult : 1/2 - 1/2 \nDraw by Agreement";
                file.close();
                save.close();
                rename("save.txt", "load.txt");
                return 0;
            }
            if(m.is_game_saved())   {                       //  If a game is saved
                cout << "Game saved" << endl;
                file.close();
                save.close();
               rename("save.txt", "load.txt");
                return 0;
            }
        }while(!m.black_valid());           //  Continue taking user input until a valid move is entered
        m.move_piece();
        brd.display();
        file << m.return_start() << "-" << m.return_finish() << "\n";   //  Save moves in record of games
        save << m.return_start() << " " << m.return_finish() << " ";    //  Save moves of a game that may be saved to be played later
        if(brd.white_check())
            cout << "CHECK : WHITE!" << endl;
        if(m.white_stalemate()) {                                    //  If white has no legal moves but not in check, it is stalemate
            if(brd.white_check())   {                                //  If white has no legal moves but in check, it is checkmate
            cout << "Checkmate : Black Wins!" << endl;
            file << "Result: 0-1 \nCheckmate : " << black << " Won!\n\n";
            }
            else{
                cout << "Draw by Stalemate" << endl;
                file << "Result: 1/2 - 1/2 \nDraw by Stalemate\n\n";
            }
        }
    }
    file.close();
    save.close();
    rename("save.txt", "load.txt");             //  The saved game that needs to be loaded later
    return 0;
}
