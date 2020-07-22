#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool fromBothsides(const string &);

int main() {
	string someString;
	cout << "Enter string to determine: ";
	std::getline(cin, someString);
	
	if (fromBothsides(someString))
		cout << "It is a palindrome";
	else
		cout << "Nah bro";	
}

bool fromBothsides(const string & someString) {
	char Fpointer;
	char Bpointer;

	if (someString.length() == 1)
		return true;
	else {
		Fpointer = someString.at(0);
		Bpointer = someString.at(someString.length() - 1);

		if (Fpointer == Bpointer)
		{
			string newString = someString.substr(1, (someString.length() - 2));
			return true && fromBothsides(newString);
		}
		else
		{
			string newString = someString.substr(1, someString.length() - 2);
			return false;
		}
	}
		
}

