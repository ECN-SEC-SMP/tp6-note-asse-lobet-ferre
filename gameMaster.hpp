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
        vector<Player> Players;

    public:

        GameMaster();

        void Game();
        void startGame();
        void movePlayerToPosition(Player player, int position);
        void movePlayerFromPosition(Player player, int movement);

        void goToHornyJail(Player horny);

        Player getPlayer(int i);
        int getDice1Number();
        int getDice2Number();

        int newDiceRoll();

        bool checkDiceForDouble(int dice1, int dice2);

};

enum GamePhase
{
    HOW_MANY_PLAYERS = 0,
    NEW_GAME_TURN,
    DICE_ROLL
};