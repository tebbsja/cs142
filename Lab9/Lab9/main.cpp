#include <vector>
#include "Player.h"

using namespace std;
/* TEST CASES
 
 1) input 6 - exit program
 
 2) input 2 - input "austin" should create a Player* austin
    input 1 - should display the Player austin, along with statistics (all 0 right now)
    input 2 - input "adam" should create Player* adam
    input 3 - input "austin"
    input 3 - input "adam"
    input 4 - should display Players austin and adam (along w/ statistics?)
    input 5 - should display either rock paper or scissors for adam and austin and tell who won, or 
              in the event of a draw, that it ended in a draw
    input 4 - should be empty, and not display anything
    input 1 - should display Payers austin and adam along w/ statistics (should just be 1 number with rest
              0's)
    input 6 - end program
 
 3) input 5 - should give me error that there are not enough players
    input 1 - should be empty
    input 2 - input austin - create Player austin
    input 3 - input austin - add austin to line up
    input 3 - input austin - add austin to line up
    input 5 - should result in a draw
    input x - display INVALID input
    input 3 - input austin
    input 5 - should give me error not enough players
    input 2 - input austin should give me error, austin is already playing
    input 1 - should display Player austin with 1 draw
    input 6 - end program
 
 4) input 2 - input austin
    input 2 - input adam
    input 2 - input aubrey
    input 2 - input allyson
    input 4 - should display Players, austin, adam, aubrey, allyson
    input 5 - austin and adam should battle
    input 4 - should only display aubrey and allyson
    input 5 - aubrey and allyson should battle
    input 4 - should display nothing, should be empty
    input 1 - display austin, adam, aubrey, allyson and statistics
    input 6 - end program
 
 */

/* *****************************************************************************
 determineWinner()
 
 DESCRIPTION - This function determines who won in a rock, paper, scissors battle
 
 PARAMETERS:
 @player1Throw - This is an integer representing either "rock", "paper", or "scissors"
 @player2Throw - This is an integer representing either "rock", "paper", or "scissors"
 @player1 - This is a player pointer to the first player in line to play
 @player2 - This is a player pointer to the second player in line to play
 
 RETURNS - The function returns the name of the player who won.
 ***************************************************************************** */
string determineWinner(int player1Throw, int player2Throw, Player* player1, Player* player2)
{
    string winner;
    
    if (player1Throw == ROCK)
    {
        
        if (player2Throw == ROCK)
        {
            player1->addDraws();
            player2->addDraws();
        }
        else if (player2Throw == PAPER)
        {
            player1->addLosses();
            player2->addWins();
            winner = player2->getName();
        }
        else if (player2Throw == SCISSORS)
        {
            player1->addWins();
            player2->addLosses();
            winner = player1->getName();
        }
    }
    else if (player1Throw == PAPER)
    {
        
        if (player2Throw == ROCK)
        {
            player1->addWins();
            player2->addLosses();
            winner = player1->getName();
        }
        else if (player2Throw == PAPER)
        {
            player1->addDraws();
            player2->addDraws();
        }
        else if (player2Throw == SCISSORS)
        {
            player1->addLosses();
            player2->addWins();
            winner = player2->getName();
        }
    }
    else if (player1Throw == SCISSORS)
    {
        
        if (player2Throw == ROCK)
        {
            player1->addLosses();
            player2->addWins();
            winner = player2->getName();
        }
        else if (player2Throw == PAPER)
        {
            player1->addWins();
            player2->addLosses();
            winner = player1->getName();
        }
        else if (player2Throw == SCISSORS)
        {
            player1->addDraws();
            player2->addDraws();
        }
    }
    
    return winner;

}
/* *****************************************************************************
 findPlayer()
 
 DESCRIPTION - This function determines if a player is in the vector
 
 PARAMETERS:
 @players - This is a vector of all players
 @player - This is a string of the name of the player to look for
 
 RETURNS - The function returns the index of the player, if in the vector, or -1 
            if the player is not in the vector
 ***************************************************************************** */

int findPlayer(vector<Player*> players, string player)
{
    int index = -1;
    
    for (int i=0; i < players.size(); i++)
    {
        if (players[i]->getName() == player)
        {
            index = i;
        }
    }
    
    return index;
}

/* *****************************************************************************
menu()
 
 DESCRIPTION - This function displays menu options and prompts for an integer. 
                It will check if the integer was valid. If it is not valid,
                it will continue to prompt
 
 PARAMETERS:
 
 RETURNS - The function returns an integer representing the menu choice.
 ***************************************************************************** */
int menu()
{
    int choice=0;
    bool valid = true;
    
    do
    {
        cout << "****** WELCOME TO THE ROCK PAPER SCISSORS THROWDOWN ******\n";
        cout << "PLEASE SELECT ONE OF THE OPTIONS BELOW\n";
        cout << "1) Show Players\n";
        cout << "2) Add Player\n";
        cout << "3) Add to Line-Up\n";
        cout << "4) Show Line-Up\n";
        cout << "5) Fight\n";
        cout << "6) Quit\n";
    
        cin >> choice;
    
        if (cin.fail())
        {

            cin.clear();
            string ignore;
            cin >> ignore;
            cout << "INVALID ENTRY\n\n";
            valid = false;
        }
        else if (choice < 1 || choice > 6)
        {
            cout << "INVALID ENTRY\n\n";
            valid = false;
        }
        else
        {
            valid = true;
        }
    }
    while (!valid);
    
    return choice;
}

/* *****************************************************************************
 showPlayers()
 
 DESCRIPTION - This function prints out all players in a vector, along with their statistics
 
 PARAMETERS:
 @all_players - This is the vector of all players
 
 RETURNS - nothing
 ***************************************************************************** */
void showPlayers(vector<Player*>  all_players)
{
    for (int i=0; i < all_players.size(); i++)
    {
        cout << all_players[i]->toString() << endl;
    }
}

/* *****************************************************************************
 addPlayer()
 
 DESCRIPTION - This function prompts for the name of a player to add. It then checks
                to see if the player is already in the vector. If the player is not found,
                the player will be added to the vector.
 
 PARAMETERS:
 @all_players - This is a vector of all players.
 
 RETURNS - nothing
 ***************************************************************************** */
void addPlayer(vector<Player*> & all_players)
{
    cout << "What is the name of the player? ";
    string name;
    getline(cin,name);
    
    int index =0;
    index = findPlayer(all_players, name);
    
    if (index == -1)
    {
        Player* newPlayer = new Player(name);
        all_players.push_back(newPlayer);
        cout << endl << name << " has been added\n";
    }
    else
    {
        cout << "THAT PLAYER IS ALREADY PLAYING\n";
    }
    
    cout << endl;
}

/* *****************************************************************************
 addToLineUp()
 
 DESCRIPTION - This function prompts to add a player into the line up. If player is
                in player vector, player will be added to line_up vector.
 
 PARAMETERS:
 @all_players - This is a vector representing all the players
 @line_up - This is a vector representing players in the line up to play
 
 RETURNS - nothing
 ***************************************************************************** */
void addToLineUp(vector<Player*> all_players, vector<Player*> & line_up)
{
    
    cout << "Who do you want to add to the line up? ";
    string name;
    getline(cin,name);
    
    int index = 0;
    index = findPlayer(all_players, name);
    
    if (index == -1)
    {
        cout << "THAT PLAYER DOES NOT EXIST\n";
    }
    else
    {
        Player* newPlayer = all_players[index];
        line_up.push_back(newPlayer);
        cout << endl << newPlayer->getName() << " was added to the line-up\n";
    }
    
    cout << endl;
}

/* *****************************************************************************
 rockPaperScissors()
 
 DESCRIPTION - This function converts the int representing either "rock", "paper", or
                "scissors" into the corresponding string.
 
 PARAMETERS:
 @playerThrow - This is an integer representing either "rock", "paper", or "scissors"

 RETURNS - The function returns the string corresponding to the integer thrown
 ***************************************************************************** */
string rockPaperScissors(int playerThrow)
{
    string shoot;
    
    if (playerThrow == ROCK)
    {
        shoot = "rock";
    }
    else if (playerThrow == PAPER)
    {
        shoot = "paper";
    }
    else if (playerThrow == SCISSORS)
    {
        shoot = "scissors";
    }
    
    return shoot;
}

/* *****************************************************************************
 fight()
 
 DESCRIPTION - This function simulates a rock, paper, scissors battle, and records 
                the statistics of the match.
 
 PARAMETERS:
 @line_up - This is an vector of players waiting to battle.
 
 RETURNS - nothing
 ***************************************************************************** */
void fight(vector<Player*> &line_up)
{
    //doesn't need to loop - just one battle
    if (line_up.size() < 2)
    {
        cout << "THERE ARE NOT ENOUGH PLAYERS\n";
    }
    else
    {
        // grab first two players in vector
        Player* player1 = line_up[0];
        Player* player2 = line_up[1];
        
        if (player1->getName() == player2->getName())
        {
            cout << "THIS MATCH RESULTS IN A DRAW\n\n";
            player1->addDraws();
            line_up.erase(line_up.begin(), line_up.begin() + 2);
        }
        else
        {
            int player1Throw = 0, player2Throw = 0;
            string p1throw, p2throw, winner;
        
            //determine which int each player "threw"
            player1Throw = player1->getRPSThrow();
            player2Throw = player2->getRPSThrow();
        
            //who won?
            winner = determineWinner(player1Throw, player2Throw, player1, player2);
        
            //what string did they each throw?
            p1throw = rockPaperScissors(player1Throw);
            p2throw = rockPaperScissors(player2Throw);
        
            cout << "FIGHT BEGINS!\n\n";
            cout << player1->getName() << " throws " << p1throw << "!\n";
            cout << player2->getName() << " throws " << p2throw << "!\n";
        
            // if they throw the same thing, its a draw, else display winner
            if (player1Throw == player2Throw)
            {
                cout << "\nDRAW!\n";
            }
            else
            {
                cout << endl << winner << " is the winner!\n";
            }
        
            //erase first two players from vector
            line_up.erase(line_up.begin(), line_up.begin() + 2);
        }

    }
    cout << endl;
}


int main()
{
    srand(time(0));
    bool running = true;
    vector<Player*> all_players;
    vector<Player*> line_up;
    

    while (running)
    {
        int choice = 0;
        choice = menu();
        cin.ignore();
        
        switch (choice)
        {
            case 1: cout << endl; showPlayers(all_players); break;
            case 2: cout << endl; addPlayer(all_players); break;
            case 3: cout << endl; addToLineUp(all_players,line_up); break;
            case 4: cout << endl; showPlayers(line_up); break;
            case 5: cout << endl; fight(line_up); break;
            case 6: running = false; break;
            
        }
    }
    
    //do i need this?
    for (int i=0; i < all_players.size(); i++)
    {
        delete all_players[i];
    }
    for (int i=0;i < line_up.size(); i++)
    {
        delete line_up[i];
    }
    
    return 0;
}