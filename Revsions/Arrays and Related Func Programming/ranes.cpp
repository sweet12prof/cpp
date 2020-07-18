#include <iostream>
#include <algorithm>
#include <numeric>
#include <range/v3/all.hpp>
#include <string>
#include <array>
#include <vector>
using namespace ranges;
std::array<int, 5> someFunc(std::array<int, 5>);

int main(){
    auto showValues = [](auto & someContainer) {
        for (auto  item : someContainer) {
            std::cout << item << " ";
        }
    };

    auto createArray = views::iota(1, 11);
    auto val2 = createArray | views::filter([](const auto& a) {return a % 2 == 0; });
    auto val3 = val2 | views::transform([](const auto& a) {return "abe"; });
    
    showValues(createArray);
    
    std::cout << std::endl << std::endl;
    showValues(val2);
    std::cout << std::endl << std::endl;
    showValues(val3);
    std::cout << std::endl << std::endl;
    auto val4 = std::accumulate(val2.begin(), val2.end(), 0, [](auto x, auto y) {return x - y; });
    std::cout << val4;

    std::array <int, 5> m = {1,32,1, -1};
    for (auto item : m)
        std::cout << item <<" ";
    std::cout << std::endl << std::endl;
    std::vector <int> newVector = { 1,2,3,45 };
    auto newVal = newVector | views::filter([](const int& x) {
        return x % 2 == 1;
    });

    showValues(newVal);

}