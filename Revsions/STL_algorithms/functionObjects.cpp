#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>

template <typename T>
class sumClass {
    public :
        T operator () (const T & Total, const T & value ){
            return Total + (value * value);
        }
};

int main(){
    int i{0};
    std::vector <int> newVec {19, 0, 2, -4, 6};
    std::generate(newVec.begin(), newVec.end(), [& i](){
        ++i;
        return i * i;
    });
   

    std::ostream_iterator <int> Output {std::cout, " "};

    
    std::copy(newVec.begin(), newVec.end(), Output);
    std::cout << std::endl;

    int result = std::accumulate(newVec.begin(), newVec.end(), 1, sumClass<int>{});

    //std::copy(newVec.begin(), newVec.end(), Output);
    std::cout << "\n the result is " << result;
}