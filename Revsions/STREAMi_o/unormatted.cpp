#include <iostream>
#include <string>

int main(){

    std::string someString;
    char c;
    char d;
    char e;
    while ( (c = std::cin.get()) != EOF){
        someString += c;
        std::cout.put(c);
    }

    //std::cin.ignore(5);
    d = std::cin.get();

    std::cout << "Printed values is: "<<d << " cc"<< std::endl;

     std::cin.ignore(5);
 while(std::cin){
      e = std::cin.get();
 }
    std::cout << "e is " << e << " cc";


}