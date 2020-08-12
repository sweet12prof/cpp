#include <iostream>
#include <iterator>
#include <string>
#include <vector>
int main(){

    std::string num1, num2;
    std::istream_iterator<std::string> input_iter {std::cin};
    std::cout << "Enter 2 numbers: " ;
    num1 = *input_iter;
    ++input_iter;
    num2 = *input_iter;

    std::ostream_iterator<std::string> output_iter{std::cout};
    std::cout << std::endl << "sum of the 2 numbers is : ";
    *output_iter = num1 + num2;
    ++ output_iter;
    std::cout << std::endl << "Entering a new number: ";
    *output_iter = "Chris"; 

    std::cout << std::endl;


    std::vector<int> someVec {1,2,3,4,5,6,7};
    
    for(auto i = someVec.rbegin(); i<someVec.rend(); ++i){
        *i = (2* (*i)) + 2;
    }

    for(auto i = someVec.crbegin(); i<someVec.crend(); ++i){
        std::cout << *i << " ";
    }
    std::cout<< std::endl;
    
}