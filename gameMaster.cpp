#include "gameMaster.hpp"

// Constructor
GameMaster::GameMaster()
{
    this->nbPlayers = 0;
    this->dice1 = 0;
    this->dice2 = 0;
}

// Begging of a game
void GameMaster::startGame()
{
    cout << "Combien y-a-t'il de joueurs ?" << endl;
    cin >> this->nbPlayers;

    if (this->nbPlayers > 8)
    {
        return;
    }

    string name;
    for (int i = 0; i < this->nbPlayers; i++)
    {
        cout << "Nom du joueur ?" << endl;
        cin >> name;
        Player joueur_i(name, 1500, 0, 0, 0);

        Players.push_back(joueur_i);
    }
}

// Moves a player to a specific position
void GameMaster::movePlayerToPosition(Player player, int position)
{
    player.setPosition(position);
}

// Moves a player from his current position
void GameMaster::movePlayerFromPosition(Player player, int movement)
{
    player.setPosition(player.getPosition() + movement);
}

// Generates a rand number modulo 6 as a new dice roll
int GameMaster::newDiceRoll()
{
    return rand() % 6;
}

// Checks if two dice rolls are equals
bool GameMaster::checkDiceForDouble(int dice1, int dice2)
{
    return (dice1 == dice2) ? true : false;
}

// Returns an instance of player
Player GameMaster::getPlayer(int i)
{
    return this->Players[i];
}

// Getter for the first dice
int GameMaster::getDice1Number()
{
    return this->dice1;
}

// Getter for the second dice
int GameMaster::getDice2Number()
{
    return this->dice2;
}

// Moves a player directly to the jail
void GameMaster::goToHornyJail(Player horny)
{
    int coordinates = 10;
    movePlayerToPosition(horny, coordinates);
}

// The main game sequence
void GameMaster::Game()
{
    GamePhase gp = GamePhase::HOW_MANY_PLAYERS;
    switch (gp)
    {
        case GamePhase::HOW_MANY_PLAYERS:
            cout << "Lancement du jeu !" << endl;
            startGame();
            gp = GamePhase::NEW_GAME_TURN;

        case GamePhase::NEW_GAME_TURN:

            for (int j=0; j < this->nbPlayers; j++)
            {
                cout << "Début d'un tour de jeu pour : " << this->getPlayer(j).getName() << "." << endl;

                this->dice1 = newDiceRoll();
                cout << "Résultat du premier dé : " << dice1 << "." << endl;

                this->dice2 = newDiceRoll();
                cout << "Résultat du deuxième dé : " << dice2 << "." << endl;

                if(checkDiceForDouble(this->dice1, this->dice2))
                {
                    cout << this->getPlayer(j).getName() << " a fait un double !" << endl;

                    this->getPlayer(j).setNbDouble((this->getPlayer(j).getNbDouble() + 1));

                    cout << "Ce joueur cumule un total de " << this->getPlayer(j).getNbDouble() << " double(s)." << endl;
                    if (this->getPlayer(j).getNbDouble() == 3)
                    {
                        cout << "Go to horny jail " << this->getPlayer(j).getName() << "." << endl;
                        this->goToHornyJail(this->getPlayer(j));

                        // reset the Player's Nb of double
                        this->getPlayer(j).setNbDouble(0);
                        cout << this->getPlayer(j).getName() << " voit son nombre de doubles être remis à " << this->getPlayer(j).getNbDouble() << "." << endl;
                    }
                }

                this->getPlayer(j).setMovement(dice1 + dice2);

                cout << this->getPlayer(j).getName() << " bouge de " << this->getPlayer(j).getMovement() << " cases." << endl;
                movePlayerFromPosition(this->getPlayer(j), this->getPlayer(j).getMovement());

                cout << this->getPlayer(j).getName() << " est maintenant sur la case " << this->getPlayer(j).getPosition() << "." << endl;
            }
        break;

        default:
            break;

    }
}