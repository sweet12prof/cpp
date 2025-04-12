
#include <iostream>
#include <print>
#include <format>
#include <ranges>
#include <array>
#include <numeric>
#include <cmath>
#include <vector>
#include <random>

    template <typename T>
    T maximumVal(T val1, T val2, T val3){
        T maxVal{val1};
        
        if(val2 > maxVal)
            maxVal=val2;
        
        if(val3 > maxVal)
            maxVal=val3;
        
        return maxVal;
    }

void someFunc(const auto & );

int main(){
    double a{5};
    int  b{3};
    // std::print(" {1} Hello World {2}", b, a);
    std::print("some guy \n{1:>7.3f}", a, static_cast<double>(b));

    std::print("\n");
    
        using std::array;
        array someArr{0, 1, 2, 3, 4, 5, 6, 7, 8};
        std::cout << std::accumulate(someArr.begin(), someArr.end(), 1, 
        [](const auto &x, const auto &y){
            return x + 2 * y;
        }
        );

        std::print("\n");

        auto someArr2 {std::views::iota(1, 11)};
        auto printVal{[](auto & someVal){
            for(const auto &item : someVal){
                //std::cout << item <<  " " ;  
                std::print("{0:>4} ", item);
            }
        }};

        printVal(someArr2);

         std::print("\n");

         auto SqauredVals{someArr2 | std::views::transform([](const auto &someval){
            return std::pow(someval, 2);
         })};
        
        printVal(SqauredVals);

         auto filterEven{ someArr2 | std::views::filter([](const auto & someval){
            return someval %2 == 1;
         })};

       std::print("\n");
        
       printVal(filterEven);


    std::vector <int> someVec(1);
 //   someVec(20);
    std::print("\n");

     {
        using std::print;
        print("size of Vec is {}", someVec.size());
        std::print("\n");
        int input = 0;
        while(std::cin >> input){
            someVec.push_back(input);
        }
        print("size of Vec is {}", someVec.size());
        printVal(someVec);
     }




        
    

    std::print("\n");
    std::cout << maximumVal(1.0, 20.5, 3.0);
    

    std::print("\n");
    std::cout << maximumVal('Z', 'E', 'F');
    std::cout << maximumVal("CHRIS", "elod", "absbsbsbsbs");


    
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    static std::uniform_int_distribution dist{1, 10};
    
        std::print("\nRandom Numbers: ");
    
        for(std::size_t i{0}; i<10; i++)
            std::print("{:<2} ", dist(engine));
    
    someFunc(someArr2);

   
}


void someFunc(const auto & refArray){
    std::print("\nsize is {} \n", refArray.size());
    for (auto item : refArray)
        std::print("{:<2} ", item);
}