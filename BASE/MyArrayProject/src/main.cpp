#include <iostream>
#include <Myarray.hpp>
#include <print>
Array::MyArray& CheckingDestruct();

int main(){
    {
        using namespace Array;
        MyArray arrOfInt2{1,2,3, 4,5};
        MyArray arrOfInt3{arrOfInt2};
        std::cout << arrOfInt3++;
        std::cout << (++arrOfInt3)++;
        arrOfInt3+=2;
        std::cout << arrOfInt3;

        std::print("{}", (arrOfInt2) ? "yay": "nay");
        try {
                std::print("{}",arrOfInt2[4]);
                arrOfInt2[2] = 12;
                std::cout << arrOfInt2;
                arrOfInt2[6] = 10;
            } catch(std::out_of_range ex){
                std::print("Error: {}", ex.what());
        }
    }
}

