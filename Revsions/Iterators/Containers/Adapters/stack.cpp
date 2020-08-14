#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>

template <typename T> void insertVec(T&);
int main(){
    //std::vector<int> myVec {1,2,3,4};
    std::stack<int, std::vector<int>> stackVec;
    insertVec(stackVec);

}

// template <typename T> void printVec(T &stackref){
//     std::ostream_iterator<int> Output {std::cout, " "};
//     std::copy(stackref.begin(), stackref.end(), )
// }

template <typename T> void insertVec(T& stackRef){
    int i{0};
    while(i != 10){
        stackRef.push(i);
        
    }
}