#include <iostream>
using std::cin;
using std::cout;
int main(){
    int size, count, secondCount{0};
    cout <<"Square size: ";
    cin >> size;
    
    
    while(count != size){
        secondCount = 0;

        if((count == 0 ) || (count == size - 1)){
            //cout <<"second count is "<<secondCount;
            while (secondCount !=  size)
                
                {
                    //cout << "Here1";
                    cout << "*";
                    secondCount++;
                }
            cout << std::endl;
        }
        else
       {
             while (secondCount !=  size)
                
                {
                    if(secondCount == 0 || secondCount == size - 1)
                    cout << "*";
                    else 
                    cout << " ";
                    secondCount++;
                }
             cout << std::endl<< std::endl;
       }
       
        
        count++;
    }
}