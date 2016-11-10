//TEST CASES
// input 't' should tell me "INVALID SELECTION" and return me to the menu.
//
// input '1' should ask me what slot 0-8 I want to drop my chip into.
//      input '0' slot, the position of the chip should never drop below 0,
//      and should increment by .5 at each location,
//      and output the prize money associated with the last position of the chip.
//
//input '2' should prompt me to enter a number of chips,
//      and then prompt me to drop them into a slot 0-8.
//      if input 9 for chips, and a valid slot (0-8),
//      then the average money won per chip should have a decimal,
//      and the total money won could be a large range of numbers
//      from a couple thousand to tens of thousands, depending on where the chips fall.
//
//input '3' should prompt me to enter a number of chips
//      if input 2 for chips then at each slot the average winnings should be half the total winnings
//
//input '4' should quit the program.


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

bool chipCheck(int chip)
{
    bool valid = true;
    if (cin.fail())
    {
        cin.clear();
        string ignore;
        cin >> ignore;
        valid = false;
    }
    else if (chip < 1)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    return valid;
}

bool slotCheck(double slot)
{
    bool valid = true;
    if (cin.fail())
    {
        cin.clear();
        string ignore;
        cin >> ignore;
        valid = false;
    }
    else if (slot < 0 || slot > 8)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    return valid;
}

double getPrizeMoney(double final_position)
{
    const int PRIZE_MONEY_0_8 = 100;
    const int PRIZE_MONEY_1_7 = 500;
    const int PRIZE_MONEY_2_6 = 1000;
    const int PRIZE_MONEY_3_5 = 0;
    const int PRIZE_MONEY_4 = 10000;
    
    int prize_money =0;
    
    if (final_position == 0 || final_position == 8)
    {
        prize_money = PRIZE_MONEY_0_8;
    }
    else if (final_position == 1 || final_position == 7)
    {
        prize_money = PRIZE_MONEY_1_7;
    }
    else if (final_position == 2 || final_position == 6)
    {
        prize_money = PRIZE_MONEY_2_6;
    }
    else if (final_position == 3 || final_position == 5)
    {
        prize_money = PRIZE_MONEY_3_5;
    }
    else
    {
        prize_money = PRIZE_MONEY_4;
    }
    
    return prize_money;
}

double plinkoSimulator(double slot, int menu_selection)
{
    const int ROWS_ON_BOARD =12;
    const int ONE_CHIP =1;
    double position=0;
    position = slot;
    
    for (int i=0; i <ROWS_ON_BOARD; i++)//runs 12 times
    {
        int randPeg;
        randPeg = rand() % 2 + 1;
        
        if (randPeg ==1)
        {
            position -= .5;
            if (position < 0)
            {
                position += 1;
            }
        }
        else
        {
            position += .5;
            if (position >8)
            {
                position -= 1;
            }
        }
        if ( menu_selection == ONE_CHIP)//if menu selection "1" print position of chip
        {
            if ( i < (ROWS_ON_BOARD - 1))
            {
                cout << position << " ";
            }
            else
            {
                cout << position << "]";
            }
        }
    }
    return position;
}

double oneChipSimulation(double slot)
{
    const int ONE_CHIP=1;
    double position=0;
    position = slot;
    srand((unsigned int)time(0));
    double last_position = 0;
    
    cout << "Path: [" << fixed << setprecision(1) << position << " ";
    last_position = plinkoSimulator(position, ONE_CHIP);

    return last_position;
}

double multipleSimulations(int chips, double slot)
{
    const int MULTIPLE_CHIPS = 2;
    double final_position = 0;
    double total_prize_money = 0;
    double prize_money=0;
    
    for (int i=0; i < chips; i++)//run as many times as there are chips
    {
        final_position = plinkoSimulator(slot, MULTIPLE_CHIPS);//simulates plinko, returns last position
        prize_money = getPrizeMoney(final_position);// grabs the prize money associated with last position
        total_prize_money += prize_money;// running total
    }
    return total_prize_money;
}

void simulateAllChips(int chips)
{
    double average_money_per_chip=0;
    double total_prize_money=0;

    for (double slot=0; slot <=8; slot++)
    {
        
        total_prize_money = multipleSimulations(chips, slot);
        average_money_per_chip = total_prize_money / chips;
        cout << "Slot " << setprecision(0) << slot << ":\n";
        cout << "Total Winnings: $" << fixed << setprecision(2) << total_prize_money << endl
             << "Average Winnings Per Chip: $" << average_money_per_chip << endl << endl;
    }

}

int main()
{
    int menu_choice= 0;
    const int ONE_CHIP = 1;
    const int MULTIPLE_CHIPS = 2;
    const int MULTIPLE_SLOTS = 3;
    const int QUIT = 4;
    
    do
    {
        cout << "PLINKO MENU\n";
        cout << "Please enter one of the following:\n";
        cout << "1 - Drop one chip into a slot\n";
        cout << "2 - Drop multiple chips into a slot\n";
        cout << "3 - Drop a number of chips into all slots\n";
        cout << "4 - QUIT\n";
        cin >> menu_choice;
        cout << endl;
        
        if (cin.fail())
        {
            cin.clear();
            string ignore;
            cin >> ignore;
            cout << "INVALID SELECTION\n\n";
            
        }
        else if( menu_choice == ONE_CHIP)
        {
            cout << "SINGLE\n";
            cout << "Please choose a slot 0-8 to drop your chip ";
            
            double slot=0;
            cin >> slot;

            bool valid=0;
            valid = slotCheck(slot);
            if (!valid)
            {
                cout << endl << "INVALID SLOT\n\n";
            }
            else
            {
                double finalPosition = oneChipSimulation(slot);
                double winnings = getPrizeMoney(finalPosition);
                
                cout << "\nYou won $" << fixed << setprecision(2) << winnings << endl << endl;
            }
        }
        else if (menu_choice == MULTIPLE_CHIPS)
        {
            cout << "MULTIPLE\n";
            cout << "How many chips do you want to drop? ";
            
            int chips=0;
            cin >> chips;
            
            bool valid;
            valid = chipCheck(chips);
            
            if (!valid)//invalid input
            {
                cout << endl << "INVALID NUMBER OF CHIPS\n\n";
            }
            else//chips valid
            {
                cout << "Please choose a slot 0-8 to drop your chip ";
                
                double slot=0;
                cin >> slot;
                
                bool valid=0;
                valid = slotCheck(slot); // invalid slot
                if (!valid)
                {
                    cout << endl << "INVALID SLOT\n\n";
                }
                
                else // slot valid, execute program
                {
                    double total_prize_money =0;
                    total_prize_money =  multipleSimulations(chips, slot);
                    
                    double average_money_per_chip = 0;
                    average_money_per_chip = total_prize_money / chips;
                    
                    cout << endl << "Your total prize money is $" << fixed << setprecision(2)
                         << total_prize_money << endl;
                    
                    cout << "Your average winnings per chip is $" << fixed << setprecision(2)
                         <<average_money_per_chip << endl << endl;
                }
            }
        }
        else if (menu_choice == MULTIPLE_SLOTS)
        {
            cout << "How many chips would you like to drop? ";
            
            int chips =0;
            cin >> chips;
            cout << endl;
            
            bool valid;
            valid = chipCheck(chips);
            
            if (!valid)
            {
                cout << endl << "INVALID NUMBER OF CHIPS\n\n";
            }
            else
            {
                simulateAllChips(chips);
            }
        }
        else if (menu_choice > QUIT || menu_choice < 0)
        {
            cout << "INVALID SELECTION\n\n";
        }
        
    }
    while (menu_choice != QUIT);
    cout << "GOODBYE\n";
    return 0;
}