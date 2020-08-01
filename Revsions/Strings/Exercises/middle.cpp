#include <iostream>
#include <string>

int main(){
    std::string myString = "chris";
    size_t pos = (myString.size() /2 ) % 2 == 1 ? (myString.size() /2 ) + 1 :  myString.size() /2;
    myString.insert( pos, "xxxxx");
    std::cout <<myString;
}