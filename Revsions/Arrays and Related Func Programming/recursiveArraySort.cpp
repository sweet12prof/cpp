#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;

void returnSmallestNum(std::array<int, 9> &, const int & Sub1, const int & Sub2);

int currentMin;

int main() {
	std::array <int, 9> someArray = { 32,7,8,4, 8, 1, 3, 21,9 };
	returnSmallestNum(someArray, 3, 8);
}

void returnSmallestNum(const std::array<int, 9> & someArray, const int & Sub1, const int &  Sub2 ) {
	if (Sub1 == Sub2) {
		currentMin = currentMin < someArray[Sub1] ? someArray[Sub1] : currentMin;
		cout << "Minimum value is: " << currentMin;
	}
		
	else{
		int plus1 = Sub1 + 1;
		currentMin = currentMin < someArray[Sub1] ? someArray[Sub1] : currentMin;
		returnSmallestNum(someArray, plus1, Sub2);
	}
		
		
}