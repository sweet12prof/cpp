#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

void printSet( std::multiset<int, std::less<int>> &);
int main(){
     std::multiset <int, std::less<int>> intSet;
     
     intSet.insert(12);
     intSet.insert(12);

     std::cout << "The count of the key 12 is : " << intSet.count(12);

     auto result = intSet.find(121);

    if(result == intSet.end())
        std::cout << "That key does not exist";
    std::cout << std::endl;

    result = intSet.find(12);
    if(result != intSet.end())
        std::cout << "The key exists";

    std::cout << std::endl;

    std::vector <int> someVec {13,-1,1,2,2};
    std::vector <int> reCapVec {2,1,0};

    // reCapVec.insert(reCapVec.end(), someVec.begin(), someVec.end());


    intSet.clear();
    printSet(intSet);
    std::cout << std::endl;


    intSet.insert(someVec.cbegin(), someVec.cend());
    printSet(intSet);

    std::cout << "The lower bound of 2 is " << *(intSet.lower_bound(2)) 
            << "\nThe upper bound of 2 is " << *(intSet.upper_bound(2));

    auto p{intSet.equal_range(2)};

    std::cout << std::endl << "The lower bound of  2 is " << *(p.first) << std::endl 
                      << "The upper bound is : " << *(p.second) << std::endl;
        
}

void printSet( std::multiset<int, std::less<int>> & someset){
    std::ostream_iterator <int> output {std::cout, " "};
    if(someset.empty())
        std::cout << "The set is empty ";
    else
        std::copy(someset.cbegin(), someset.cend(), output);
}