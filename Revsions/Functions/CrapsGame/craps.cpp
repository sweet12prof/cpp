#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

std::default_random_engine engine{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<int> RandomInt (1, 6);

int generateRandomNumber();
int numOnSpinFunc();
void spinFunc();


int main(){
    int numOnSpin, point, input {0};
    enum class status {CONTINUE, WON, LOST};
    status gameStatus;
    numOnSpin = numOnSpinFunc();

    switch (numOnSpin){
        case 7:     [[fallthrough]]
        case 11:
                gameStatus = status::WON;
                break;
        case 2:      [[fallthrough]]
        case 3:      [[fallthrough]]
        case 12:    
                gameStatus = status::LOST;
                break;
        case 4 :    [[fallthrough]]
        case 5 :    [[fallthrough]]
        case 6:     [[fallthrough]]
        case 8:     [[fallthrough]]
        case 9:     [[fallthrough]]
        case 10:   
            gameStatus = status::CONTINUE;
            cout<<"Your point is "<< numOnSpin<<endl;
            point = numOnSpin;
            break;
        default:
            gameStatus = status::LOST;
    }

    while(gameStatus == status::CONTINUE){
        cout << "You havent made your point, Toss? ";
        cin>>input;
        //cout<<endl;
        if(input == 1)
            {
                numOnSpin = numOnSpinFunc();
                if(numOnSpin == point)
                    gameStatus = status::WON;
                else if(numOnSpin == 7)
                    gameStatus = status::LOST;     
                

            }
    }

     if(gameStatus == status::WON){
                cout<<"You made ya point, WON!"<<endl;
                
            }
                
            else {
                    cout <<"You lost bruh!"<<endl;
                    
            }
                
    
        
    
}

int generateRandomNumber(){
    return RandomInt(engine);
}


int numOnSpinFunc(){
    int num = generateRandomNumber() + generateRandomNumber();
    cout << "You rolled: " << num << endl;
    return num;
}