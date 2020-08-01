#include <iostream>
#include <string>

int main(){
    std::string someString {"My name is christopher Nutsukpui. I am 23 years old."};

    int spacePos{someString.find(" ")};
    std::cout << someString << std::endl; 
    while(spacePos != someString.npos){
        someString.replace(spacePos, 1, ".");
        spacePos = someString.find(" ", (spacePos + 1));
    }

    std::cout << someString << std::endl ;


}