#include "gameMaster.hpp"

void GameMaster::startGame()
{
    int players = 0;
    GamePhase gp = GamePhase::HOW_MANY_PLAYER;

    switch (gp)
    {
        case GamePhase::HOW_MANY_PLAYER:
            cin >> "How many players are playing ?" + players << endl;
            break;

        default:
            break;
    }
}