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
//input '3' should quit the program.


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int menu_choice= 0;
    srand((unsigned int)time(0));
    const int LEFT = 1;
    const int QUIT = 3;
    const int ONE_CHIP = 1;
    const int MULTIPLE_CHIPS = 2;
    const int ROWS_ON_BOARD = 12;
    const double PRIZE_MONEY_0_8 = 100;
    const double PRIZE_MONEY_1_7 = 500;
    const double PRIZE_MONEY_2_6 = 1000;
    const double PRIZE_MONEY_3_5 = 0;
    const double PRIZE_MONEY_4 = 10000;
    
   do
   {
       cout << "PLINKO MENU\n";
       cout << "Please enter one of the following:\n";
       cout << "1 - Drop one chip into a slot\n";
       cout << "2 - Drop multiple chips into a slot\n";
       cout << "3 - Quit\n";
       cin >> menu_choice;
       cout << endl;
       
       if (cin.fail())
       {
           cin.clear();
           cin.ignore();
           cout << "INVALID SELECTION\n\n";
           
       }
       
       else if( menu_choice == ONE_CHIP)
       {
           cout << "SINGLE\n";
           double slot=0;
           cout << "Please choose a slot 0-8 to drop your chip ";
           cin >> slot;
           cout << endl;
           
           if (cin.fail())
           {
               cin.clear();
               cin.ignore();
               cout << "INVALID SLOT\n\n";
           }
           else if (slot < 0 || slot > 8)
           {
               cout << "INVALID SLOT\n\n";
           }
           else
           {
               double current_position = slot;
               cout << "PATH: " << "[" << fixed << setprecision(1) << slot << " ";
               for (int i=0; i < ROWS_ON_BOARD; i++)
               {
                   
                   int rpeg;
                   rpeg = rand() % 2 + 1;
                   
                   
                   if (rpeg == LEFT)
                   {
                       current_position -=  .5;
                       if (current_position < 0)
                       {
                           current_position += 1;
                       }
                   }
                   else
                   {
                       current_position += .5;
                       if (current_position > 8)
                       {
                           current_position -= 1;
                       }
                   }
                   if (i < (ROWS_ON_BOARD - 1))
                   {
                       cout << fixed << setprecision(1) << current_position << " ";
                   }
                   else
                   {
                   cout << fixed << setprecision(1) << current_position;
                   }
               }
               cout << "]" << endl;
               cout << endl << "WINNINGS: $";
               
               if (current_position == 0 || current_position == 8)
               {
                   cout << fixed << setprecision(2) << PRIZE_MONEY_0_8 << endl;
               }
               else if (current_position == 1 || current_position == 7)
               {
                   cout << fixed << setprecision(2) << PRIZE_MONEY_1_7 << endl;
               }
               else if (current_position == 2 || current_position == 6)
               {
                   cout << fixed << setprecision(2) << PRIZE_MONEY_2_6 << endl;
               }
               else if (current_position == 3 || current_position == 5)
               {
                   cout << fixed << setprecision(2) << PRIZE_MONEY_3_5 << endl;
               }
               else
               {
                   cout << fixed << setprecision(2) << PRIZE_MONEY_4 << endl;
               }
               
               cout << endl;
           }
       }
       else if (menu_choice == MULTIPLE_CHIPS)
       {
           cout << "MULTIPLE\n";
           cout << "How many chips do you want to drop? ";
           
           int chips=0;
           cin >> chips;
           
           if (cin.fail())
           {
               cin.clear();
               cin.ignore();
               cout << endl << "INVALID NUMBER OF CHIPS\n\n" << endl;
           }
           
           else if (chips <= 1)
           {
               cout << endl << "INVALID NUMBER OF CHIPS\n\n" << endl;
           }
           
           else
           {
               int slot=0;
               cout << "Please choose a slot 0-8 to drop your chip ";
               cin >> slot;
               cout << endl;
               
               if (slot < 0 || slot > 8)
               {
                   cout << "INVALID SLOT\n\n" << endl;
               }
               
               else if (cin.fail())
               {
                   cin.clear();
                   cin.ignore();
                   cout << "INVALID SLOT\n\n" << endl;
               }
               
               else
               {
                   double total_prize_money=0;
                   int winnings =0;
                   double average_prize_money=0;
                 
                   for (int i =0; i < chips; i++)
                   {
                         double current_position = slot;
                     
                       for (int i=0; i < ROWS_ON_BOARD; i++)
                       {
                           int rpeg;
                           rpeg = rand() % 2 + 1;
                           
                           if (rpeg == LEFT)
                           {
                               current_position -=  .5;
                               if (current_position < 0)
                               {
                                   current_position += 1;
                               }
                           }
                           else
                           {
                               current_position += .5;
                               if (current_position > 8)
                               {
                                   current_position -= 1;
                               }
                           }
                           
                       }
                  
                       if (current_position == 0 || current_position == 8)
                       {
                           winnings = PRIZE_MONEY_0_8;
                       }
                       else if (current_position == 1 || current_position == 7)
                       {
                           winnings = PRIZE_MONEY_1_7;
                       }
                       else if (current_position == 2 || current_position == 6)
                       {
                           winnings = PRIZE_MONEY_2_6;
                       }
                       else if (current_position == 3 || current_position == 5)
                       {
                           winnings = PRIZE_MONEY_3_5;
                       }
                       else
                       {
                           winnings = PRIZE_MONEY_4;
                       }
                       
                       total_prize_money += winnings;
                   }
                   
                   average_prize_money = total_prize_money / chips;
                   cout << "Your total prize money is $" <<
                   
                        fixed << setprecision(2) << total_prize_money << endl;
                   cout << "Your average prize money per chip is $" << fixed << setprecision(2) << average_prize_money << endl << endl;
               }
               
           }
       }
       else if (menu_choice < 1 || menu_choice > 3)
       {
           cout << "INVALID SELECTION\n\n";
       }
   
   }
    
    while (menu_choice != QUIT);
    cout << "GOODBYE\n";
    return 0;
}

