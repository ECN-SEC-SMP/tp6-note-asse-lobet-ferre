#pragma once

#include <iostream>
#include <vector>

#include "player.hpp"

using namespace std;

enum GamePhase
{
    HOW_MANY_PLAYERS = 0,
    NEW_GAME_TURN,
    DICE_ROLL
};

class GameMaster
{
    private:

        int nbPlayers;
        int dice1;
        int dice2;
        vector<Player> Players;

    public:

        GameMaster();

        void Game();
        void startGame();
        void movePlayer(Player player, int movement);
        Player getPlayer(int i);

        int newDiceRoll();

        bool checkDiceForDouble(int dice1, int dice2);

};