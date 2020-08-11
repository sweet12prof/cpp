#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using std::cout, std::cin, std::endl, std::cerr, std::string, std::setw;

int main(){
    std::ifstream input;
    input.open("clients.txt", std::ios::in);

    string field1, field2 = "";


    if(!input){
        cerr << "File could not be opened " << endl;
        exit(EXIT_FAILURE);
    }
    else {
      //  input.seekg(160, std::ios::cur);
       // input.seekg(120, std::ios::cur);
        input.seekg(0, std::ios::end);
        cout << "Current Location is: " << input.tellg() << endl;
        input.seekg((-166), std::ios::end);
         cout << "Current Location is: " << input.tellg() << endl;
        
        while(input >> field1 >> field2){
            cout << setw(20) << std::right << field1 << setw(20) << std::right << field2 << endl; 
        }
    }
}