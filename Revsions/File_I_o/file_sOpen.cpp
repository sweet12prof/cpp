#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include  <cstdlib>

int main(){

    std::ofstream output{"clients.txt", std::ios::out || std::ios::app};
    std::string inputName, inputNumber;
    if(output){
        std::cout << "Enter name and Number: " << std::endl;
        while(std::cin >> inputName >> inputNumber){
            output << std::setw(20) << std::left <<inputName << std::setw(20) << std::left << inputNumber << std::endl;
        }
       
    } else {
                std::cerr << "File could not be opened";
                std::exit(EXIT_FAILURE);
    }
}