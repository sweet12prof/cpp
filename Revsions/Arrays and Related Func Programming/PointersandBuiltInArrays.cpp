#include <iostream>
using std::cout;
using std::cin;
void someFunc(int[]);

int main() {
	int count = 5;
	int * countPtr{& count };
	
	*countPtr = *countPtr * 5;
	cout << "Count is " << *countPtr;

	int someArray[] = { 1,2,3,4,5 };
	cout << someArray;
	someFunc(someArray);

	cout << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
		cout << someArray[i] << " ";
}

void someFunc(int arr[]  ) {
	for (int i = 0; i < 5; i++) {
		arr[i] = arr[i] * 5;
	}
	//return arr;
}