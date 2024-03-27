#include "gameMaster.hpp"


GameMaster::GameMaster()
{

}


void GameMaster::startGame()
{
    cout << "Combien y-a-t'il de joueurs ?" << endl;
    cin >> this->nbPlayers;

    vector<Player> Players;

    for (int i = 0; i < this->nbPlayers; i++)
    {
        string name;
        cout << "Nom du joueur ?" << endl;
        cin >> name;
        Player joueur_i(name, 123, 0, 5);

        Players.push_back(joueur_i);
    }
}

int GameMaster::newDiceRoll()
{
    return rand() % 6;
}

bool GameMaster::checkDiceForDouble(int dice1, int dice2)
{
    return (dice1 == dice2) ? true : false;
}


void GameMaster::Game()
{
    GamePhase gp = GamePhase::HOW_MANY_PLAYERS;

    switch (gp)
    {
        case GamePhase::HOW_MANY_PLAYERS:
            startGame();
            break;

        case GamePhase::NEW_GAME_TURN:
            this->dice1 = newDiceRoll();
            this->dice2 = newDiceRoll();

            if(checkDiceForDouble(this->dice1, this->dice2))
            {
                // Player.instance.incrementDouble()
                // if (Player.instance.nbDouble == 3)
                // {
                //    Player.instance.goToHornyJail();
                //    reset Player.instance.nbDouble;
                // }
            }
            else
            {

            }

            // Player.instance.movement = gm.dice1 + gm.dice2;
            // move(Player.instance, Player.instance.movement)

            break;

        default:
            break;
    }
}