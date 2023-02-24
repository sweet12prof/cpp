#include <iostream>
#include "Poly.hpp"

int main(){
    Poly somePoly(5);
    Poly somePoly2(2);
    Poly somePoly3(2);

   
    int i{0};

    std::cout << "Enter first poly: ";
    std::cin >> somePoly;
    std::cout << std::endl;
    std::cin.clear();

    std::cout  << "Enter second Poly: "; 
    std::cin >> somePoly2;
    std::cout << std::endl;
    std::cin.clear();

    std::cout <<"Enter third Poly: "; 
    std::cin >> somePoly3;
    std::cout << std::endl;
    
    std::cout << somePoly2 << std::endl << somePoly3 << std::endl;
    for(auto i{0}; i<somePoly2.getSize(); i++)
        std::cout << "--------"; 
    std::cout << std::endl;
    //std::cout << somePoly + somePoly2 + somePoly3;
    std::cout << "size of somePoly 3 is " << somePoly3.getSize() << std::endl; 
    somePoly3 = somePoly2 * somePoly3;
    std::cout << "size of somePoly3 is " << somePoly3.getSize() << std::endl;
    std::cout << somePoly3 << std::endl << std::endl;

    somePoly3 += somePoly3 += somePoly2 += somePoly;

    std::cout << somePoly3 << std::endl;


}