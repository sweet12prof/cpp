#include <hpp/hello.hpp>
#include <iostream>


int main(){
    const int a {3};
    int b;
   std::cin >> b;
    int somearr [a * b]= {}; 
    std::cout << "a is {}" << b << std::endl;
    Hello::printHello() ;
    // std::cout <<"I am {} and {}" << 1 << 2;
}