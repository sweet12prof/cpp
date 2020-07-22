#include <iostream>
#include <array>
#include <iomanip>
#include <random>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::array;

std::default_random_engine engine{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<int> randomInt { 1, 30 };
	
constexpr size_t columns { 20 };
constexpr size_t rows{ 20 };

void createMap(array < array <char, columns>, rows>&, int start, int Finish);

int main() {
	array < array <char, columns>, rows> myMaze;

	createMap(myMaze, 1, 10);
	for (auto& rows : myMaze) {
		for (auto& item : rows)
		{
			cout << item << " ";
		}
		cout << endl;
	}
		
}


void createMap(array < array <char, columns>, rows>& mapArray, int start, int Finish) {
	int rowNum = 0;
	int columnNum = 0;
	for (auto& rows : mapArray) {
		for (auto& item : rows)
		{
			if (columnNum == 0 and rowNum == 1)
				item = '.';
			else if (columnNum == 19 and rowNum == 16)
				item = '.';
			else if (columnNum == 0 || columnNum == 19 || rowNum == 0 || rowNum == 19)
				item = '#';
			else
				item = randomInt(engine) < 11 ? '#' : '.';
		++columnNum;
		}
		columnNum = 0;
		++rowNum;
	}
		
}
