#include "pack.hpp"
class TwoDayPackage : public Package{
    public:
        TwoDayPackage(const User& sender, const User& recipient, const int& weight,
        const double& flatcost);
         ~TwoDayPackage(){std::print("Destroyed");}
        double calculateCost() const override;
        void packageDetails() const override;
    private: 
        double flatCost{0.0};
};