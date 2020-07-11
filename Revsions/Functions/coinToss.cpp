#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

int coinToss ();
std::default_random_engine engine{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<int> randomInt{0, 1};
int main(){
    int hCount, tCount{0};
    for(int i=0; i < 100; i++){
        coinToss() == 1 ? hCount++ : tCount++;
    }
    cout <<"Head Count: "<<hCount<<endl;
    cout <<"Tail Count: "<<tCount<<endl;

}

int coinToss (){
    return randomInt(engine);
}