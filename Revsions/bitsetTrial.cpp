#include <iostream>
#include <bitset>
#include <iomanip>

int main(){
    int numindec {727485849};
    std::bitset<32> someNum (numindec);
    std::cout << "Full num in binary: " << someNum << std::endl;
    someNum = someNum << 20;
    someNum = someNum >> 20;
    std::cout << "Full num in binary: " << someNum << std::endl;
}