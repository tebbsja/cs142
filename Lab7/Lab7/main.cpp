
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Test Cases
 
 1) input - 1 should display all restaurants, followed by a comma. The last restaurant should have no comma.
 2) input - 6 should end the program
 3) input - 4 shuffle restaurants, each restaurant should appear only once.
 4) input - 3 remove 'Betos' should tell me 'Betos' has been removed. input - 5, should not allow me to begin tournament, due to an invalid number of restaurants
 5) input - 2 add 'Subway' should tell me 'Subway' has been added to the vector. input 1 - display vector
    should have 9 restaurants. input -3 remove 5 restaurants. input 5. should choose 2 random restaurants, input 1(select one). Display other 2 restaurants in vector. Choose one. Display 2 winner restaurants
        choose one. Selected restaurant should be displayed as winner.
 
 */

/* *****************************************************************************
 findRestaurant()
 
 DESCRIPTION - This function searches the vector for a specific restaraunt. If found in the vector, the function will return the index of the restaraunt. If not found, the function will return '-1.'
 
 PARAMETERS/INPUTS:
 @restaurants - This vector parameter is the pool of restaurants eligible for the tournament.
 @restaurant - This string parameter is the specific restaurant the user is trying to add or delete from the pool of restaurants.
 
 RETURNS - If the restaurant is in the vector, the function will return the index of the restaurant in the vecotr. If the restaurant is not found in the vector, the function will return '-1.'
 
 ***************************************************************************** */

int findRestaurant(vector<string> restaurants, string restaurant)
{
    int index =-1;
    
    for (int i=0; i <restaurants.size() ; i++)
    {
        if ( restaurant == restaurants[i])
        {
            index = i;
        }
    }

    return index;
}

/* *****************************************************************************
 displayRestaurants()
 
 DESCRIPTION - This function will print out all of the restaraunts that are currently in the vector.
 
 PARAMETERS/INPUTS:
 @restaraunts - This vector parameter is the pool of restaraunts eligble for the tournament.
 
 RETURNS - The function does not return a value, it only prints out the values in the vector.
 
 ***************************************************************************** */

void displayRestaurants(vector<string> restaraunts)
{
    int last_pos =0;
    last_pos = restaraunts.size() -1;
    for (int i=0; i < restaraunts.size(); i++)
    {
        if (restaraunts.size() == 1)
        {
            cout << restaraunts[i] << " ";
        }
        else
        {
            if (restaraunts[i] == restaraunts[last_pos])
            {
                cout << restaraunts[i];
            }
            else
            {
                cout << restaraunts[i] << ", ";
            }
        }
    }
}

/* *****************************************************************************
 menu()
 
 DESCRIPTION - This function prompts the user to choose an option from the menu.
 
 PARAMETERS/INPUTS:
    This function does not have any parameters.
 
 RETURNS - This function will return an integer value from 1 - 6 depending on the users input.
 
 ***************************************************************************** */

int menu()
{
    int choice = 0;
    
    cout << "\n*****RESTAURANT MADNESS*****\n\n";
    cout << "Please select one of the following options:\n\n";
    cout << "1) Display All Restaurants\n";
    cout << "2) Add a Restaurant\n";
    cout << "3) Remove a Restaurant\n";
    cout << "4) Shuffle Restaurants\n";
    cout << "5) Begin Tournament\n";
    cout << "6) Quit\n";
    cin >> choice;

    return choice;

}

/* *****************************************************************************
 removeRestaurant()
 
 DESCRIPTION - This function prompts the user for a restaurant to remove from the vector. Upon receiving input from the user the function sends the restaurant string to the findRestaurant function. If the restaurant is in the vector, the function will remove the restaurant. If it is not in the vector, the function will inform the user the restaurant is not in the tournament.
 
 PARAMETERS/INPUTS:
 @restaurants - This vector parameter contains the possible restaurants the user can choose to remove from the tournament.
 
 RETURNS - The function does not return a value, however it does change the size of the vector.
 
 ***************************************************************************** */

bool removeRestaurant(vector<string>& restaurants, string restaurant_to_remove)
{
    bool removed = true;

    int found =0;
    found = findRestaurant(restaurants, restaurant_to_remove);
    
    int last_pos = restaurants.size() -1;
    if (found != -1)
    {
        restaurants[found] = restaurants[last_pos];
        restaurants.pop_back();
        removed = true;
    }
    else
    {
        removed = false;
    }
    return removed;
}

/* *****************************************************************************
 addRestaurant()
 
 DESCRIPTION - This function prompts the user for a restaurant to add to the vector. Upon receiving input from the user the function sends the restaurant string to the findRestaurant function. If the restaurant is in the vector, the function will inform the user the restaurant is already in the tournament. If it is not in the vector, the function will add the restaurant to the tournament.
 
 PARAMETERS/INPUTS:
 @restaurants - This vector parameter contains the restaurants eligible for the tournament.
 
 RETURNS - The function does not return a value, however it does change the size of the vector.
 
 ***************************************************************************** */

void addRestaurant(vector<string>& restaurants)
{
    cout << "What is the name of the restaurant you want to add? ";
    
    string restaurant_to_add;
    getline(cin,restaurant_to_add);
    
    int found=0;
    found = findRestaurant(restaurants, restaurant_to_add);

    if (found == -1)
    {
        restaurants.push_back(restaurant_to_add);
        cout << endl << restaurant_to_add << " was added to the tournament.\n";
    }
    else
    {
        cout << "\nThat restaurant is already in the tournament!\n";
    }
    
}

/* *****************************************************************************
 shuffleRestaurants()
 
 DESCRIPTION - This function shuffles, at random, the position of all the restaurants in the vector.
 
 PARAMETERS/INPUTS:
 @restaurants - This vector parameter contains the all the restaurants to be shuffled.
 
 RETURNS - The function does not return a value, however it does change the positions of the restaurants in the vector.
 
 ***************************************************************************** */

void shuffleRestaurants(vector<string>& restaurants)
{

    int index = 0;
    index = restaurants.size()-1;
    int rand_pos =0;
    string storage;

    for (int i=0; i <= index;i++)
    {
        //Dairy Queen is first every time...
        rand_pos = rand() % index + 1;
        storage = restaurants[i];
        restaurants[i] = restaurants[rand_pos];
        restaurants[rand_pos] = storage;

    }
    cout << "The restaraunts were shuffled!\n";
}

/* *****************************************************************************
 isNumRestaurantsValid()
 
 DESCRIPTION - This function checks to see if the amount of restaurants is valid, (2^n) where n = an int > 0
 
 PARAMETERS/INPUTS:
 @restaurants - This vector parameter contains the amount of restaurants eligible for the tournament.
 
 RETURNS - The function returns either true or false. If the amount of restaurants = 2^n the function will return true, otherwise it will return false.
 
 ***************************************************************************** */

bool isNumRestaurantsValid(vector<string> restaurants)
{
    bool valid_restaurants;
    double whole=0, decimal=0;
    int size =0, base=0;
    
    size = restaurants.size();
    whole = (log10(size)) / (log10(2));
    base = whole;
    
    decimal = whole - base;
    
    if (decimal > 0) // if the number has a decimal, it is not an integer, therefore not a valid number
    {
        valid_restaurants = false;
        cout << "ERROR! TOURNAMENT MUST HAVE RESTAURANTS = 2^X.\n";
        cout << "PLEASE CHANGE THE AMOUNT OF RESTAURANTS TO BEGIN\n\n";
    }
    else
    {
        valid_restaurants = true;
    }
    
    return valid_restaurants;
}
/* *****************************************************************************
 getRandomRestaurant()
 
 DESCRIPTION - This function will grab a random restaurant from the vector.
 
 PARAMETERS/INPUTS:
 @restaurants - This vector parameter contains all the restaurants eligble for the tournament.
 
 RETURNS - The function returns a random restaurant string.
 
 ***************************************************************************** */

string getRandomRestaurant(vector<string> restaurants)
{
    string rand_restaurant;
    int rand_index = 0;
    rand_index = rand() % restaurants.size();
    rand_restaurant = restaurants[rand_index];
    
    return rand_restaurant;
}

/* *****************************************************************************
 getWinner()
 
 DESCRIPTION - This function will display 2 random restaurants from the vector and prompt the user to choose one.
 
 PARAMETERS/INPUTS:
 @restaurant1 - This string parameter is the first random restaurant.
 @restaurant2 - This string parameter is the second random restaurant.
 
 RETURNS - This function returns the winner of the two restaurants.
 
 ***************************************************************************** */

string getWinner(string restaurant1, string restaurant2)
{
    string winning_restaurant;
    int winner = 0;
    bool invalid = true;
    const int RESTAURANT1 =1, RESTAURANT2 =2;
    
    while (invalid)
    {
        cout << "\nSelect a Restaurant:\n";
        cout << "1) " << restaurant1 << endl;
        cout << "2) " << restaurant2 << endl;
        cin >> winner;
    
        if (cin.fail())
        {
            cin.clear();
            string ignore;
            cin >> ignore;
            cout << "INVALID INPUT\n\n";
        }
        else if (winner != RESTAURANT1 && winner !=RESTAURANT2)
        {
            cout << "INVALID INPUT\n\n";
        }
        else if (winner == RESTAURANT1)
        {
            winning_restaurant = restaurant1;
            invalid = false;
        }
        else
        {
            winning_restaurant =restaurant2;
            invalid = false;
        }
    }
    
    return winning_restaurant;
}


/* *****************************************************************************
 beginTournament()
 
 DESCRIPTION - This function will display 2 random restaurants from the vector and prompt the user to choose one. It will continue to do this until every restaurant has been displayed. The function will put all the restaurants the user chose into a "winners bracket." The function will continue to prompt the user to choose a restaurant until one restaurant is left.
 
 PARAMETERS/INPUTS:
 @restaurants - This vector parameter contains all the restaurants eligble for the tournament.
 
 RETURNS - The function does not return a value, however it alters the size of the vector to just one restaurant.
 
 ***************************************************************************** */

void beginTournament(vector<string>& restaurants)
{
    
    int size=0, match=1, rounds=1, total_matches=0;
    int total_rounds=0;
    vector<string> winners_bracket;
    size = restaurants.size();
    
    total_rounds = (log10(size)) / (log10(2));

    total_matches = restaurants.size() / 2;
    
    
        while (restaurants.size() > 0)
        {

            string rand_restaurant1, rand_restaurant2;
            
            rand_restaurant1 = getRandomRestaurant(restaurants);
            rand_restaurant2 = getRandomRestaurant(restaurants);
            
            while (rand_restaurant2 == rand_restaurant1)
            {
                rand_restaurant2 = getRandomRestaurant(restaurants);
            }
            
            string winner;
            cout << "\nMatch: " << match << "/" << total_matches << endl;
            cout << "Round: " << rounds << "/" << total_rounds << endl;
            winner = getWinner(rand_restaurant1, rand_restaurant2);
            
            winners_bracket.push_back(winner);
            
            removeRestaurant(restaurants, rand_restaurant1);
            removeRestaurant(restaurants, rand_restaurant2);
            
            match++;
        }
    
    while (winners_bracket.size() >1)
    {
    beginTournament(winners_bracket);
    rounds++;
    }
    
    displayRestaurants(winners_bracket);

}



int main()
{
    vector<string> restaurants;
    restaurants.push_back("Cafe Rio");
    restaurants.push_back("Zupas");
    restaurants.push_back("Panda Express");
    restaurants.push_back("Pizza Hut");
    restaurants.push_back("Betos");
    restaurants.push_back("Dairy Queen");
    restaurants.push_back("Firehouse Subs");
    restaurants.push_back("Smash Burger");
    
    srand(time(0));
    
    int choice = 0;
    string restaurant_to_remove;
    bool removed;
    bool play = true;
    bool valid = true;
    while (play == true)
    {
        choice = menu();
        cin.ignore();
        switch (choice)
        {
            case 1: displayRestaurants(restaurants); break;
                
            case 2: addRestaurant(restaurants); break;
                
            case 3: cout << "What is the name of the restaurant you want to remove? ";
                    getline(cin,restaurant_to_remove);
                    removed = removeRestaurant(restaurants,restaurant_to_remove);
                    if (removed)
                    {
                        cout << endl << restaurant_to_remove << " was removed from the tournament\n";
                    }
                    else
                    {
                        cout << "That restaurant is not in the tournament!\n";
                    }
                    break;
            
            case 4: shuffleRestaurants(restaurants); break;
                
            case 5: valid = isNumRestaurantsValid(restaurants);
                    if (!valid)
                    {
                        break;
                    }
                    else
                    {
                        beginTournament(restaurants);
                        cout << "is the winner!\n";
                        play = false;
                        break;
                    }
                
            case 6: play=false; break;
                
            default: if (cin.fail())
                    {
                        cout << "INVALID ENTRY\n\n";
                        cin.clear();
                        string ignore;
                        cin >> ignore;
                    }
                    else
                    {
                        cout << "INVALID ENTRY\n\n";
                    }
                    break;
        }
    
    }
    
    return 0;
}

