#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main(){
    double principal{1000.00};
    double rate{0.05};
    cout << std::fixed << std::setprecision(2); 
    cout<<"Principal :" << std::setw(10) << principal << endl;
    cout<<"     Rate :" << std::setw(10) << rate << endl << endl;

    cout << "Year" << std::setw(20) << "Amount on deposit"<<endl;
    double amount{0};
    for(int i{1};  i<=10; i++)
    {
        amount = principal * pow((1 + rate), i);
        cout << std::setw(4) << i << std::setw(20) << amount <<endl;
    }

}
