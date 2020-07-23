#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main() {
	std::ofstream output {"clients.txt", std::ios::app };
	std:: string Name, number{};
	if (output) {
		cout << "Enter name and number seperated by one space: " << endl;
		cout << std::left << std::setw(20) << "Name" << std::left << std::setw(15) << "Number"<<endl;
		while (cin >> Name >> number) {
			output << std::left << std::setw(20) << Name << std::left << std::setw(15) << number << endl;
		}
	}
	else {
		std::cerr << "Failed top open file";
		exit(EXIT_FAILURE);
	}

	std::ifstream input{ "clients.txt", std::ios::in };
	if (input) {
		while (input >> Name >> number) 
			cout << std::left << std::setw(20) << Name << std::left << std::setw(15) << number << endl;
		
	}
	else {
		std::cerr << "Failed top open file";
		exit(EXIT_FAILURE);
	}
}