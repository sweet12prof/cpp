#include "uniqPtr.hpp"

int Account::Id(void){
    return 2;
}

void Account::Id(const int& Id){
    this->id = Id; 
}