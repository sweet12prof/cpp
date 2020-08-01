// 4WAY_GenerateTrace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

using std::setw;
using std::string;

std::stringstream padZero();
std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
std::uniform_int_distribution<int> randomInt{ 0, 999999999 };

int main()
{

    std::ofstream output1{ "memFile1.txt", ( std::ios::out | std::ios::app) };
    std::ofstream output2{ "memFile2.txt", (std::ios::out) | std::ios::app};
    std::ofstream output3{ "memFile3.txt", (std::ios::out) | std::ios::app};
    std::ofstream output4{ "memFile4.txt", (std::ios::out) | std::ios::app};

    if (output1) {
        for (int i = 0; i < 16; i++)
            output1 << std::left << setw(8) << padZero().str() << std::endl;
    }
    else
        exit(EXIT_FAILURE);
    

    if (output2) {
        for (int i = 0; i < 16; i++)
            output2 << std::left << setw(8) << padZero().str() << std::endl;
    }
    else
        exit(EXIT_FAILURE);
 

    if (output3) {
        for (int i = 0; i < 16; i++)
            output3 << std::left << setw(8) << padZero().str() << std::endl;
    }
    else
        exit(EXIT_FAILURE);
   

    if (output4) {
        for (int i = 0; i < 16; i++)
            output4 << std::left << setw(8) << padZero().str() << std::endl;
    }
    else
        exit(EXIT_FAILURE);
    
}


std::stringstream padZero() {
    std::stringstream stream;
    stream <<std::hex << setw(8) << std::setfill('0') << randomInt(engine);
    return stream;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
