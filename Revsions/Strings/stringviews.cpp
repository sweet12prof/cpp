#include <iostream>
#include <string>

int main(){
    char *myName = "Chris";
    std::string_view someString{myName};

    for(auto item : someString)
        std::cout << item;

    char charArray[6] = {"chris"};
    std::cout <<std::endl;
    for(auto item : charArray)
        std::cout << item  << " ";
}