#include "costModel.hpp"
class TwoDayCost: public CostModel {
    private: 
        double flatcost;
    public: 
        TwoDayCost(const double &);
        double calculateCost() override;
};