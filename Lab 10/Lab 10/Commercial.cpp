#include "Commercial.h"

Commercial::~Commercial(){}

Commercial::Commercial(){}

Commercial::Commercial(string address, bool rental, bool tax_discount, double price, double discount_rate)
            :Property(address, rental, price)
{
    this->discount_rate = discount_rate;
    this->tax_discount = tax_discount;
}

bool Commercial::getTaxDiscount() const
{
    return tax_discount;
}

string Commercial::convertTaxDiscount()
{
    string discount;
    
    if (getTaxDiscount() == true)
    {
        discount = "Discounted";
    }
    else
    {
        discount = "Not Discounted";
    }
    
    return discount;
}

double Commercial::getDiscountRate() const
{
    return discount_rate;
}

double Commercial::taxesDue()
{
    double taxes_due = 0, taxes = getPrice(), tax_credit = 0;
    const double RENT_TAX_RATE = .012;
    const double NON_RENT_TAX_RATE = .01;
    tax_credit = 1 - (getDiscountRate());
    
    if (getTaxDiscount() == true)
    {
        taxes = (getPrice()) * tax_credit;
    }
    if (getRental() == true)
    {
        taxes_due = taxes * (RENT_TAX_RATE);
    }
    else
    {
        taxes_due = taxes * (NON_RENT_TAX_RATE);
    }
    

    return taxes_due;
}

string Commercial::toString()
{
    string rentalString, discount;
    
    rentalString = convertRental();
    discount = convertTaxDiscount();
    
    stringstream ss;
    
    ss << "Property ID: " << getPropertyID() << " Address: " << getAddress() << endl;
    ss << rentalString << " Estimated Value: " << getPrice() << " " << discount;
    
    if (discount == "Discounted")
    {
        ss << " Discount " << getDiscountRate() << endl;
    }
    else
    {
        ss << endl;
    }
    
    return ss.str();
}