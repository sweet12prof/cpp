#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

bool isPrimeNumber(const int & );

int main(){
    cout <<std::setw(15) <<"Prime Numbers" <<endl;
    for(int i =2; i<1000; i++){
        if(isPrimeNumber(i))
            cout << std::setw(15) << i <<endl;
    }
}

bool isPrimeNumber(const int & num){
    int factorSum{0};
    for (int i{1}; i<num+1; i++){
        if(num % i == 0)
            factorSum += i;        
        if(factorSum > (num + 1))
            break;
        
            
    }
   return factorSum > (num + 1) ? false : true;
}