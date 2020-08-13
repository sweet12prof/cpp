#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iterator>

int main(){
    std::multimap< int, double, std::less<int>> Firstmap{{1, 23.98}, {2, 2.0}, {2, 0.5}};

    std::cout << "There are : " << Firstmap.count(2) << " Key pairs" << std::endl;

    Firstmap.insert(std::make_pair(1, 0.3));
    Firstmap.insert({15, 12.56});

    for(auto item : Firstmap)
        std::cout << item.first << "\t" << item.second << std::endl;;

    // auto someVal = Firstmap.find(2);
    // if(someVal == Firstmap.end())
    //     std::cout << "The key value pair does not exist" << std::endl;
//     else 
//         {
//             for(auto item : someVal)
//                 std::cout << someVal;
//         }
// }
    // auto res = Firstmap[2];

    // for(auto item : Firstmap)
    //     std::cout << *item.First << "\t" << *item.sedond;
    
}