#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main(){
    std::ifstream input{"Titss.txt", std::ios::in};
    
    if( std::string inName, inNumber; input){
        
        input.seekg(41);
        input.seekg(20, std::ios::end);
        while(input >> inName >> inNumber){
            cout << std::setw(20) << std::left << inName << std::setw(20) << std::left << inNumber << std::endl;
        }
    }
        else {
            cerr << "File cannot be opened or does not exist";
            exit(EXIT_FAILURE);
        }
}