#include <Board.hpp>
#include <iostream>
#include <stdexcept>

Board::Board() : field{'1', '2', '3', '4', '5', '6', '7', '8', '9'} {}

void Board::display() {
    for (int i = 0; i < 9; i++) {
            std::cout << field[i] << (((i + 1) % 3 == 0) ? "\n" : "   ");
    }
}

void Board::set_cell(int index, char symbol) {
    if (index < 1 || index > 9) {
        throw std::out_of_range("Index out of range 1-9");
    }
    field[index - 1] = symbol;
}

bool Board::is_occupied(int index) {
    if (index < 1 || index > 9) {
        throw std::out_of_range("Index out of range 1-9");
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