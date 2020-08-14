#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iterator>
#include <ranges>

 
    void  printMap(const std::map <int, std::string, std::less<int>> &);
int main(){
    std::map <int, std::string, std::less<int>> mapCont{{10, "Chris"}, {11, "Melod"}, {-2, "mcMac"}, {-2, "mcNuts"}};

    auto p{ mapCont.insert(std::pair{10, "Dimebag"} ) };
    printMap(mapCont);

    std::cout << std::endl << std::endl << std::endl << "Element " << (p.second ? "has been inserted" : "already exists") << "\nThat element is " \
              << (*p.first).first << " " << (*p.first).second << std::endl;

    mapCont[10] = "AttaGob3";
    mapCont[20] = "WaakyeBase";

    printMap(mapCont);

    auto pis = mapCont.find(10);

    if(pis == mapCont.end())
        std::cout << std::endl << "Element not found " << std::endl;
    else 
        std::cout << "Element found is " << (*pis).first << " " <<pis->second << " " << std::endl; 


    
}

 void  printMap(const std::map <int, std::string, std::less<int>> & someMap){
     for(auto item : someMap){
         std::cout << item.first << " " << item.second;
         std::cout << std::endl;
     }
        
 }