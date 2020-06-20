#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int numarray [10]{3,1,7,24,2,6, -2, 98,2, 20};
    int currentVal{0};
    int swapVal{0};
    int size = sizeof(numarray) / 4 ;

    for(int i{1}; i<size; i++){
         currentVal = i;
        for (int k{i-1}; k > -1; k--)
        {
            if(numarray[k] > numarray[currentVal]){
                swapVal = numarray[k];
                numarray[k] = numarray[currentVal];
                numarray[k+1] = swapVal;
                currentVal--;
            }
        }                   
    }

            for (auto a : numarray)
                cout << a << " ";
                cout <<endl;
}

 