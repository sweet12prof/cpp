#include <iostream>
#include <string>
#include <iomanip>

int main(){
    std::string someString;

    std::cin.width(10);
    std::cout << "Enter some string: ";
    std::cin >> someString;
    
    std::cout.width(20);
    std::cout <<std::endl <<"String type was: " << someString;
    
    std::cout <<std::endl <<"String type was: " << someString;

   //std::cout << std::setprecision(5) << 14.3488578;
   // std::cout << std::endl <<12.56;

    std::cout << std::fixed <<std::setprecision(3) << std::showpoint << std::endl << 12.0;
    std::cout.precision();
    
    std::string someString2 {"chrisnUts"};
    for(char & someChar : someString2)
            someChar = toupper(someChar);
    std::cout <<someString2;
}