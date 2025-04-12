#pragma once
class CostModel{
    public:
        virtual ~CostModel() =default;
        virtual double calculateCost() = 0;
};