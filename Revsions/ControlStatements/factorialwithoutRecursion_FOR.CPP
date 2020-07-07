#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
int main(){
    long fact{1};
    cout << "Num" << std::setw(25) << "Factorial"<<std::endl;

    for(int i=1; i<21; i++){
        for(int j = i; j>0; j--){
            fact *= j;
        }
        cout << std::setw(3) << i << std::setw(25) << fact;
        cout << std::endl;
        fact = 1;
    }
        

}