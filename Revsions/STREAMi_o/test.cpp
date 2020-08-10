#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;
int main(){

    // char someChar; 
    // char  anotherChar = 'c';
    char anotheCharPtr[10];

    char receiveInput;

    // std::string_view someStr{anotheCharPtr};
    // char * receiveInput;
    // std::string token;
    // std::string someStr = "Chris is a fool ";
    // while((someChar = cin.get())){
    //     if(someChar != ' ')
    //         token += someChar;
    //     else {
    //         cout << "Token is : " << token << std::endl;
    //         token = "";
    //     }
    // }


     
//     someChar = cin.get( );
//     //* anotheCharPtr
//    cout << "anotherChar Ptr is of size  : " << std::boolalpha << /* someStr.length() <<  " "*/  ( ( someChar == ' ') ? "True space there" : " Nah lie" ) ;
    //cout <<



        


        //cout << "Inputted String was: " << anotheCharPtr;

    //    std::stringbuf strBuf {"some String"};
    //    cin.get(strBuf);

    //    cout << strBuf.str();
       
    //    std::streambuf someBuff;
    //    someBuff.

    std::stringstream someStream;
    std::string token;
    someStream << "Chris is a fool ^z";
    char inp ;
    int CurrentPointer = 0;
    while((inp = someStream.get()) != EOF){
        if(inp != ' '){
            token += inp;
            CurrentPointer++;
        }
        else {
            cout << "Token is:  " << token << "\nToken length is: " << token.size() << std::endl << std::endl;
            token = "";
            std::string someString = someStream.str();
            someString =  "" + someString.substr(++CurrentPointer, someString.size() - 1);
            someStream.str("");
            someStream << someString;
            CurrentPointer = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        }
    }
}