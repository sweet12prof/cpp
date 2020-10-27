#include <iostream>
#include <string>
#include "./DivideByZero_derivedException.h"

int main(){//Exceptions
    int quotient{0}, divisor{0};
    while(std::cin >> quotient >> divisor)
    {
        try{
            std::cout << "The result is: " <<  divide(quotient, divisor) << std::endl;
        }

        catch(DivideByZeroExpt & divExcpt)
        {
            std::cout << "Exception message : " << divExcpt.what();
        }
    }
    std::cout << std::endl << std::endl;
}