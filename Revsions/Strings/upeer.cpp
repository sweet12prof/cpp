#include <iostream>
#include <string>
#include <ctype.h>

int main(){
    char *name;
    std::cout <<"Enter name: ";
    std::cin >> name;

    std::string_view namePtr{name};

    for(auto item : namePtr)
            std::cout<<(char)toupper(item); 
}