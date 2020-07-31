#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;
string encrypt(string, int);
std::string decrypt(string );
int main()
{
    std::cout << "Enter string for encryption: " << std::endl;
    
   string newString, encryptedString;
   std::getline(std::cin, newString);
   encryptedString = decrypt(newString);
   cout << "Encrypted String is: "<< encryptedString;
}

std::string encrypt(std::string somestring, int key){
    std::string alphaArray {"abcdefghijklmnopqrstuvwxyz "}; 
    
    std::string newString;

    cout << somestring.size() << std::endl;
    for(auto & item : somestring){
        newString += alphaArray[(alphaArray.find(item) + 3) % (alphaArray.size() )];
    }
            

    return newString;
}


std::string decrypt(std::string someString){
    std::string alphaArray {"abcdefghijklmnopqrstuvwxyz "}; 
    std::string newString;

    for(auto item : someString)
    {
        newString += alphaArray[(alphaArray.find(item) % (alphaArray.size())) - 3];
    }
    return newString;
}