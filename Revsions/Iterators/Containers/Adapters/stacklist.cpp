#include <iostream>
#include <stack>
#include <iterator>
#include <list>
#include <string>
#include <vector>

template <typename T>
    void pushStack(T &);
template <typename T>
    void popStack(T &);
int main(){
    std::stack <int, std::vector <std::string>> listStringStack;
    pushStack(listStringStack);
    popStack(listStringStack);
}

template <typename T>
    void pushStack(T & someRef){
        int i{0};
        std::cout <<"Pushing : ";
        while(i != 10)
        {
            std::string a = "Chris";
           // for(char item : a)
                someRef.push(a);
            ++i;
            std::cout << a <<" ";
        } 
        std::cout << std::endl;
    }

template <typename T>
    void popStack(T & someRef){
        std::cout << std::endl << std::endl << "Popping : " ;

        while(!someRef.empty()){
            //std::cout << someRef.top() << " ";
            for(auto item : someRef.top())
                std::cout << item ;
            std::cout << " ";
            someRef.pop(); 
        }
        if(someRef.empty())
            std::cout << "Stack is empty";
        
    }