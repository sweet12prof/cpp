#include <print>
#include "Acc.hpp"
#include <fstream>
#include <ranges>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main(int argC, const char* argv[]){
   
   using namespace std;
   fstream file {"somefile.txt", ios::app  | ios::in} ;
    // std::string f{"ab"}, l{"ab"};
//     char abs[]{"abcdefghij\n"};
//   //   Account blankAcc("ab", "ab", 12);
//       auto iter = std::views::iota(1, 11);
//     if(file)
//         for(auto item : iter ){
//             file.write(abs, sizeof(abs));
//         }
        
//     //    char *buffer[1024]{};
    //    array <Account, 1024> buffer{}; 
       
    //    fstream file2 {"somefile.bin",   ios::in | ios::binary} ;
    //     size_t trackRev{0};
    //     for(auto &item : buffer)
    //     {
    //         if(file2.good()) 
    //             {
    //                 file2.read(reinterpret_cast<char *>(&item), (sizeof(Account)));
    //                 trackRev++;
    //             }
    //         else 
    //             break;
    //     }
        
    //    // print("\n");
    //     for (size_t i{0}; i<trackRev - 1; i++)
    //         print(" {:<10} {:<10} {:>5} \n", buffer[i].getfName(), buffer[i].getlName(), buffer[i].getAge());
        //std::string a {Acc.getfName()};
    //std::print("\n {} ", Acc.getfName().c_str());
            
    //    char somechar[1024]{0};
    //    fstream file2 {"somefile.txt",   ios::in } ;
       
      
       

    //          file2.read(somechar, 60);


    //     std::cout.write(somechar, 60);
   
    // Account someAcc
    {
        using namespace std;

        // std::vector<char> buffer(100, 0);
        //  std::vector<std::string> buffer2;
        // std::stringstream abs;
        // file.read(buffer.data(), 96);
        // //print("\n");
        // for(auto item : buffer)
        //     {   
        //      print("{}", item);
        //         if(item != '\0' && item != '\n' )
        //             abs << item;

        //         if((item == '\0' || item == '\n' ) && !abs.str().empty())
        //         {
        //             buffer2.push_back(abs.str());
        //             abs.str("");
        //         }
        //     }
        //  print("\n\n");
        // for(auto item : buffer2)
        // {
        //      print("{}\n", item);
        //   //   print("babs\n");
        // }   

        //  std::string a{\n}

        char someChar[20];
        std::string someStack{};
        std::cin.get(someChar, 20, '\n');
        print("{}", someChar);
    }

    

  
}
