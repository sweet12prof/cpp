#include <iostream>
#include <array>
#include <numeric>
using std::cout;
using std::cin;
using std::endl;
using std::array;

int* passingArray(array<int, 5>);
constexpr size_t arraySize = 5;
int main(){
    std::array<int, 5> myArray = {1,2,3};
   


    for(const auto & item : myArray)
        cout << item << " ";
        cout << endl << "Manipulating with pointers" << endl;

    for (auto & item : myArray)
            item *= item;

    for (const int item : myArray)
        cout << item << " ";
        cout<<endl;

    int sum{0};
    for(const int item : myArray)
        sum = std::accumulate(myArray.begin(), myArray.end(), 0);
    cout << "After Accumulating: " << sum << endl;
    cout << "Using \"at\" member func: " << myArray.at(0) << endl;
    cout << "Using c-style square brackets: " << myArray[5]<<endl<<endl;

    constexpr size_t columns{3}, rows{2};
    array< array <int, columns>, rows> myArray2{1,2,0,3};

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++)
                cout << myArray2[i][j] << " ";
            cout << endl;
        }

     cout << endl << endl << endl << endl << "Using range based for to modify multidimensional:" << endl;

     for (auto & row : myArray2)
        for(auto & item : row)
            item *= item - 1;

    cout << "Using range based for to display multidimensional array elements :" << endl;
     for (auto row : myArray2)
        {
            for(const int & item : row )
                cout << item << " ";
            cout << endl;
        }

        
     cout << "Using \"at\" member func for multidimensaional array: " << myArray2.at(0).at(1) << endl;
            
    array <int, 3> myarray3 = myArray2.at(0);
    for(const auto & item : myarray3)
        cout << item << " ";

     int * c_array;
    c_array = passingArray(myArray);

    cout << endl << endl<<endl<<endl<<"Using \"at\" member func for multidimensaional array after passing into function: "<< endl;
        for(int i=-100; i<100; i++)
            cout << *(c_array + i) << endl;
        cout << endl;
            //cout << *c_array;
         //   cout << (c_array + 1);
       
}


int * passingArray(array<int, arraySize> someArray) {
     int c_array[5];
     int i=0;

    for(auto & item : someArray)
        {
            item += 5;
            
            cout << "c_array element at " << "i is: "  << c_array[i] << endl; 
            i++;
        }

        c_array[0] = 1;
        c_array[1] = 3;
        c_array[2] = 5;
        c_array[3] = 4;
        c_array[4] = 2;
    return c_array;
}