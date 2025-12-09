#pragma once

class Board {
    char field[9];
public:
    Board();
    void display();
    bool is_out_of_range(int index);
    void set_cell(const int index, const char symbol);
    bool is_occupied(const int index);
    bool is_full();
    char check_winner();
};