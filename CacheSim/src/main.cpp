#include <DirectMapped.hpp>
#include <Associative.hpp>
#include <IdealLRU.hpp>
#include <Random_replace.hpp>
#include <FIFO_replace.hpp>
#include <stdexcept>
#include <DirectMappedNoTag.hpp>

void DoRead(std::size_t&, Cache&);
void DoWrite(std::size_t&, Cache&);
void DoTest(std::vector<std::size_t>& , Cache&);

int main(){
    int csize{8};
    int bsize{16};
    int assoc{4};
    int abit{32};

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

  std::vector <std::size_t> someVec {A, B, C, D, E, F, G, H};


    Associative Che2(csize, bsize, assoc, abit);
    // Che2.bDisplaySpec();

    DirectMappedNoTag Che3(csize, bsize, assoc, abit);
    Che3.ValidateAllEntries();
   
    Che2.InitialiseReplacementPolicy(std::make_unique<IdealLRU>(Che2));
    std::print("\n_____________Before Trace Drive___________\n");
     Che2.bDisplaySpec();
    DoTest(someVec, Che2);
     std::print("\n_____________After Trace Drive___________\n");
    Che2.bDisplaySpec();

    std::print("\n\n");
    std::print("\n_____________Before Trace Drive___________\n");
    Che3.bDisplaySpec();
    DoTest(someVec, Che3);
    std::print("\n_____________After Trace Drive___________\n");
    Che3.bDisplaySpec();




}



void DoRead(std::size_t& address, Cache& assoCache){
  assoCache.bRead(address);
}

void DoWrite(std::size_t& address, Cache& assoCache){
  assoCache.bWrite(address);
}


void DoTest(std::vector<std::size_t>& stimVec, Cache& Cache1){
    int f =static_cast<int> (stimVec.size()); f--;
    std::uniform_int_distribution dist1{0, f};
    std::uniform_int_distribution dist2{0, 1};
    std::random_device rd2;
    std::mt19937 engine1{rd2()};
    int j{0};
    int rCount{0}, wCount{0};
    // std::mt19937 engine2{rd2()};

    for(auto i{0}; i <100; i++){
      bool abs = static_cast<bool>(dist2(engine1));
      switch(abs){
        case true : 
          j = dist1(engine1);
          try {
          DoRead(stimVec.at(j), Cache1);
          rCount++;
          } catch(std::exception ex){
            ex.what();
          }
          break;
        
        case false: 
           j = dist1(engine1);
           try{
            DoWrite(stimVec.at(j), Cache1);
            wCount++;
           }catch( std::exception ex){ex.what();}
           break;
      }
    }
    
      if(rCount != Cache1.getReadNum() || wCount != Cache1.getWriteNum())
          std::print("Error Somewhere, accesses not matching with that in stimulus drive");


}