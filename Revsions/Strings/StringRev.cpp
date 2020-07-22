#include <iostream>
#include <string>
#include <numeric>
#include <range/v3/all.hpp>
using std::cout;
using std::cin;
using std::endl;

using namespace ranges;

int main() {
	auto showValues = []( auto& someArray) {
		//cout << "Showing: " << message;
		for (auto item : someArray) {
			cout << item << " ";
		}
		cout << endl;
	};

	auto createArray = ranges::views::iota(1, 11);
	auto val2 = createArray | views::filter([](const auto& a) {return a % 2 == 1; });
	auto val3 = val2 | views::transform([](const auto& a) { return a * 2; });
	
	showValues(createArray);
	showValues(val2);
	showValues(val3);

	std::string someval = " ssss ";

}