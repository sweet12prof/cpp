#include <DirectMapped.hpp>
#include <Associative.hpp>
#include <IdealLRU.hpp>
#include <Random_replace.hpp>
#include <FIFO_replace.hpp>
#include <stdexcept>
#include <DirectMappedNoTag.hpp>
#include <Sim.hpp>



int main(){
    int csize{16};
    int bsize{16};
    int assoc{1};
    int abit{64};

    std::string path {"C:\\pinatrace2.out"};
    TraceDrivenSim Sim(path);
    
    Associative Che2(csize, bsize, assoc, abit);
    Che2.InitialiseReplacementPolicy(std::make_unique<IdealLRU>(Che2));

  
   
    std::print("\n_____________Before Trace Drive___________\n");
    Che2.bDisplaySpec();
    Sim.processFile(Che2);
    std::print("\n_____________After Trace Drive___________\n");
    Che2.bDisplaySpec();


}



