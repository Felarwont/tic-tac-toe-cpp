#pragma once

class Board {
    char field[9];
public:
    Board();
    void display();
    void set_cell(int index, char symbol);
    bool is_occupied(int index);
    bool is_full();
};