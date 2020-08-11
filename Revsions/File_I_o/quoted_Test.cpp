#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using std::string, std::cout, std::cin, std::endl;

int main(){
    std::ofstream output;
    std::string name;
    std::string number;
    output.open("tryingquoted.txt");
    std::cout <<"Enter name and number seperated by new line: " << std::endl;
    while ( std::getline(cin, name) && (cin >> number)){
        string buffClear;
       /// cin >> number;
       
        output << std::setw(40) << std::left << std::quoted(name) << std::setw(20) << std::left << number << endl ;
        std::getline(cin, buffClear);
    }
}