#pragma once
#include <Player.hpp>

class Board {
    char field[9];
public:
    void display();
    void make_mark(int index, Player& player);
    bool is_occupied(int index);
    bool is_full();
};