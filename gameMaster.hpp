#pragma once

#include <iostream>

using namespace std;

class GameMaster
{
    public:

    protected:

    private:

        GameMaster();

        void startGame();

        void newDiceRoll();

        void checkDiceForDouble();
};

enum class GamePhase
{
    HOW_MANY_PLAYER = 0,
    NEW_GAME_TURN,
    DICE_ROLL
};
