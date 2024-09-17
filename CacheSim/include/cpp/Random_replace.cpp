#include <Random_replace.hpp>

RandomReplacement::RandomReplacement(Associative& baseArg)
: randWay{-1}
{
    this->associativity = baseArg.getassoc();   
}

int RandomReplacement::Replace(const std::size_t& address){
   RandomReplacement::trackLRU(0, 0);
   return this->randWay;
}


std::string RandomReplacement::policyName(){
    return "Random Replacement Policy";
}

 void RandomReplacement::trackLRU(const std::size_t & address, const int& way) {
    std::uniform_int_distribution dist{0, this->associativity-1};
    this->randWay = dist(engine);
 };