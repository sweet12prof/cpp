#include "TwoDayCost.hpp"

double TwoDayCost::calculateCost(){
    return TwoDayCost::flatcost;
}

TwoDayCost::TwoDayCost(const double& flatcost)
:flatcost(flatcost) {}