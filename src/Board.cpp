#include <Board.hpp>
#include <iostream>
#include <stdexcept>

Board::Board() : field{'1', '2', '3', '4', '5', '6', '7', '8', '9'} {}

void Board::display() {
    for (int i = 0; i < 9; i++) {
            std::cout << field[i] << "   ";
            if ((i + 1) % 3 == 0) {
                std::cout << '\n';
            }
        }
}

void Board::make_mark(int index, Player& player) {
    if (index < 0 || index > 8) {
        throw std::out_of_range("Index out of range 0-8");
    }
    field[index] = player.symbol;
}

bool Board::is_occupied(int index) {
    if (index < 0 || index > 8) {
        throw std::out_of_range("Index out of range 0-8");
    }
    return !std::isdigit(field[index]);
}

bool Board::is_full() {
    for (int i = 0; i < 9; i++) {
        if (!is_occupied(i)) {
            return false;
        }
    }
    return true;
}