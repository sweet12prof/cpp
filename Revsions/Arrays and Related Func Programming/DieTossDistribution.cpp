#include <iostream>
#include <array>
#include <numeric>
#include <ctime>
#include <random>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::array;

std::default_random_engine engine {static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<int> randomInt (1, 6);

int RollDice();
int addFunc(const int & x, const int & y);

int main(){
    array <int, 11> possibleOutcomes{0};
    for(int i=0; i<36'000'000; i++) {
            possibleOutcomes[RollDice() - 2] ++;
    }

    cout << "Outcomes" << std::setw(15) << "frequency" << std::setw(15) << "\%" << endl;
    cout << std::setprecision(2);
    for(int i=0; i<11; i++)
        cout << std::setw(8) << i+2 << std::setw(15) << possibleOutcomes[i] << std::setw(15) << (double)possibleOutcomes[i]/36'000'000<<endl; 

    cout << endl<<endl << "tryin smth out " << endl << endl << endl ;

    int sum { std::accumulate(begin(possibleOutcomes), end(possibleOutcomes), 0, 
    [](const int & x, const int & y) 
    {
        return x  + y;
    }
    )};
    cout << "sum is " << sum <<endl;
}

inline int RollDice(){
    return randomInt(engine) + randomInt(engine);
}

int addFunc(const int & x, const int & y ){
    return x + y;
}