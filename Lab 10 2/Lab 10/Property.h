#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Property
{
public:
    //---------------------------------------------------------------------------------------
    /*
     * Constructor
     *
     * Handles creation of Property objects.
     *
     * @address
     *		The address of the property
     * @rental
     *		If property is a rental
     * @price
     *      The price of the property
     */
    Property();
    Property(string address, bool rental, double price);
    virtual ~Property();
    //---------------------------------------------------------------------------------------
    /*
     * toString
     *
     * Returns - a string with useful information about the property
     */
    virtual string toString() = 0;
    //---------------------------------------------------------------------------------------
    /*
     * getAddress
     *
     * Returns - the address as a string
     */
    string getAddress() const;
    //---------------------------------------------------------------------------------------
    /*
     * getPropertyID
     *
     * Returns - the property ID number as an integer
     */
    int getPropertyID() const;
    //---------------------------------------------------------------------------------------
    /*
     * getRental
     *
     * Returns - a bool value, whether or not the property is a rental
     */
    bool getRental() const;
    //---------------------------------------------------------------------------------------
    /*
     * setID
     *
     * @ID - the number to set the ID number to
     *
     * assigns an ID number to a property
     */
    void setID(int ID);
    //---------------------------------------------------------------------------------------
    /*
     * getPrice
     *
     * Returns - the price of the property as a double
     */
    double getPrice() const;
    //---------------------------------------------------------------------------------------
    /*
     * convertRental
     *
     * Returns - a string either "Rental" or "NOT Rental"
     */
    string convertRental();
    //---------------------------------------------------------------------------------------
    /*
     * taxesDue
     *
     * Returns - the amount of taxes due on a property
     */
    virtual double taxesDue() = 0;
    //---------------------------------------------------------------------------------------
    /*
     * getHouseNum
     *
     * Returns - the house number as an integer
     */
    int getHouseNum();
    //---------------------------------------------------------------------------------------
    /*
     * getStreetName
     *
     * Returns - the street name as a string
     */
    string getStreetName();
    
private:
    string address;
    bool rental;
    double price;
    int propertyID;

};