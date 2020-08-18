#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <cmath>
#include <vector>


void misFunc(std::pair<std::array<int, 5>::iterator, std::vector<int>::iterator >);
int main(){
    int i{0};
    std::array <int, 5> someArray;
    std::vector <int> someVec {someArray.begin(), someArray.end()};
    std::ostream_iterator <int> Output {std::cout, " "};

    std::generate(someArray.begin(), someArray.end(), [&i](){
        ++i;
        return (std::pow((i - 1), 2 )+ 1);
    });

    std::copy(someArray.begin(), someArray.end(), Output );    

    std::cout << std::endl;

    std::generate_n(someVec.begin(), 5, [&i](){
        return i ;
    });

    std::copy(someVec.begin(), someVec.end(), Output );

    std::cout << std::endl;

    std::fill(someVec.begin(), someVec.end() - 3, 10);

    std::copy(someVec.begin(), someVec.end(), Output );

    bool areEqual = std::equal(someVec.begin(), someVec.end(), someArray.begin(), someArray.end());

    std::cout << std::endl << "They are "  << (areEqual ? "equal" : "not equal");

    someVec.assign(someArray.begin(), someArray.end());

    areEqual = std::equal(someVec.begin(), someVec.end(), someArray.begin(), someArray.end());

     std::cout << std::endl << "They are "  << (areEqual ? "equal" : "not equal");

    auto mismatched = std::mismatch(someArray.begin(), someArray.end(), someVec.begin(), someVec.end()); 
    //misFunc(mismatched, someArray.end(), someVec.end());

     if(( mismatched.first == someArray.end()) && (mismatched.second == someVec.end()) )
         std::cout << "They matched";
     else 
              std::cout << "They are mismatched at " << *(mismatched.first) << " " << *(mismatched.second);
        

}


// void misFunc(std::pair< std::array<int, 5>::iterator, std::vector<int>::iterator > somePair, std::array<int, 5>::iterator someEnd, std::vector<int>::iterator  anotherend){
//     if((somePair.first == someEnd) && (somePair.second == anotherend) )
//         std::cout << "They matched";
//     else 
//         std::cout << "They are mismatched at " << *(somePair.first) << " " << *(somePair.second);
// }