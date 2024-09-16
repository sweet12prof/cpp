#include <IdealLRU.hpp>

IdealLRU::IdealLRU(Associative& assocPtr)
{
    this->associativity =  assocPtr.getassoc();
    this->flatIndex     =  assocPtr.getFlatIndex();
    this->numOfEntries  =  assocPtr.getNumOfEntries();
    
    for(std::size_t i{0}; i < (this->flatIndex); i++){
        handlingMeta.push_back(0);
    }
}

void IdealLRU::trackLRU(const std::size_t& addr, const int& way){
    for(std::size_t i{addr}; i < addr + this->associativity; i++)
        if(i == addr+way)
            handlingMeta.at(i) = 0;
        else 
           handlingMeta.at(i)++;
}


int IdealLRU::Replace(const std::size_t  &addr){
    std::vector <int> assocLine;
    
    for(std::size_t i{addr}; i < addr + this->associativity; i++)
       assocLine.push_back(handlingMeta.at(i));
   
    auto lruWayPtr = (std::max_element(assocLine.begin(), assocLine.end()));
    
    int maxIndex = std::distance(assocLine.begin(), lruWayPtr);
    
    this->trackLRU(addr, maxIndex);
    return maxIndex;
 }

 std::string IdealLRU::policyName(){
    return "Least Recently Used";
 }



//    //DirectMapped ;
//     //std::unique_ptr<DirectMapped> che (new DirectMapped(csize, bsize, assoc,abit ) );
//     DirectMapped che(csize, bsize, 1 ,abit );
//     che.bDisplaySpec();

//     std::print("\n\n\n\n\n");
//    //Associative che2(csize, bsize, assoc, abit);
//    //che2.bDisplaySpec();

//     Associative Che2(csize, bsize, assoc, abit);
//     Che2.bDisplaySpec();

   
//     Che2.InitialiseReplacementPolicy(std::make_unique<IdealLRU>(Che2));
//     std::print("\n\n\n");
//      Che2.bDisplaySpec();