#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

	std::ofstream output{ "recordsFile.txt", std::ios::out };
	string name, number{};

	if (output) {

		output << std::setw(20) << "Name" << std::setw(25) << "Number"<<endl;

		cout << "Enter name and Number seperated by space: " << endl;
		while (cin >> name >> number)
			output << std::setw(20) << name << std::setw(15) << "(+233) " << number << endl;
	}
	else {
		std::cerr << "file could not be opened";
		std::exit(EXIT_FAILURE);
	}
		
	
}