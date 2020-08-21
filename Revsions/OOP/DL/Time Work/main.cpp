#include <iostream>
#include <sstream>
#include "Time.hpp"
int main(){
    Time TimeObj;

    
    std::string TimeInput;

    int h;
    int m;
    int s;
    
    std::cout << "What is the time : ";
    std::getline(std::cin, TimeInput);

    std::stringstream stream{TimeInput};

    stream >> h >> m >> s;

    TimeObj.setTime(h, m, s);

    //std::cout << h << " "  << h << " " << m << " " << s << std::endl;
    std::cout << std::endl <<"The standard time is: " << TimeObj.getStandardTime();
    std::cout << std::endl << "The universal time is: " << TimeObj.getUniversalTime();
}