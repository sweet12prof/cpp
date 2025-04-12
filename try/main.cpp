#include <iostream>
int main(){ 
    int a, b, c, i = 0;
    std::cin  >> a >> b; 
    int * intPtr = new int[a +b]{};
    while( (std::cin >> c) && (i < (a+b))){
        intPtr[i] = c;
    }
}