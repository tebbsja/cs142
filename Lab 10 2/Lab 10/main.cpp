#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

/* *****************************************************************************
 findID()
 
 DESCRIPTION - This function gets the property ID for each property.
 
 PARAMETERS:
 @properties - This vector contains all properties
 @adress - This string is the address of the property that corresponds with the unique ID number.
 
 RETURNS - The unique property ID number as an integer.
 ***************************************************************************** */
int findID(vector<Property*> properties, string address)
{
    int uniqueID = 0;
    
    for (int i=0; i < properties.size(); i++)
    {
        if (properties[i]->getAddress() == address)
        {
            uniqueID = i;
        }
    }
    
    return uniqueID;
}

/* *****************************************************************************
 printTaxReport()
 
 DESCRIPTION - This function prints out the tax report for all of the properties.
 
 PARAMETERS:
 @properties - This vector contains all of the properties to be included in the tax report.
 
 RETURNS - nothing
 ***************************************************************************** */
void printTaxReport(vector<Property*> properties)
{
    cout << "NOW PRINTING TAX REPORT:\n\n";
    
    for (int i=0; i < properties.size(); i++)
    {
        cout << "** Taxes due for the property at: " << properties[i]->getAddress() << endl << endl;
        cout << "\t\tProperty ID: " <<  setw(50) << properties[i]->getPropertyID() << endl << endl;
        cout << "\t\tThis property has an estimated value of:" << setw(23) << properties[i]->getPrice();
        cout << endl << endl;
        cout << "\t\tTaxes due for this property:"<< setw(35) << properties[i]->taxesDue() << endl << endl;
    }
}

/* *****************************************************************************
 checkInput()
 
 DESCRIPTION - This function checks what type of error was in the input.
 
 PARAMETERS:
 @line_to_check - This is the line of input that contains an error
 
 RETURNS - nothing
 ***************************************************************************** */
void checkInput(string line_to_check)
{
    istringstream check_input(line_to_check);
    string first_word;
    
    check_input >> first_word;
    if (first_word == "Residential")
    {
        cout << "Ignoring invalid RESIDENTIAL type in input file: " << line_to_check << endl << endl;
    }
    else if (first_word == "Commercial")
    {
        cout << "Ignoring invalid COMMERCIAL type in input file: " << line_to_check << endl << endl;
    }
    else if (first_word == "")
    {
    }
    else
    {
        cout << "Ignoring unknown types of properties in input file: " << line_to_check << endl << endl;
    }
}

/* *****************************************************************************
 printValidProperties()
 
 DESCRIPTION - This function displays all of the valid properties.
 
 PARAMETERS:
 @properties - This vector contains all of the properties.
 
 RETURNS - nothing
 ***************************************************************************** */
void printValidProperties(vector<Property*> properties)
{
    cout << "ALL VALID PROPERTIES: \n\n";
    
    for (int i=0; i < properties.size(); i++)
    {
        cout << properties[i]->toString() << endl;
    }
}

/* *****************************************************************************
 processInput()
 
 DESCRIPTION - This function checks to see if the file exists, if it does, it will process the input and create either a Residential object or Commercial obejct and put it into a vector of properties
 
 PARAMETERS:
 @file - This is the name of the file to be opeend.
 @properties - This is the vector to put Commercial and Residential items into.
 
 RETURNS - a boolean value, validFile, true if it is valid, or false if it is not valid.
 ***************************************************************************** */
bool processInput(string file, vector<Property*> & properties)
{
    string line, res_or_com, address;
    int uniqueID = 0;
    bool rental, occupied, discount, validFile;
    double price = 0, tax_rate = 0;
    
    ifstream in_file;
    in_file.open(file.c_str());
    
    if (in_file.fail())
    {
        cout << "ERROR! THE FILE: " << file << " WAS NOT FOUND\n\n";
        validFile = false;
    }
    else
    {
        validFile = true;
        while (!in_file.eof())
        {
            getline(in_file, line);
            istringstream from_text(line);
            
            if (from_text >> res_or_com >> rental >> price)
            {
                if (res_or_com == "Residential")
                {
                    if (from_text >> occupied)
                    {
                        getline(from_text, address);
                        Residential* newResidential = new Residential(address,rental,occupied,price);
                        properties.push_back(newResidential);
                        uniqueID = findID(properties,newResidential->getAddress());
                        newResidential->setID(uniqueID);
                    }
                    else
                    {
                        checkInput(line);
                    }
                }
                else if (res_or_com == "Commercial")
                {
                    if (from_text >> discount)
                    {
                        if (from_text >> tax_rate)
                        {
                            getline(from_text, address);
                            
                            Commercial* newCommercial =
                            new Commercial(address,rental,discount,price,tax_rate);
                            
                            properties.push_back(newCommercial);
                            uniqueID = findID(properties,newCommercial->getAddress());
                            newCommercial->setID(uniqueID);
                        }
                    }
                    else
                    {
                        checkInput(line);
                    }
                
                }
                else
                {
                    checkInput(line);
                }
            }
            else
            {
                checkInput(line);
            }
        }
    }
    
    in_file.close();
    
    return validFile;
}

/* *****************************************************************************
 sortReport()
 
 DESCRIPTION - This function prompts if user wants to sort the tax report, if the user enters 'Y' or 'y'
 then the function will prompt to sort by either the address or by taxes due.
 
 PARAMETERS:
 
 RETURNS - a Char, 'N' if the user does not want to sort, or 'A' or 'T' depending on if user wants to sort by Address or Taxes due.
 ***************************************************************************** */
char sortReport()
{
    char sort_by;
    cout << "Would you like to sort the tax report?[Y/N] ";
    string answer;
    getline(cin,answer);
    
    if (answer == "Y" || answer == "y")
    {
        cout << "\nSort by:\n";
        cout << "A)ddress\n";
        cout << "T)axes due\n\n";
        string sort;
        getline(cin, sort);
        
        if (sort == "A" || sort == "a")
        {
            sort_by = 'A';
        }
        else if (sort == "T" || sort == "t")
        {
            sort_by = 'T';
        }
    }
    else
    {
        sort_by = 'N';
    }
    
    return sort_by;
}

/* *****************************************************************************
 sortAddress()
 
 DESCRIPTION - This function sorts the properties by their address for the tax report.
 
 PARAMETERS:
 @properties - This vector contains all of the properties to be sorted.
 
 RETURNS - nothing
 ***************************************************************************** */
void sortAddress(vector<Property*> & properties)
{
    const int FIRST_POS = 0;
    vector<Property*> sortedProperties;
    
    Property* smallestProperty;
    string street_name;
    int smallest = 0, index = 0, size = 0;
    size = properties.size();
    
    
    for (int i=0; i < size; i++)
    {
        street_name = properties[FIRST_POS]->getStreetName();
        smallest = properties[FIRST_POS]->getHouseNum();
        
        for (int i=0; i < properties.size(); i++)
        {
            if (properties[i]->getHouseNum() <= smallest)
            {
                if (properties[i]->getHouseNum() == smallest)
                {
                    //check to see which street is higher alpha
                    if (properties[i]->getStreetName() <= street_name)
                    {
                        street_name = properties[i]->getStreetName();
                        smallestProperty = properties[i];
                        index = i;
                    }
                }
                else
                {
                    smallest = properties[i]->getHouseNum();
                    smallestProperty = properties[i];
                    index = i;
                }
            }
        }
        properties.erase(properties.begin()+index);
        sortedProperties.push_back(smallestProperty);
    }
    
    printTaxReport(sortedProperties);
    
}
/* *****************************************************************************
 sortTaxesDue()
 
 DESCRIPTION - This function sorts the properties by the amount of taxes due for the tax report
 
 PARAMETERS:
 @properties - This vector contains all of the properties to be sorted.
 
 RETURNS - nothing
 ***************************************************************************** */
void sortTaxesDue(vector<Property*> properties)
{
    const int FIRST_POS = 0;
    vector<Property*> sortedProperties;
    
    Property* cheapestProperty;
    double smallest = 0;
    int index = 0, size = 0;
    size = properties.size();
    
    for (int i=0; i < size; i++)
    {
        smallest = properties[0]->taxesDue();
        for (int i=0; i < properties.size(); i++)
        {
            if (properties[i]->taxesDue() <= smallest)
            {
                smallest = properties[i]->taxesDue();
                cheapestProperty = properties[i];
                index = i;
            }
        }
        properties.erase(properties.begin()+index);
        sortedProperties.push_back(cheapestProperty);
    }
    
    printTaxReport(sortedProperties);
}

int main()
{
    const char ADDRESS = 'A', TAXES_DUE = 'T', NO = 'N';
    bool validFile;
    vector <Property*> properties;
    
    cout << "What is the location of the property file? ";
    
    string file;
    
    getline(cin, file);
    cout << endl << endl;
    
    validFile = processInput(file, properties);
    
    if (validFile)
    {
        printValidProperties(properties);
        cout << endl << endl;
        char sort_by;
        sort_by = sortReport();
        
        if (sort_by == ADDRESS)
        {
            sortAddress(properties);
        }
        else if (sort_by == TAXES_DUE)
        {
            sortTaxesDue(properties);
        }
        else if (sort_by == NO)
        {
            printTaxReport(properties);
        }
    }
    
    return 0;
}
