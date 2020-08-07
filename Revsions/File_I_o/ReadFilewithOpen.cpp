#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main(){

    std::ofstream output;
    std::string inputName,inputNumber;

    output.open("Tit.txt", std::ios::out);
    if(  !output){
                std::cerr << "File could not be opened";
                std::exit(EXIT_FAILURE);
        }
       
     else {
               

                 std::cout << "Enter name and Number: " << std::endl;
        while(std::cin >> inputName >> inputNumber){
            output << std::setw(20) << std::left <<inputName << std::setw(20) << std::left << inputNumber << std::endl;
        }
    
    
    

}
    output.flush();
    output.close();

    std::cin.clear();
 
    
    std::ofstream outputs;

   outputs.open("Titss.txt", std::ios::out);
    if( !outputs){
                std::cerr << "File could not be opened";
                std::exit(EXIT_FAILURE);
        }
       
     else {
               
           
            std::cout << "Enter name and Number: ";
            while(std::cin >> inputName >> inputNumber)
                outputs << std::setw(20) << std::left <<inputName << std::setw(20) << std::left << inputNumber << std::endl;
        
    }


}