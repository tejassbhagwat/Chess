#include <iostream>
#include "chess.h"
using namespace std;

//  Setting up board and position of pieces
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

//  Setting up board and position of pieces
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

//  Function to capture white piece
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

//  Function to capture black piece
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

