/* *****************************************************************************

CS 142 - Winter 2015
Midterm 1 - Yahtzee

Student Name (First and Last):
Student NetID:
Section and Instructor:
Development Platform (e.g. Visual Studio Express 2013" or "XCode"):

***************************************************************************** */



#include <iostream>
#include <string>

#include "YahtC++.h"

using namespace std;


// Some constants that you may find useful
const char CHAR_YES = 'Y';
const char CHAR_NO = 'N';
const int  TURNS_PER_GAME = 13;
const int  SIDES_PER_DIE = 6;





/* *****************************************************************************
 GETYN()
 
 DESCRIPTION - This function prompts the user for input in the form of either a
 'Y' or an 'N'.  Your program should accept either upper- or
 lower-case Y and N.  Any other character that's given as input is
 invalid and your program should continue to prompt the user until
 a valid input character (a Y or an N) is received.
 
 PARAMETERS/INPUTS:
 @PROMPT - This string parameter is used as the display prompt for the user.
 For example, if prompt has the value "Do you want to quit?", then
 the program will display "Do you want to quit? [Y/N]: " and wait
 for user input.
 
 RETURNS - Either an upper-case 'Y' or an 'N'
 
 ***************************************************************************** */

char getYN(string prompt)
{
    cout << prompt;
    char answer;
    bool valid = true;
    do
    {
        cout << "[Y/N] ";
        cin >> answer;
        if (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
        {
            cout << "INVALID ANSWER\n";
            valid = false;
        }
        else if (answer == 'y' || answer == 'Y')
        {
            answer = CHAR_YES;
            valid = true;
        }
        else if (answer == 'n' || answer == 'N')
        {
            answer = CHAR_NO;
            valid = true;
        }
    }
    while (!valid);
    
    return answer;

}

/* *****************************************************************************
GETCHARINRANGE()

DESCRIPTION - This function prompts the user for input in the form of a single
              character in a specified range.  Your program should accept either
			  upper- or lower-case characers, but always return upper case.  If
			  the character that's given by the user is in the specified range
			  (you may assume that the input characters are upper-case), then
			  then it should return it (return the upper-case version if a
			  lowe-case character was entered).  If the input is not in the
			  valid range, then your program should continue to prompt the user
			  until a valid input character (in the correct range) is received.

PARAMETERS/INPUTS:
    @MIN -    An upper-case character that begins the valid range.
	@MAX -    An upper-case character that ends the valid range.

RETURNS -     An upper-case character in the specified range.


***************************************************************************** */

char getCharInRange(char min, char max)
{
    bool valid = true;
    char choice;
    
    do
    {

        cin >> choice;
        switch (choice)//switches to uppercase if lowercase
        {
            case 'a': choice = 'A'; break;
            case 'b': choice = 'B'; break;
            case 'c': choice = 'C'; break;
            case 'd': choice = 'D'; break;
            case 'e': choice = 'E'; break;
            case 'f': choice = 'F'; break;
            case 'g': choice = 'G'; break;
            case 'h': choice = 'H'; break;
            case 'i': choice = 'I'; break;
            case 'j': choice = 'J'; break;
            case 'k': choice = 'K'; break;
            case 'l': choice = 'L'; break;
            case 'm': choice = 'M'; break;
            case 'n': choice = 'N'; break;
            case 'o': choice = 'O'; break;
            case 'p': choice = 'P'; break;
            case 'q': choice = 'Q'; break;
            case 'r': choice = 'R'; break;
            case 's': choice = 'S'; break;
            case 't': choice = 'T'; break;
            case 'u': choice = 'U'; break;
            case 'v': choice = 'V'; break;
            case 'w': choice = 'W'; break;
            case 'x': choice = 'X'; break;
            case 'y': choice = 'Y'; break;
            case 'z': choice = 'Z'; break;
        }
        if (choice >= min && choice <= max)
        {
            valid = true;
        }
        else
        {
            valid = false;
        }
        
    }
    while (!valid);

    return choice;
}

/* *****************************************************************************
ISVALIDOPTION_YAHTZEE()

DESCRIPTION - This function determines whether the values on the five dice
              passed in as parameters constitute a YAHTZEE (all five dice have
			  an identical value).  For example, the values 2 2 2 2 2 represent
			  a YAHTZEE.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS - Either TRUE (if the values are all identical) or FALSE (otherwise).

***************************************************************************** */

bool isValidOption_YAHTZEE(int die1, int die2, int die3, int die4, int die5)
{
    bool yahtzee = true;
    if (die1 == die2 && die2 == die3 && die3 == die4 && die4 == die5)
    {
        yahtzee = true;
    }
    else
    {
        yahtzee = false;
    }
    
    return yahtzee;
}

/* *****************************************************************************
ISVALIDOPTION_SMSTRAIGHT()

DESCRIPTION - This function determines whether there is a small straight.  For
              example if the dice values were 2 5 4 3 4, there is a small
			  straight 2-3-4-5 present.  Any sequence of four consecutive
			  values (each in the range 1-6) is a small straight.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if a small straight is present in the dice) or
              FALSE (otherwise).

***************************************************************************** */

bool isValidOption_SmStraight(int die1, int die2, int die3, int die4, int die5)
{
    bool small_straight = false, one_die = false, two_die = false,
    three_die = false, four_die = false, five_die = false, six_die = false;
    
    switch(die1)
    {
        case 1: one_die = true; break;
        case 2: two_die =  true; break;
        case 3: three_die = true; break;
        case 4: four_die = true; break;
        case 5: five_die = true; break;
        case 6: six_die = true; break;
    }
    switch(die2)
    {
        case 1: one_die = true; break;
        case 2: two_die =  true; break;
        case 3: three_die = true; break;
        case 4: four_die = true; break;
        case 5: five_die = true; break;
        case 6: six_die = true; break;
    }
    switch(die3)
    {
        case 1: one_die = true; break;
        case 2: two_die =  true; break;
        case 3: three_die = true; break;
        case 4: four_die = true; break;
        case 5: five_die = true; break;
        case 6: six_die = true; break;
    }
    switch(die4)
    {
        case 1: one_die = true; break;
        case 2: two_die =  true; break;
        case 3: three_die = true; break;
        case 4: four_die = true; break;
        case 5: five_die = true; break;
        case 6: six_die = true; break;
    }
    switch(die5)
    {
        case 1: one_die = true; break;
        case 2: two_die =  true; break;
        case 3: three_die = true; break;
        case 4: four_die = true; break;
        case 5: five_die = true; break;
        case 6: six_die = true; break;
    }
    if (one_die == true && two_die == true && three_die == true && four_die == true)
    {
        small_straight = true;
    }
    else if (two_die == true && three_die == true && four_die == true && five_die == true)
    {
        small_straight = true;
    }
    else if (three_die == true && four_die == true && five_die == true && six_die == true)
    {
        small_straight = true;
    }
    else
    {
        small_straight = false;
    }
    
    return small_straight;
}

/* *****************************************************************************
ISVALIDOPTION_3OFAKIND()

DESCRIPTION - This function determines whether there are 3 (or more) dice that
              have the same value.  For example if the dice values were
			  2 5 5 1 5, there is a 3-of-a-kind, the fives.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if 3 or more dice have the same value) or
              FALSE (otherwise).

***************************************************************************** */
bool isValidOption_3OfAKind(int die1, int die2, int die3, int die4, int die5)
{
    bool three_of_a_kind;
    int counter = 0;
    
    if (die1 == die2)
    {
        counter++;
    }
    if (die1 == die3)
    {
        counter++;
    }
    if (die1 == die4)
    {
        counter++;
    }
    if (die1 == die5)
    {
        counter++;
    }
    
    if (die2 == die3)
    {
        counter++;
    }
    if (die2 == die4)
    {
        counter++;
    }
    if (die2 == die5)
    {
        counter++;
    }
    
    if (die3 == die4)
    {
        counter++;
    }
    if (die3 == die5)
    {
        counter++;
    }
    
    if (counter >= 3)
    {
        three_of_a_kind = true;
    }
    else
    {
        three_of_a_kind = false;
    }
    
    return three_of_a_kind;
}

/* *****************************************************************************
POINTSFOR_SIXES()

DESCRIPTION - This function computes the number of points for sixes.  If two
              dice show sixes, then this would return 12, if four dice show
			  sixes, then this function would return 24, and so forth.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     The total of all dice showing a six (an int).

***************************************************************************** */

int pointsFor_Sixes(int die1, int die2, int die3, int die4, int die5)
{
    int total_points = 0;
    int counter = 0;
    if (die1 ==6)
    {
        counter ++;
    }
    if (die2 ==6)
    {
        counter++;
    }
    if (die3 ==6)
    {
        counter++;
    }
    if (die4 ==6)
    {
        counter++;
    }
    if (die5 == 6)
    {
        counter++;
    }
    
    total_points = counter * 6;
    
    return total_points;
}

