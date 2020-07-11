#include <iostream>
#include <array>
#include <numeric>
using std::cout;
using std::cin;
using std::endl;
using std::array;

int main(){
    constexpr size_t columns{2}, rows{5};
    array < array < int, columns>, rows > myArray {6,9,0,6,0,4,5};

    for(auto rows : myArray ){
        for (auto item : rows)
            cout << item << " ";
        cout << endl; 
    }
    cout << "Manipulating and pronying" << endl;
    for(auto & rows : myArray ){
        for (auto & item : rows){
            item *= (item + 1);
            cout << item << " ";
        }   
        cout << endl; 
    }

    
    
    int sum = std::accumulate(begin(myArray.at(0)), end(myArray.at(rows -1)), 0);
    cout << "Sum is " << sum;
    cout<< endl;;
}