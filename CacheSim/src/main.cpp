#include <DirectMapped.hpp>
#include <Associative.hpp>
#include <IdealLRU.hpp>
#include <Random_replace.hpp>
int main(){
    int csize{8};
    int bsize{16};
    int assoc{4};
    int abit{32};

 
   //DirectMapped ;
    //std::unique_ptr<DirectMapped> che (new DirectMapped(csize, bsize, assoc,abit ) );
    // DirectMapped che(csize, bsize, 1 ,abit );
    // che.bDisplaySpec();

    // std::print("\n\n\n\n\n");
   //Associative che2(csize, bsize, assoc, abit);
   //che2.bDisplaySpec();

    Associative Che2(csize, bsize, assoc, abit);
    Che2.bDisplaySpec();

   
    Che2.InitialiseReplacementPolicy(std::make_unique<IdealLRU>(Che2));
    std::print("\n\n\n");
     Che2.bDisplaySpec();

    unsigned int addr1{0b10101011010011011110111100010010};
    unsigned int addr2{0b10101011110011011110111100010010};
    unsigned int addr3{0b10101001110011011110111100010010};
    unsigned int addr4{0b11101010110011011110111100010010};
    unsigned int addr5{0b11111110110011011110111100010010};
    unsigned int addr6{0b11110010111111011110111100010010};
    unsigned int addr7{0b10111111110111011110111100010010};
    unsigned int addr8{0b00000010110011011110111100010010};
    std::size_t A{static_cast<std::size_t>(addr1)};
     std::size_t B{static_cast<std::size_t>(addr2)};
      std::size_t C{static_cast<std::size_t>(addr3)};
       std::size_t D{static_cast<std::size_t>(addr4)};
         std::size_t E{static_cast<std::size_t>(addr5)};
         std::size_t F{static_cast<std::size_t>(addr6)};
         std::size_t G{static_cast<std::size_t>(addr7)};
         std::size_t H{static_cast<std::size_t>(addr8)};

    Che2.bRead(A);
    Che2.bRead(B);
    Che2.bRead(C);
    Che2.bRead(D);
    Che2.bRead(C);
    Che2.bRead(A);
    Che2.bRead(E);
    Che2.bRead(F);
    Che2.bRead(G);
    Che2.bRead(H);
   
  Che2.bDisplaySpec();

    
    

}