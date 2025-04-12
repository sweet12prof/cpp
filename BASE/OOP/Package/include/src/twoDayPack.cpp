#include "twoDayPack.hpp"

TwoDayPackage::TwoDayPackage(const User& sender, const User& recipient, const int& weight,
        const double& flatcost)
        :Package{sender, recipient, weight}, flatCost{flatcost} 
{
}

double TwoDayPackage::calculateCost()const{
    return this->flatCost;
}

void TwoDayPackage::packageDetails() const {
    TwoDayPackage::Package::packageDetails();
    std::print("-----------COST--------------\n");
    std::print("Cost: {}", this->flatCost);
}