#include <iostream>
#include "chess.h"
using namespace std;

// PIECE FUNCTIONS

// Piece Constructors

piece :: piece()   {
    is_captured = false;
}

piece :: piece(int x, int y)  {
    is_captured = false;
    s = new spot(x, y);
}

//  Function to capture a piece

void piece :: captured()    {
    this->is_captured = true;
    this->s = NULL;
}

// END OF PIECE FUNCTIONS


// PAWN FUNCTIONS

pawn :: pawn()  {
    this->promotion = false;
}

pawn :: pawn(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
    this->promotion = false;
}

pawn :: pawn(int x, int y, spot *a)    {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
    this->promotion = false;
}

// END OF PAWN FUNCTIONS


//  BISHOP FUNCTIONS

bishop :: bishop(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
}

bishop :: bishop(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
}

//  END OF BISHOP FUNCTIONS

//  KNIGHT FUNCTIONS

knight :: knight(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
}

knight :: knight(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
}

//  END OF KNIGHT FUNCTIONS


//  ROOK FUNCTIONS
// Since rook is involved in castling, it has additional variable : castling_possible

rook :: rook()  {
    castling_possible = true;
}

rook :: rook(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
    this->castling_possible = true;
}

rook :: rook(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
    this->castling_possible = true;
}

// END OF ROOK FUNCTIONS


//  QUEEN FUNCTIONS

queen :: queen(int a, int b)  {
    this->is_captured = false;
    s = new spot(a, b);
}

queen :: queen(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
}

// END OF QUEEN FUNCTIONS


//  KING FUNCTIONS
//  Since King is involved in castling, it has additional variable : castling_possible

king :: king()  {
    this->check = false;
    this->castling_possible = true;
}

king :: king(int a, int b)  {
    this->is_captured = false;
    check = false;
    s = new spot(a, b);
    this->castling_possible = true;
}

king :: king(int x, int y, spot *a) {
    is_captured = false;
    s = a;
    this->s->x = x;
    this->s->y = y;
    check = false;
    this->castling_possible = true;
}

// END OF KING FUNCTIONS
