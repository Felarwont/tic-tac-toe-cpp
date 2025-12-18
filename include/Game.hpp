#pragma once
#include <Board.hpp>
#include <Player.hpp>

class Game {
    Board board;
    Player player1;
    Player player2;
    Player* current_player;
public:
    Game(Player& p1, Player& p2);
    void swap_players();
    Player* get_winner();
    void run();
};