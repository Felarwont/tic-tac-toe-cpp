#include <Game.hpp>
#include <stdexcept>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Game::Game(Player& p1, Player& p2) : player1(p1), player2(p2), current_player(&player1) {
    if (player1.symbol == player2.symbol) {
        throw std::logic_error("The symbols must be unique.");
    } else if (player1.symbol == 'D' || player2.symbol == 'D') {
        throw std::logic_error("The symbol must not be equal to 'D'.");
    }
}

void Game::swap_players() {
    current_player = (current_player == &player1) ? &player2 : &player1;
}

Player* Game::get_winner() {
    char winner = board.check_winner();
    if (!winner || winner == 'D') {
        return nullptr;
    }
    return (winner == player1.symbol) ? &player1 : &player2;
}

void Game::run() {
    int index;
    while (true) {
        if (board.check_winner()) {
            Player* winner = get_winner();
            cout << "Winner is " << ((winner) ? winner->nickname : "Draw") << endl;
            break;
        }

        board.display();
        
        cout << "Select a index: ";
        cin >> index;
        
        if (cin.fail()) {
            cout << "[!] It's not a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (board.is_out_of_range(index)) {
            cout << "[!] This out of range" << endl;
            continue;
        }
        if (board.is_occupied(index)) {
            cout << "[!] This cell is occupied." << endl;
            continue;
        }
        board.set_cell(index, current_player->symbol);
        swap_players();
    }
}