#include <iostream>
#include <vector>
#include <stdexcept>
using std::cout;
using std::cin;
using std::vector;
using std::endl;

void inputVector(vector<int> &);
void printVectors(const vector<int>&);
int main() 
{
	//Create Vector
	vector <int> vector1(5);
	vector <int> vector2(7);
	inputVector(vector1);
	inputVector(vector2);
	printVectors(vector1);
	printVectors(vector2);

	try {
		cout << "Element at index 8 for vector2: "<<vector2.at(8);
	}
	catch (const std::out_of_range & ex) {
		std::cerr << "This happened: " << ex.what();
	}

	vector1.push_back(2);
	vector1.push_back(27);
	printVectors(vector1);
}

void inputVector(vector<int>& vectorIn)
{
	for (auto& item : vectorIn)
		cin >> item;
}

void printVectors(const vector<int>& vectorIn) {
	for (auto& item : vectorIn)
		cout << item << " ";
	cout << endl;
}