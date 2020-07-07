#include <iostream>
using std::cin;
using std::cout;

int main(){
    cout << "Enter 5digit number : ";
    int num; 
    cin >> num;

    int MSb_5, MSb_4, MSb_3, MSb_2, MSb_1 {0};

    MSb_5 = num / 10000;
    MSb_4 = (num - (MSb_5 * 10000))/1000;
    MSb_3 = (num - (MSb_5 * 10000) - (MSb_4 * 1000)) / 100;
    MSb_2 = (num - (MSb_5 * 10000) - (MSb_4 * 1000) - (MSb_3 * 100))/10;
    MSb_1 = (num - (MSb_5 * 10000) - (MSb_4 * 1000) - (MSb_3 * 100) - (MSb_2 * 10));

    if((MSb_1 == MSb_5) && (MSb_4 == MSb_2)) 
        cout << "Input is a palindrome";
    else 
        cout << "Input is not a palindrome";

    cout << std::endl;
}