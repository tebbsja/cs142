#pragma once
#include "Property.h"

class Residential : public Property
{
public:
    //---------------------------------------------------------------------------------------
    /*
     * Constructor
     *
     * Handles creation of Residential objects.
     *
     * @address
     *		The address of the property
     * @rental
     *		If property is a rental
     * @occupied
     *      If the property is occupied
     * @price
     *      The price of the property
     */
    Residential();
    Residential(string address, bool rental, bool occupied, double price);
    ~Residential();
    
    //---------------------------------------------------------------------------------------
    /*
     * getOccupied
     *
     * Returns - a bool value, if property is occupied
     */
    bool getOccupied() const;
    
    
    //---------------------------------------------------------------------------------------
    /*
     * toString
     *
     * Returns - a string with useful information about the property
     */
    string toString();
    
    
    //---------------------------------------------------------------------------------------
    /*
     * convertOccupancy
     *
     * converts bool value occupied into a string either "Occupied" or "Vacant"
     *
     * Returns - a string telling if the property is occupied or vacant
     */
    string convertOccupancy();
    
    
    //---------------------------------------------------------------------------------------
    /*
     * taxesDue
     *
     * Returns - the amount of taxes due on a property
     */
    double taxesDue();
    
private:
    bool occupied;
};
