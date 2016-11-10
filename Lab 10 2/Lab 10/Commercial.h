#pragma once
#include "Property.h"

class Commercial : public Property
{
public:
    //---------------------------------------------------------------------------------------
    /*
     * Constructor
     *
     * Handles creation of Commerical objects.
     *
     * @address
     *		The address of the property
     * @rental
     *		If property is a rental
     * @tax_discount
     *      If there is a tax discount
     * @price
     *      The price of the property
     * @discount_rate
     *      The discount rate of the property taxes
     */
    Commercial();
    Commercial(string address, bool rental, bool tax_discount, double price,
               double discount_rate);
    ~Commercial();
    //---------------------------------------------------------------------------------------
    /*
     * toString
     *
     * Returns - a string with useful information about the property
     */
    string toString();
    //---------------------------------------------------------------------------------------
    /*
     * convertTaxDiscount
     *
     * converts the bool value tax_discount into a string
     *
     * Returns - a string either "Discounted" or "Not Discounted"
     */
    string convertTaxDiscount();
    //---------------------------------------------------------------------------------------
    /*
     * getDiscountRate
     *
     * Returns - the tax discount rate of the property as a double
     */
    double getDiscountRate() const;
    //---------------------------------------------------------------------------------------
    /*
     * taxesDue
     *
     * Returns - the amount of taxes due on the property as a double
     */
    double taxesDue();
    //---------------------------------------------------------------------------------------
    /*
     * getTaxDiscount
     *
     * Returns - a bool value, whether or not there is a tax discount
     */
    bool getTaxDiscount() const;
    
private:
    double discount_rate;
    bool tax_discount;
    
};