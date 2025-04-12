#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <array>
#include <span>
int main(int argc, char *argv[]){
    std::cout << argc << "arguments\n";
    std::vector<std::string> cmdArgs;
    for (int i{1}; i<argc; i++)
        cmdArgs.push_back(argv[i]);
    

    auto displayArr{[]( auto &item){
       for(const auto&items : item)
        std::cout << items << " ";
    }};
    displayArr(cmdArgs);
}