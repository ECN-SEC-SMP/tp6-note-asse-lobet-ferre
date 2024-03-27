#pragma once

#include <iostream>
#include <vector>

#include "player.hpp"

using namespace std;

class GameMaster
{
    private:

        int nbPlayers;
        int dice1;
        int dice2;

    public:

        GameMaster();

        void Game();
        void startGame();
        void movePlayer(Player player, int movement);

        int newDiceRoll();

        bool checkDiceForDouble(int dice1, int dice2);
};

enum class GamePhase
{
    HOW_MANY_PLAYERS = 0,
    NEW_GAME_TURN,
    DICE_ROLL
};
