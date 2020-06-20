#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int a {10};
    int b{0};
    while (a < 10){
        if(a < 9) [[likely]]{
            b++;
        }
        else 
            b--;
    }
    cout << "B is " + b <<endl;
}