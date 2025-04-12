#include "Acc.hpp"
#include <iostream>

Account::Account(std::string_view fName, std::string_view lName, const int & age)
:age{age}{
   
    setFName(fName); 
    setlName(lName);
   //  std::cout << this->fName << this->lName;
}


void Account::setFName(std::string_view FName){
    size_t length = FName.length() < 10 ? FName.length() : 9;
    FName.copy( Account::fName, length);
  this->fName[length] =  '\0';
}

void Account::setlName(std::string_view lName){
    size_t length = lName.length() < 10 ? lName.length() : 9;
    lName.copy( Account::lName, length);
    this->lName[length] =  '\0';
}

std::string Account::getfName() const{
    return  Account::fName;
} 

std::string Account::getlName() const{
    return Account::lName;
}

int Account::getAge() const{
    return this->age;
}
