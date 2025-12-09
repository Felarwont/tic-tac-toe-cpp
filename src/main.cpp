#include <iostream>
#include <Board.hpp>
#include <Player.hpp>

int main() {
    Board board;
    Player player{"MyName", 'Z'};

    board.display();
    for (int i = 1; i <= 9; i++)
        board.set_cell(i, player.symbol);
    board.display();

    std::cout << board.is_full() << std::endl;
    std::cout << "nickname: " << player.nickname << " symbol: " << player.symbol << std::endl;
}