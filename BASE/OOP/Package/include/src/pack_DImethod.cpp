#include "pack_DImethod.hpp"
#include <print>
Package_DI::Package_DI(const User& u1, const User& u2, const int& weight, CostModel* costmethod)
:sender{u1}, recipient{u2}, weight{weight}, CostMethod{costmethod} {}

Package_DI::~Package_DI(){
    delete this->CostMethod;
    this->CostMethod = nullptr;
}


void Package_DI::packageDetails() const{
    std::print("-----------SENDER-------------\n");
    this->sender.UserDetails();
    std::print("\n");
    std::print("-----------RECEIVER-----------\n");
    this->recipient.UserDetails();
    std::print("\nCost: {:f}", this->CostMethod->calculateCost());
}