#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main(){
    std::ifstream input{"clients.txt", std::ios::in};
    
    if( std::string inName, inNumber; input){
        while(input >> inName >> inNumber){
            cout << std::setw(20) << std::left << inName << std::setw(20) << std::left << inNumber << std::endl;
        }
    }
        else {
            cerr << "File cannot be opened or does not exist";
            exit(EXIT_FAILURE);
        }
}