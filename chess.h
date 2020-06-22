#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

#include<string.h>
#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF
using namespace std;

class spot  {
    spot();
    spot(int, int);
     ~spot() {}
    char annotation;
    int x;
    int y;
    friend class board;
    friend class white_player;
    friend class black_player;
    friend class movement;
    friend class piece;
    friend class pawn;
    friend class knight;
    friend class bishop;
    friend class rook;
    friend class queen;
    friend class king;
};

class piece {
public:
    spot *s;
    bool is_captured;
    void captured();
    piece(int, int);
    piece();
    ~piece()    {}

};

class pawn : private piece   {
    bool promotion;
    pawn();
    pawn(int, int, spot *);
    pawn(int, int);
    friend class white_player;
    friend class black_player;
    friend class movement;
};

class bishop : private piece {
    bishop(){}
    bishop(int, int, spot *);
    bishop(int, int);
    friend class white_player;
    friend class black_player;
    friend class movement;
};

class knight : private piece {
    knight(){}
    knight(int, int, spot *);
    knight(int, int);
    friend class white_player;
    friend class black_player;
    friend class movement;
};

class rook : private piece   {
    bool castling_possible;
    rook();
    rook(int, int, spot *);
    rook(int, int);
    friend class white_player;
    friend class black_player;
    friend class movement;
};

class queen : private piece  {
    queen() {}
    queen(int, int, spot *);
    queen(int, int);
    friend class white_player;
    friend class black_player;
    friend class movement;
};

class king : private piece  {
    bool castling_possible;
    bool check;
    king();
    king(int, int, spot *);
    king(int, int);
    friend class white_player;
    friend class black_player;
    friend class movement;
};


class board {
    spot b[8][8];
    friend class white_player;
    friend class black_player;
    friend class movement;
public:
    board();
    void display();
    bool white_check();
    bool black_check();
     ~board()  {}
};

class white_player  {
    board *BOARD;
    pawn white_pawn[8];
    bishop white_bishop[2];
    knight white_knight[2];
    rook white_rook[2];
    queen white_queen;
    king white_king;
    void capture(spot *);
public:
    white_player(board *);
    ~white_player() {}
    friend class movement;
};

class black_player  {
    board *BOARD;
    pawn black_pawn[8];
    bishop black_bishop[2];
    knight black_knight[2];
    rook black_rook[2];
    queen black_queen;
    king black_king;
    void capture(spot *);
public:
    black_player(board *);
    ~black_player(){}
    friend class movement;
};

class movement  {
    string s1, s2;
    bool draw;
    bool save;
    white_player *WHITE_PLAYER;
    black_player *BLACK_PLAYER;
    board *BOARD;
    int x1, y1, x2, y2;
    spot *start;
    spot *finish;
    bool white_pawn_valid();
    bool white_knight_valid();
    bool white_bishop_valid();
    bool white_rook_valid();
    bool white_queen_valid();
    bool black_pawn_valid();
    bool black_bishop_valid();
    bool black_knight_valid();
    bool black_rook_valid();
    bool black_queen_valid();
    bool white_king_castle_valid();
    bool white_queen_castle_valid();
    bool white_king_valid();
    bool black_king_valid();
    bool black_king_castle_valid();
    bool black_queen_castle_valid();
    bool white_illegal_move();
    bool black_illegal_move();
    void draw_offer();
    void save_game();
public:
    movement(board *, white_player *, black_player *);
    void get_move();
    void load_move(string, string);
    bool white_valid();
    bool black_valid();
    bool white_stalemate();
    bool black_stalemate();
    void move_piece();
    string return_start();
    string return_finish();
    bool draw_offer_accept();
    bool game_over();
    bool is_game_saved();
    ~movement() {}
};

bool valid_input(string);
string lower(string);


#endif // CHESS_H_INCLUDED
