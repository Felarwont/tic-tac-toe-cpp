#include <iostream>
#include <Board.hpp>
#include <Player.hpp>

int main() {
    Board board;
    Player player{"MyName", 'O'};

    board.display();

    std::cout << board.is_full() << std::endl;
    std::cout << "nickname: " << player.nickname << " symbol: " << player.symbol << std::endl;
}