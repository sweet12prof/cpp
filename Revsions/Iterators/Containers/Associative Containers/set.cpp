#include <iostream>
#include <set>
#include <iterator>
#include <vector>

void printSet(const std::set<int, std::less<int>> &);
int main(){
    std::vector input {8, -1, 2,0, 4, -1, 8};
    std::set <int, std::less<int>> Firstset{input.crbegin(), input.crend()};

    printSet(Firstset);

    auto p{Firstset.insert(7)};

    std::cout << "The key " << (* p.first ) << (p.second ? " was not inserted" : " was inserted");
    

}

void printSet(const std::set<int, std::less<int>> & someSet){
    std::ostream_iterator <int> iterate {std::cout, " "};
    if(someSet.empty())
        std::cout << "the set is empty" << std::endl;
    else
        std::copy(someSet.begin(), someSet.end(), iterate );
}