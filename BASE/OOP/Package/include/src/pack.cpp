#include "pack.hpp"

Package::Package(const User& sender, const User& recipient, const int& weight)
:sender{sender}, recipient{recipient}, weight{std::max(0, weight)}, cost{0.0}{   
    this->cost = calculateCost();
}

double Package::calculateCost() const{
    return this->weight * this->costPerOunce;
}

void Package::packageDetails() const{
    std::print("-----------SENDER-------------\n");
    this->sender.UserDetails();
    std::print("\n");
    std::print("-----------RECEIVER-----------\n");
    this->recipient.UserDetails();
    std::print("\n");
    
}
