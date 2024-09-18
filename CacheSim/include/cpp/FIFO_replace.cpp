#include <FIFO_replace.hpp>

FIFOReplacement::FIFOReplacement(Associative& bArg)
:associativity{bArg.getassoc()}, toGetNextIndex{0}{}

std::string FIFOReplacement::policyName() {
    return "FIFO replacement Policy";
}

void FIFOReplacement::trackLRU(const std::size_t& address, const int& way){
    return;
}


int FIFOReplacement::Replace(const std::size_t& address){
    int temp  = this->toGetNextIndex;
    //this->toGetNextIndex = (this->toGetNextIndex < (this->associativity - 1)) ? this->toGetNextIndex + 1 : 0;
    if(temp < this->associativity - 1)
        this->toGetNextIndex++;
    else if(temp == this->associativity - 1)
        this->toGetNextIndex = 0;
    return temp;
}