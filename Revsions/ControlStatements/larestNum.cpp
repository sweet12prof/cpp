#include <iostream>
//using std::cout;
//using std::cin;

int main(){
    int input, count {0};
   
    int largestnum {0};
    while(std::cin >> input){
        
        if(count == 10)
            break;
        if(input > largestnum)
            largestnum = input;
        count++;
    }
    std::cout << "largest Number is: " << largestnum;
}