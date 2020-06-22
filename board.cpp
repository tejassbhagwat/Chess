#include <iostream>
#include "chess.h"
using namespace std;

//  SPOT FUNCTIONS

spot :: spot(int x, int y)   {
    this->x = x;
    this->y = y;
    annotation = 'o';           // o represents unoccupied spot
}

spot :: spot()  {
    annotation = 'o';           // o represents unoccupied spot
}

// END OF SPOT FUNCTIONS


//  BOARD FUNCTIONS

//  Board Constructor
board :: board  ()  {
    for(int i = 0; i < 8; i++)  {
        for(int j= 0; j < 8; j++)   {
            b[i][j].x = i+1;            //  Setting x and y values of each spot of board
            b[i][j].y = j+1;
        }
    }
}

//  Function to display the board and position
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

//  Function to check whether the white king is in check in the current board position
bool board :: white_check() {
    int white_king_x = 0, white_king_y = 0, black_king_x = 0, black_king_y = 0, i, j;
    for(i = 0; i < 8; i++)  {
        for(j = 0; j < 8; j++)  {
            if(this->b[i][j].annotation == 'k') {           //  Determining position of white king
                white_king_x = i;
                white_king_y = j;
            }
            if(this->b[i][j].annotation == 'K') {           //  Determining position of black king
                black_king_x = i;
                black_king_y = j;
            }

        }
    }

    //  Checking whether the king would be in check from the opposition king
    if((black_king_x - white_king_x == 1 || black_king_x - white_king_x == 0 || black_king_x - white_king_x == -1)
       && (black_king_y - white_king_y == 1 || black_king_y - white_king_y == 0 || black_king_y - white_king_y == -1))
       return true;

    //  Checking whether the king is in check from opposition pawns
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

    //  Checking whether king is in check from rook/queen along rows and columns
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

    //  Checking whether king is in check from bishop or queen along diagonals
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

    //  Checking whether king is in check from a knight
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

//  Function to check whether the black king is in check in the current position
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

    //  Checking whether king is in check from opposition king
    if((opp_king_x - king_x == 1 || opp_king_x - king_x == 0 || opp_king_x - king_x == -1) &&
       (opp_king_y - king_y == 1 || opp_king_y - king_y == 0 || opp_king_y - king_y == -1))
       return true;

    //  Checking whether king is in check from opposition pawns
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

    //  Checking whether king is in check from rook or queen along rows and columns
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

    //  Checking whether king is in check from bishop or queen along diagonals
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

    //  Checking whether king is in check from a knight
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



