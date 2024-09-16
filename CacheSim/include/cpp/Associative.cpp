#include <Associative.hpp>

Associative::Associative(const int& cSize, const int& bSize,  const int& assoc, const int& abits)
:Cache(cSize, bSize, assoc, abits), flatIndex{static_cast<std::size_t>(this->numOfentries * assoc)}, 
ReplacePolicy{nullptr}
{
    cacheline defline;
    //line.reserve(flatIndex);
    for (std::size_t i{0}; i<this->flatIndex; i++)
        this->line.push_back(defline);
}

void Associative::InitialiseReplacementPolicy(std::unique_ptr<ReplacementPolicy> PolicyArg){
    ReplacePolicy = std::move(PolicyArg);
}

void Associative::displaySpec()const{
   std::print("Replacement Policy      : {}\n", this->ReplacePolicy == nullptr ? "Not Initialised" : this->ReplacePolicy->policyName());
}

void Associative::Read(const std::size_t& indexAddr ){ 
    std::size_t address {this->getIndex_i(indexAddr) * this->getassoc()};
    std::string tagBits  {this->getTag(indexAddr)};

    int wayfound{-1};
    for(std::size_t i{address}; i<address+this->getassoc(); i++){ //Look for an associative match
        if(this->line.at(i).validBit == '1'){
            if(this->line.at(i).tag == tagBits){
                wayfound = i-address;
                ReplacePolicy->trackLRU(address, (i-address));
                this->hits++;
                break;
            }
        }
    }

    if(wayfound == -1){ //ASSOCIative match missed
         this->misses++;
         for(std::size_t i{address}; i<address+this->getassoc(); i++){ //Look for an unused way
            if(this->line.at(i).validBit == '0'){
                this->line.at(i).validBit = '1';
                this->line.at(i).dirtyBit = '0';
                this->line.at(i).tag   = tagBits;
                this->ReplacePolicy->trackLRU(address, (i-address));
                wayfound = (i-address);
                break;
            }
        }

        if(wayfound == -1){ //If there wasnt any unused way, look for LRU
            std::size_t i = ReplacePolicy->Replace(address);
            std::size_t addr{address + i};
            this->line.at(addr).validBit = '1';
            this->line.at(addr).dirtyBit = '0';
            this->line.at(addr).tag   = tagBits;
        }
    } 
}

void Associative::Write(const std::size_t& indexAddr){  
    std::size_t address {this->getIndex_i(indexAddr) * this->getassoc()};
    std::string tagBits  {this->getTag(indexAddr)};

    int wayfound{-1};
    for(std::size_t i{address}; i<address+this->getassoc(); i++){ //Look for an associative match
        if(this->line.at(i).validBit == '1'){
            if(this->line.at(i).tag == tagBits){
                wayfound = i-address;
                ReplacePolicy->trackLRU(address, (i-address));
                this->hits++;
                this->line.at(i).dirtyBit = '1';    //mark dirty
                break;
            }
        }

        if(wayfound == -1){ //ASSOCIative match missed
         this->misses++;
         for(std::size_t i{address}; i<address+this->getassoc(); i++){ //Look for an unused way
            if(this->line.at(i).validBit == '0'){
                this->line.at(i).validBit = '1';
                this->line.at(i).dirtyBit = '1';
                this->line.at(i).tag   = tagBits;
                this->ReplacePolicy->trackLRU(address, (i-address));
                wayfound = (i-address);
                break;
            }
        }

        if(wayfound == -1){ //If there wasnt any unused way, look for LRU
            std::size_t i = ReplacePolicy->Replace(address);
            std::size_t addr{address + i};
            this->line.at(addr).validBit = '1';
            this->line.at(addr).dirtyBit = '1';
            this->line.at(addr).tag   = tagBits;
        }
    } 
    }
}
