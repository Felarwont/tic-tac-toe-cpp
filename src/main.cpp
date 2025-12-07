#include <iostream>
#include <Board.hpp>

int main() {
    Board board;

    board.display();

    std::cout << board.is_full() << std::endl;
}