#include <Board.hpp>
#include <iostream>
#include <stdexcept>

Board::Board() : field{'1', '2', '3', '4', '5', '6', '7', '8', '9'} {}

void Board::display() {
    for (int i = 0; i < 9; i++) {
            std::cout << field[i] << (((i + 1) % 3 == 0) ? "\n" : "   ");
    }
}

bool Board::is_out_of_range(int index) {
    return (index < 1 || index > 9);
}

void Board::set_cell(const int index, const char symbol) {
    if (index < 1 || index > 9) {
        throw std::out_of_range("Index out of range 1-9.");
    }
    field[index - 1] = symbol;
}

bool Board::is_occupied(const int index) {
    if (index < 1 || index > 9) {
        throw std::out_of_range("Index out of range 1-9.");
    }
    return !std::isdigit(field[index - 1]);
}

bool Board::is_full() {
    for (int i = 1; i <= 9; i++) {
        if (!is_occupied(i)) {
            return false;
        }
    }
    return true;
}

char Board::check_winner() {
    short win_indexes[8][3] = {
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    for(auto& row : win_indexes) {
        if (field[row[0]] == field[row[1]] && field[row[1]] == field[row[2]] && field[row[0]] == field[row[2]]) {
            return field[row[0]];
        }
    }
    if (is_full()) {
        return 'D';
    }
    return '\0';
}