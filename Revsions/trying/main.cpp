#include <iostream>
#include <bitset>
#include <random>
#include <print>

int funcAdd (int, int);
int main(){
    const int a{5}, b{6};
    constexpr int someVal {a * b};

    
    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist{1, 6};

    int randNum{dist(engine)};

    std::bitset<someVal> binNum(randNum);
    int val2{funcAdd(randNum, randNum+5)};
    std::print("randNum: {}\nRandNum in Bits: {}\nVal2: {}\n", randNum, binNum.to_ulong(), val2);

}

int funcAdd(int a, int b){
    a+=3;
    return a +b;
}