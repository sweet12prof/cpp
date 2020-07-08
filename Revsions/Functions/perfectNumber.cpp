#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

bool isperfectNumber(const int &);

int main(){
    cout<<endl << "Perfect numbers from 1-100: "<<endl;
    cout<< std::setw(15) << "Numbers"<<endl;
    for(int i=1; i<100; i++){
        if(isperfectNumber(i))
            cout << std::setw(15) << i<<endl;
    }
}

bool isperfectNumber(const int & num){
    int checkSum{0};
    for(int i = 1; i<num; i++){
        if(num % i == 0)
            checkSum += i;
    }
    return checkSum == num ? true : false; 
}