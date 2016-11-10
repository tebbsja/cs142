
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;
//DOES IT COST MONEY TO PAINT CAR?

/* TEST CASES
 1) input 8 should quit program
 2) input 6, enter "/Users/Austin/Downloads/lab8/cars1.txt" , input 1 to display cars in inventory. 
        "Name: Jalopy
        Color: Blue
        Price: $3402.99
 
        Name: Rustbucket
        Color: Brown
        Price: $44.99
 
        Name: Lemon
        Color: Yellow
        Price: $4226.99
    
    input 2 to display balance should print out "$10529.23"
    input 5 - paint car - ask for name of car
        input Jalopy, ask for color to paint
        input pink - should raise price of Jalopy to $4402.99
 
        ******does it cost money to paint?!? if so balance should be $9529.23******
                            -THIS IS HOW I CODED IT
 
    input 7 - enter "/Users/Austin/Desktop/isthisworking.txt"
        should create a txt file on desktop that reads:
            9529.23
            Jalopy pink 4402.99
            Rustbucket Brown 44.99
            Lemon Yellow 4226.99
    input 8 - quit
 
 3) input 3 - buy a car - should prompt for name, color, and price
        Name: ford
        Color: pink
        Price: 5000
 
    input 2 - display balance - "$5000.00"
    input 4 - sell car - should prompt for name of car to sell
        input chevy - should tell me that car isn't in the inventory
    input 4 - prompt for name of car
        input ford
        should remove car from vector and add the price of the car to balance
    input 2 - display balance - "$10000.00"
    input 8 - quit
 
 */

/* *****************************************************************************
 searchInventory()
 
 DESCRIPTION - This function searches the vector of cars for a user given name of a car.
 
 PARAMETERS:
 @cars - This vector parameter includes the current inventory of cars.
 @name_of_car - This string is the name of the car to search for in the vector.
 
 RETURNS - The function returns the index of the car if it was found in the vector. If it is not found it will return -1;
 ***************************************************************************** */
int searchInventory(vector<Car> cars, string name_of_car)
{
    int index = -1;
    
    for (int i=0; i < cars.size(); i++)// perform this for size of vector
    {
        if (name_of_car == cars[i].getName())
        {
            index = i;
        }
    }
    
    return index;
}

/* *****************************************************************************
 displayInventory()
 
 DESCRIPTION - This function prints out all of the cars, along with their color and price.
 
 PARAMETERS:
 @cars - This vector contains all the cars to be displayed.
 
 RETURNS - Nothing, the function is void.
 ***************************************************************************** */
void displayInventory(vector<Car> cars)
{
    for (int i=0; i < cars.size(); i++)
    {
        cout << cars[i].toString() << endl;
    }
}
/* *****************************************************************************
 menu()
 
 DESCRIPTION - This function prompts the user for an option, 1-8. If the selection isn't valid, the functioin will continue to prompt.
 
 RETURNS - an integer 1-8 depending on the choice.
 ***************************************************************************** */
int menu()
{
    int selection;
    bool valid =true;
    
    do
    {
        cout << "Please select an option:\n";
        cout << "1) Show Current Inventory\n";
        cout << "2) Show Current Balance\n";
        cout << "3) Buy a Car\n";
        cout << "4) Sell a Car\n";
        cout << "5) Paint a Car\n";
        cout << "6) Load File\n";
        cout << "7) Save File\n";
        cout << "8) Quit Program\n";
    
        cin >> selection;
        
        if (cin.fail())
        {
            cin.clear();
            string ignore;
            cin >> ignore;
            cout << "INVALID OPTION\n\n";
            valid = false;
        }
        else if (selection < 1 || selection > 8)
        {
            cout << "INVALID OPTION\n\n";
            valid = false;
        }
        else
        {
            valid = true;
        }
        
    }
    while (!valid);

    return selection;
}
/* *****************************************************************************
 buyCar()
 
 DESCRIPTION - This function will check to see if the car is already in the inventory. If it is, the car will not be purchased. If the car is worth more than the total balance of the dealership, the car will not be purchased. Otherwise, the car will be purchased, and put into the inventory.
 
 PARAMETERS:
 @car_name - The name of the car to be purchased
 @car_color - The color of the car
 @price - The price of the car
 @balance - The current balance of the dealership
 @cars - The inventory of cars
 
 RETURNS - The total balance of the dealership after purchasing a car.
 ***************************************************************************** */
double buyCar(string car_name, string car_color, double price, double balance, vector<Car> &cars)
{
    double updated_balance = 0;
    int found =0;
    found = searchInventory(cars, car_name);
    
    if ( price > balance)
    {
        cout << "YOU DO NOT HAVE ENOUGH MONEY FOR THIS CAR\n\n";
        updated_balance = balance;
    }
    else if (found != -1)
    {
        cout << "THIS CAR IS ALREADY IN YOUR INVENTORY\n\n";
        updated_balance = balance;
    }
    else
    {
        updated_balance = balance - price;
        Car car_purchased(car_name,car_color,price);
        cars.push_back(car_purchased);
    }
    
    return updated_balance;
}

/* *****************************************************************************
 sellCar()
 
 DESCRIPTION - This function checks to see if a car is in the inventory, if it does it will sell the car, removing it from the inventory and adding the price of the car to the balance.
 
 PARAMETERS:
 @cars - The cars in the inventory
 @car_name - The name of the car to be sold
 @balance - The current balance of the dealership
 
 RETURNS - The balance after selling a car.
 ***************************************************************************** */
double sellCar(vector<Car> &cars, string car_name, double balance)
{
    double updated_balance=0;
    
    int last_pos=0;
    last_pos = cars.size() - 1;
    
    int found=0;
    found = searchInventory(cars, car_name);
    
    if (found == -1)
    {
        cout << "THAT CAR IS NOT IN YOUR INVENTORY\n\n";
        updated_balance = balance;
    }
    else
    {
        updated_balance = balance + cars[found].getPrice();
        cars[found] = cars[last_pos];
        cars.pop_back();
    }
    
    return updated_balance;
}
/* *****************************************************************************
 paintCar()
 
 DESCRIPTION - This function paints a car in the inventory a given color.
 
 PARAMETERS:
 @cars - The current inventory of cars
 @car_name - The name of the car to be painted
 @color - The color the car will be painted
 @balance - The balance of the dealership
 
 RETURNS - The balance of the dealership after painting a car.
 ***************************************************************************** */
double paintCar(vector<Car> &cars, string car_name, string color, double balance)
{
    const int AMOUNT_TO_PAINT_CAR = 1000;
    double updated_balance=0;
    int found=0;
    found = searchInventory(cars, car_name);

    if (found == -1)
    {
        cout << "THAT CAR IS NOT IN YOUR INVENTORY\n\n";
        updated_balance = balance;
    }
    else if (AMOUNT_TO_PAINT_CAR > balance)
    {
        cout << "YOU DO NOT HAVE ENOUGH MONEY TO PAINT THIS CAR\n\n";
        updated_balance = balance;
    }
    else
    {
        cars[found].paint(color);
        updated_balance = balance - AMOUNT_TO_PAINT_CAR;
    }
    
    return updated_balance;
}
/* *****************************************************************************
 loadFile()
 
 DESCRIPTION - This function loads a file and puts the cars from the file into the inventory.
 
 PARAMETERS:
 @file - the name of the file to load
 @cars - the inventory of cars
 @balance - the balance of the dealership
 
 RETURNS - The updated balance with all the cars from the file in the inventory.
 ***************************************************************************** */
double loadFile(string file, vector<Car> &cars, double balance)
{
    string name, color, line;
    double price =0, add_to_balance=0, loaded_balance =0, updated_balance=0;
    ifstream in_file;
    string number;
    in_file.open(file.c_str());
    
    while (!in_file.eof())
    {
        istringstream from_text(line);
        getline(in_file, line);
        
        from_text.str(line);
        
        from_text >> add_to_balance;

        updated_balance = balance + add_to_balance;
        
        if (in_file >> name >> color >> price)
        {
            Car tempCar(name,color,price);
            cars.push_back(tempCar);
        }

    }

    in_file.close();
    return updated_balance;
}
/* *****************************************************************************
 saveFile()
 
 DESCRIPTION - This function saves the inventory to a file.
 
 PARAMETERS:
 @name - The name of the file to save
 @cars - The inventory of cars
 
 RETURNS - Nothing, the function is void.
 ***************************************************************************** */
void saveFile(string name, vector<Car> cars, double balance)
{
    ofstream output;
    
    output.open(name.c_str());
    
    output << fixed << setprecision(2) << balance << endl;
    for (int i=0; i < cars.size(); i++)
    {
        output << cars[i].getName() << " " << cars[i].getColor() << " " << fixed << setprecision(2) << cars[i].getPrice() << endl;
    }
    
    output.close();
}

int main()
{
    double balance = 10000;
    bool running = true;
    vector<Car> cars;
    while (running)
    {
        int option = 0;
        option = menu();
        cin.ignore();
        switch (option)
        {
            case 1:
                displayInventory(cars);
                break;
            case 2:
                cout << fixed << setprecision(2) << "Your balance is: $" << balance << endl << endl;
                break;
            case 3:
            {
                cout << "What is the name of the car you want to buy?: ";
                string car_to_buy;
                getline(cin,car_to_buy);
                cout << endl << "What color is the car?: ";
                string color;
                getline(cin,color);
                cout << endl << "How much is the car?: ";
                double price;
                cin >> price;
                balance = buyCar(car_to_buy,color,price,balance,cars);
                break;
            }
            case 4:
            {
                cout << "What is the name of the car you want to sell?: ";
                string car_to_sell;
                getline(cin,car_to_sell);
                balance = sellCar(cars,car_to_sell, balance);
                break;
            }
            case 5:
            {
                cout << "What is the name of the car you want to paint?: ";
                string car_to_paint;
                getline(cin,car_to_paint);
                cout << "What color do you want to paint the car?: ";
                string color;
                getline(cin,color);
                balance = paintCar(cars,car_to_paint,color,balance);
                break;
            }
            case 6:
            {
                cout << "What is the name of the file you want to load?: ";
                string file;
                getline(cin,file);
                balance = loadFile(file, cars, balance);
                break;
            }
            case 7:
            {
                cout << "What do you want to save the file as?: ";
                string file;
                getline(cin,file);
                saveFile(file,cars,balance);
               
                break;
            }
            case 8: running = false; break;
        }
    
    }
    
    return 0;
}
