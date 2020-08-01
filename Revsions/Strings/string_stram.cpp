#include <iostream>
#include<sstream>
#include<string>
int main(){
    std::ostringstream someStream;
    someStream.width(5);
    std::string s1, s2;

    while (std::cin >> s1){
       someStream << "ChristopherColumbus";
       someStream.width(5);
    }

    std::cout.width(5);
    std::cout << someStream.str(); 

}