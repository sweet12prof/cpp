#include <iostream>
#include <vector>
#include <iterator>
#include <array>

template <typename T>
void printVector(std::vector<T> &);
int main(){

    int integerArray[10] {2,43,1,-1};
   
   for(auto i = std::rbegin(integerArray); i< std::rend(integerArray); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::vector<std::string> stringVec{ "chris", "melod", "Rhoda", "Myself"};
    
    std::ostream_iterator<std::string> printString{std::cout};
    std::ostream_iterator<std::string> printVectors{std::cout, "\n"};
    std::ostream_iterator<int> printIntVectors{std::cout, " "};

    *printString = "Elements of stringVec are:\n";
    std::copy(stringVec.begin(), stringVec.end(), printVectors);
    std::cout << std::endl;

    stringVec.insert((stringVec.begin() + 2), "mcMAc");
    std::copy(stringVec.cbegin(), stringVec.cend(), printVectors);

    std::cout << std::endl;

    std::array<int, 5 > numArray {1,23,4};
    std::vector<int> anotherVec {numArray.crbegin(), numArray.crend()};
    std::copy(anotherVec.begin(), anotherVec.end(), printIntVectors);

    std::cout << std::endl;
    std::vector <int> lastVector { anotherVec.begin() + 2, anotherVec.end()};

    // std::copy(anotherVec.begin() + 2, anotherVec.end(), lastVector);
    std::copy(lastVector.begin(), lastVector.end(), printIntVectors);

    std::cout << std::endl;
    lastVector.insert(lastVector.begin(), anotherVec.begin(), anotherVec.begin() + 2);
    std::copy(lastVector.begin(), lastVector.end(), printIntVectors);


}

template <typename T> void printVector(std::vector<T> & someSeq){
    for(auto i = someSeq.crbegin(); i < someSeq.crend(); i++)
        std::cout << *i << " ";


v

}