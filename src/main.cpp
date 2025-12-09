#include <Game.hpp>
#include <iostream>

int main() {
    std::string name1, name2;
    char symbol1, symbol2;
    std::cout << "Enter the nickname of the first player: ";
    std::cin >> name1;
    std::cout << "Enter the symbol of the first player: ";
    std::cin >> symbol1;
    std::cout << "Enter the nickname of the second player: ";
    std::cin >> name2;
    std::cout << "Enter the symbol of the second player: ";
    std::cin >> symbol2;
    Player player1{name1, symbol1};
    Player player2{name2, symbol2};

    Game game(player1, player2);

    game.run();
}