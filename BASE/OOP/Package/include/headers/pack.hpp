#pragma once
#include "users.hpp"
#include <print>
using namespace Users;
class Package{
    public:
        Package(const User&, const User&, 
        const int&);
        virtual ~Package() = default;

      //  static double CostPerOunce(){return costPerOunce;};
        //void CostPerOunce(const double&) const;

        virtual double calculateCost() const;
        virtual void packageDetails() const;


    private: 
        User sender;
        User recipient;
        int     weight=0;
        double cost=0.0;
        inline static double  costPerOunce{25.0};
};