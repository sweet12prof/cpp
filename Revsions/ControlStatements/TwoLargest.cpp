#include <iostream>
using std::cin;
using std::cout;

int main(){
    int largest, secondLargest, input, count {0};

    while (cin >> input){
        if(count == 10)
            break;
        if(input > largest && input != largest ){
            secondLargest = largest;
            largest = input;
        }
        else 
            {
                if(input > secondLargest)
                    secondLargest = input;
            }
        count ++;
    }
    cout << "The largest numbers are : " << largest << " and " << secondLargest;
}