#pragma once
#include "users.hpp"
#include "costModel.hpp"
using namespace Users;
class Package_DI{
    public: 
         Package_DI(const User&, const User&, const int&, CostModel*);
         virtual ~Package_DI();
         void packageDetails() const;
    private: 
        User sender;
        User recipient;
        int  weight=0;
        CostModel* CostMethod;
};