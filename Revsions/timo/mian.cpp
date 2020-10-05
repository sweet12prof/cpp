#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
unsigned int someint = (int)'A';
void returnChar(unsigned int, std::string &);

int main(int argc, char * argv []){

unsigned int input =  std::stoul(argv[1]);
std::string result ="";
    returnChar(input, result);

    std::ostream_iterator <char> output {std::cout, ""};
    std::copy(result.rbegin(), result.rend(), output);
}


void returnChar(unsigned int quotient, std::string & result ){
        if(quotient > 25)
            {
                result.push_back ( char( (quotient % 26) + someint) );
                return returnChar(((quotient / 26) - 1), result);
            }
        else if (quotient < 26)
                  result.push_back (char (quotient + someint) );
}