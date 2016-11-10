#include "Property.h"

Property::Property(){};

Property::~Property(){}

Property::Property(string address, bool rental, double price)
{
    this->address = address;
    this->rental = rental;
    this->price = price;
}

bool Property::getRental() const
{
    return rental;
}

string Property::getAddress() const
{
    return address;
}

string Property::toString()
{
    stringstream ss;
    
    ss << address;
    
    return ss.str();
}

string Property::convertRental()
{
    string rentalString;
    if (getRental() == true)
    {
        rentalString = "Rental";
    }
    else
    {
        rentalString = "NOT Rental";
    }
    
    return rentalString;
}

int Property::getHouseNum()
{
    string address;
    address = getAddress();
    int house_num = 0;
    istringstream strm;
    strm.str(address);
    
    strm >> house_num;
    
    return house_num;
}

string Property::getStreetName()
{
    string street_name, address;
    int house_num = 0;
    address = getAddress();
    istringstream strm;
    strm.str(address);
    strm >> house_num;
    getline(strm, street_name);
    
    return street_name;
}

double Property::getPrice() const
{
    return price;
}

int Property::getPropertyID() const
{
    return propertyID;
}

void Property::setID(int ID)
{
    propertyID = ID;
}