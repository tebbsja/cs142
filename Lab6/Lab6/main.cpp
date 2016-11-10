#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/* *****************************************************************************
 printHotPlate()
 
 DESCRIPTION - This function prints out the values in a 2D array.
 
 PARAMETERS:
 @current_temperature - This array parameter is the array to be printed out.
 
 RETURNS - Nothing, the function is void.
 
 ***************************************************************************** */

void printHotPlate(double current_temperature[][20])
{
    const int ROWS = 20, COLUMNS = 20;
    
    for (int i=0; i < ROWS;i++)
    {
        for (int j=0; j < COLUMNS; j++)
        {
            cout << setw(6) << fixed << setprecision(1) << current_temperature[i][j] << "  ";
        }
        cout << endl << endl;
    }
}

/* *****************************************************************************
 initializeHotPlate()
 
 DESCRIPTION - This function initializes an array. It sets all the values in the middle of the array to 0. The top row and bottom row are set to 100, with the exception of the corners.
 
 PARAMETERS:
 @temperature - This array parameter is the array to be initialized
 
 RETURNS - The function does not return anything. The array paramter is changed.
 
 ***************************************************************************** */

void initializeHotPlate(double temperature[][20])
{
    const int ROWS = 20, COLUMNS = 20;
    const int FIRST_ROW = 0, FIRST_COLUMN = 0;
    const int LAST_ROW = 19, LAST_COLUMN = 19;

    for (int i=0; i < ROWS;i++)
    {
        for (int j=0; j < COLUMNS; j++)
        {
            temperature[i][j] = 0;
            temperature[FIRST_ROW][j] = 100;
            temperature[LAST_ROW][j] = 100;
            temperature[FIRST_ROW][FIRST_COLUMN] = 0;
            temperature[FIRST_ROW][LAST_COLUMN] = 0;
            temperature[LAST_ROW][LAST_COLUMN] = 0;
            temperature[LAST_ROW][FIRST_COLUMN] = 0;

        }
    }
}

/* *****************************************************************************
 averageHotPlate()
 
 DESCRIPTION - This function sets each value equal to the average of its 4 neighbors (top, bottom, left, right)
               at the previous iteration.
 
 PARAMETERS:
 @current_temperature - This array parameter holds the updated current temperatures.
 @previous_temperature - This array paramter holds the previous iteration of temperatures.
 
 RETURNS - Void. The array parameters are changed.
 
 ***************************************************************************** */

void averageHotPlate(double current_temperature[][20], double previous_temperature[][20])
{
    const int ROWS = 20, COLUMNS = 20;
    const int MIDDLE_ROWS = 19;
    const int MIDDLE_COLUMNS = 19;
    const int NEIGHBORS = 4;
    const int UP =1, DOWN=1, LEFT=1, RIGHT=1;

    
    double average=0;

    for (int i=0; i < ROWS; i++) //sets each index of plate2 = plate1
    {
        for (int j=0; j < COLUMNS; j++)
        {
            previous_temperature[i][j] = current_temperature[i][j];
        }
    }

    for (int i=1; i < MIDDLE_ROWS; i++)//row
    {
        for (int j=1; j < MIDDLE_COLUMNS; j++)//column
        {
  
           average = (previous_temperature[i+UP][j] + previous_temperature[i-DOWN][j]
                     + previous_temperature[i][j-LEFT] + previous_temperature[i][j+RIGHT])/ NEIGHBORS;
            current_temperature[i][j] = average;
                                        //find average for each index, replace in array
                                        //after whole array is replaced, plate2 = plate 1
        }
    }
    
}

/* *****************************************************************************
 checkDifferenceDegrees()
 
 DESCRIPTION - This function finds the difference in temperature between the current temperature array and the
               previous iteration of temperatures. As it finds the difference in temperature of each value, the
               function will store the largest difference.
 
 PARAMETERS:
 @current_temperature - This array parameter holds the current temperatures.
 @previous_temperature - This array parameter holds the temperatures from the previous iteration.
 
 RETURNS - The largest difference of temperatures.
 
 ***************************************************************************** */

double checkDifferenceDegrees(double current_temperature[][20], double previous_temperature[][20])
{
    const int MIDDLE_ROWS = 19, MIDDLE_COLUMNS = 19;
 
    double difference =0;
    double largest=0;

    for (int i=1;i<MIDDLE_ROWS;i++)//rows
    {
        for (int j=1;j<MIDDLE_COLUMNS;j++)//columns
        {
            difference =  current_temperature[i][j] - previous_temperature[i][j];
            
            if (difference > largest)
            {
                largest = difference;
            }
        }
    }
    return largest;

}
/* *****************************************************************************
 exportHotPlate()
 
 DESCRIPTION - This function exports the values in the array into a .csv file
 
 PARAMETERS:
 @current_temperature - This array parameter holds the current temperatures.
 
 RETURNS - Nothing, the function is void.
 
 ***************************************************************************** */

void exportHotPlate(double current_temperature[][20])
{
    const int ROWS = 20, COLUMNS = 20;
    
    ofstream output;
    
    output.open("/Users/Austin/Desktop/hotplate.csv");
    
    for (int i=0; i < ROWS;i++)
    {
        
        for (int j=0; j < COLUMNS; j++)
        {
            output << fixed << setprecision(1) << current_temperature[i][j] << ",";
        }
        output << endl;
        
    }
    
    
}
    
int main()
{
    const double STOP = .1;
    const int ROWS = 20, COLUMNS = 20;
    
    double current_temperature[ROWS][COLUMNS];
    initializeHotPlate(current_temperature);
    
    printHotPlate(current_temperature);
    cout << endl << endl;

    double previous_temperature[ROWS][COLUMNS];
    initializeHotPlate(previous_temperature);

    double difference = 0;
    
    do
    {
        averageHotPlate(current_temperature, previous_temperature);
        difference = checkDifferenceDegrees(current_temperature, previous_temperature);
    }
    while (difference > STOP);


    printHotPlate(previous_temperature);
    cout << endl << endl;
    printHotPlate(current_temperature);
    
    exportHotPlate(current_temperature);
    

    
    return 0;
}
