#include "Player.h"


using namespace std;
// CONSTRUCTS PLAYER

Player::Player(){}

/* *****************************************************************************
 Player()
 
 DESCRIPTION - This constructs a Player with a name
 
 PARAMETERS:
 @player_name - The name of the player
 
 returns - object in Player class
 ***************************************************************************** */
Player::Player(string player_name)
{
    name = player_name;
}

/* *****************************************************************************
 getName()
 
 DESCRIPTION - This function gets name of the Player
 
 RETURNS - The players name
 ***************************************************************************** */
string Player::getName() const
{
    return name;
}

/* *****************************************************************************
 getName()
 
 DESCRIPTION - This function gets the number of wins of a player
 
 RETURNS - an integer - the amount of wins a player has
 ***************************************************************************** */
int Player::getWins() const
{
    return wins;
}

/* *****************************************************************************
 addWins()
 
 DESCRIPTION - This function adds a win to the Player's wins
 
 RETURNS - total amount of wins
 ***************************************************************************** */
int Player::addWins()
{
    wins++;
    return wins;
}

/* *****************************************************************************
 getLosses()
 
 DESCRIPTION - This function gets the losses of the Player
 
 RETURNS - The total number of losses
 ***************************************************************************** */
int Player::getLosses() const
{
    return losses;
}

/* *****************************************************************************
 addLosses()
 
 DESCRIPTION - This function adds a loss to the Player's losses
 
 RETURNS - total amount of losses
 ***************************************************************************** */
int Player::addLosses()
{
    losses++;
    return losses;
}

/* *****************************************************************************
 getDraws()
 
 DESCRIPTION - This function gets the total number of draws of a Player
 
 RETURNS - total number of draws
 ***************************************************************************** */
int Player::getDraws() const
{
    return draws;
}

/* *****************************************************************************
 addDraws()
 
 DESCRIPTION - This function adds a draw to the total number of Player's draws
 
 RETURNS - total number of draws
 ***************************************************************************** */
int Player::addDraws()
{
    draws++;
    return draws;
}

/* *****************************************************************************
 getWinRecord()
 
 DESCRIPTION - This function gets the win record as a percentage of the Player
               (wins/total matches)

 RETURNS - win percentage of player
 ***************************************************************************** */
double Player::getWinRecord()
{
    double win_percentage = 0, matches = 0;
    matches = wins + losses + draws;
    win_percentage = (wins / matches) * 100;
    
    return win_percentage;
}

/* *****************************************************************************
 toString()
 
 DESCRIPTION - This function puts all the useful information into a string
 
 PARAMETERS:
 
 RETURNS - string w/ players name, wins, losses, draws, and win percentage
 ***************************************************************************** */
string Player::toString()
{
    double win_percentage = 0;
    win_percentage = getWinRecord();

    stringstream ss;
    ss << "Name: " << name << endl;
    ss << "Wins: " << wins << endl;
    ss << "Losses: " << losses << endl;
    ss << "Draws: " << draws << endl;
    ss << "Winning Percentage: " << win_percentage << "%" << endl;
    
    return ss.str();
}

/* *****************************************************************************
 getRPSThrow()
 
 DESCRIPTION - This function simulates a player randomly choosing rock paper or scissors
 
 RETURNS - an integer either 1, 2, or 3 representing rock paper or scissors
 ***************************************************************************** */
int Player::getRPSThrow()
{
    const int NUM_CHOICES = 3;
    int shoot = 0;
    int choice = 0;
    
    choice = rand() % NUM_CHOICES + 1;
    
    switch (choice)
    {
        case 1: shoot = ROCK; break;
        case 2: shoot = PAPER; break;
        case 3: shoot = SCISSORS; break;
    }
    
    return shoot;
}