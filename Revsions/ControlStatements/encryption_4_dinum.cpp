#include <iostream>
using std::cin;
using std::cout;
int main(){
    int num, MSb4,MSb3,MSb2, MSb1{0};
    cout << "Enter num: ";
    cin >> num;

    MSb4 = num /1000;
    MSb3 = (num - (MSb4 * 1000)) / 100;
    MSb2 = (num - (MSb4 * 1000) - (MSb3 * 100))/10;
    MSb1 = (num - (MSb4 * 1000) - (MSb3 * 100) - (MSb2 * 10));

    MSb4 = ((MSb4 + 7) % 10);
    MSb3 = ((MSb3 + 7) % 10);
    MSb2 = ((MSb2 + 7) % 10);
    MSb1 = ((MSb1 + 7) % 10);

    int newNum = (MSb2 * 1000 ) + (MSb1 * 100) + (MSb4 * 10) + MSb3;

    cout << "New number is : " << newNum;
    cout << std::endl;

}