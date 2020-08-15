#include <iostream>
#include <vector>
#include <iterator>

bool ispalindromePair( std::vector<int>);
bool ispalindromePair2(const std::vector<int>::iterator, const std::vector<int>::iterator );
int main(){
    std::vector<int> someVec = {1,2,5, -2, -3,2,1};
 
    std::vector<int>::iterator fbegin{someVec.begin()};
    std::vector<int>::iterator fend{someVec.end()};



    std::cout << (ispalindromePair2(fbegin, fend) ? "The vector is a palindrome" : "The vector is not a palindrome");
}

 bool ispalindromePair(std::vector<int> someVec){
    if(someVec.begin() == (someVec.end() - 1))
        return true;

    else if(*someVec.begin() ==  *(someVec.end() - 1)) {
        std::cout << *someVec.begin() << " is equal to " << *(someVec.end() - 1) << std::endl;
        std::vector <int> newVec {(someVec.begin() + 1), (someVec.end() - 1)};
           if(newVec.size() >= 1 ) return true && ispalindromePair(newVec); else return true;
    }
    
   else 
        return false;
       
 }

 bool ispalindromePair2(const std::vector<int>::iterator fbegin, const std::vector<int>::iterator fend){
     
     if( fbegin == fend)
        return true;

     else if(fbegin == fend - 1){
         return true ;
     }

     else if(*fbegin == *(fend - 1)){
         std::vector<int>::iterator fbegin2 = fbegin + 1;
         std::vector<int>::iterator fend2 = fend - 1;
         return true && ispalindromePair2(fbegin2, fend2);
     }

    
     
     else 
        return false;
        

 }