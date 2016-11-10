#include "Residential.h"

Residential::~Residential(){}

Residential::Residential(){}

Residential::Residential(string address, bool rental, bool occupied, double price)
            : Property(address, rental, price)
{
    this->occupied = occupied;
}

bool Residential::getOccupied() const
{
    return occupied;
}

string Residential::convertOccupancy()
{
    string occupancy;
    
    if (occupied == true)
    {
        occupancy = "Occupied";
    }
    else
    {
        occupancy = "Vacant";
    }
    
    return occupancy;
}

double Residential::taxesDue()
{
    const double OCCUPIED_TAX_RATE = .006;
    const double VACANT_TAX_RATE = .009;
    
    double taxes_due = 0;
    taxes_due = getPrice();
    
    if (getOccupied() == true)
    {
        taxes_due = getPrice() * OCCUPIED_TAX_RATE;
    }
    else
    {
        taxes_due = getPrice() * VACANT_TAX_RATE;
    }
    
    return taxes_due;
}

string Residential::toString()
{
    string rentalString;
    rentalString = convertRental();
    
    string occupancy;
    occupancy = convertOccupancy();
    
    stringstream ss;
    ss << "Property ID: " << getPropertyID() << " Address: " << getAddress() << endl;
    ss << rentalString << " Estimated Value: " << getPrice() << " " << occupancy << endl;
    
    return ss.str();
}
