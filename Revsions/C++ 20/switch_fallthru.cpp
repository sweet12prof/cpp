#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int A,B,C,F{0};
    int grade;
    double Tgrade, average{0};
    int courseCount{0};

    while(cin >> grade){
        switch(grade / 10) {
            case 7 : [[fallthrough]]
            case 8 : [[fallthrough]]
            case 9 : [[fallthrough]]
            case 10: 
                     A++;
                     break;
            case 6 : 
                     B++;
                     break;
            case 5 :
                     C++;
                     break;
            default:
                     F++;
                     break;
        }
            Tgrade += grade;
            courseCount++;
    }

    average = Tgrade / courseCount;
    cout << std::setw(12) << "A :" << std::setw(5) << A <<endl;
    cout << std::setw(12) << "B :" << std::setw(5) << B <<endl;
    cout << std::setw(12) << "C :" << std::setw(5) << C <<endl;
    cout << std::setw(12) << "F :" << std::setw(5) << F <<endl;
    cout << std::setw(12) << "Average :" << std::setw(5) << average;
} 