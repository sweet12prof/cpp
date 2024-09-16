#include <DirectMapped.hpp>

DirectMapped::DirectMapped(const int& cSize, const int& bSize,  const int& assoc, const int& abits)
:Cache(cSize, bSize, assoc, abits) {
    cacheline defline;
    line.reserve(this->numOfentries);
    for (std::size_t i{0}; i<numOfentries; i++)
        line.push_back(defline);
}

void DirectMapped::displaySpec() const{} 



void DirectMapped::Read(const std::size_t& address){
    std::size_t indexAddr {DirectMapped::getIndex_i(address)};
    std::string tagBits{DirectMapped::getTag(address)};
    if(this->line.at(indexAddr).validBit == '0'){ //no valid data at location, read miss
        this->misses++;
        this->line.at(indexAddr).validBit = '1';
        this->line.at(indexAddr).dirtyBit = '0';
        this->line.at(indexAddr).tag      = tagBits;
    } else{
        if(this->line.at(indexAddr).tag != tagBits){ //valid data but miss, read miss
            this->misses++;
            this->line.at(indexAddr).dirtyBit  = '0';
            this->line.at(indexAddr).tag       = tagBits; 
        }
        else {  //valid data and hit, read hit
            this->hits++;
        }
    }
} 


void DirectMapped::Write(const std::size_t& address){
    std::size_t indexAddr {DirectMapped::getIndex_i(address)};
    std::string tagBits{DirectMapped::getTag(address)};
     if(this->line.at(indexAddr).validBit == '0'){ //no valid data at location, write miss
        this->misses++;
        this->line.at(indexAddr).validBit = '1';
        this->line.at(indexAddr).dirtyBit = '1';
        this->line.at(indexAddr).tag      = tagBits;
    } else{
        if(this->line.at(indexAddr).tag != tagBits){ //valid data but miss
            this->misses++;
            this->line.at(indexAddr).dirtyBit  = '1';
            this->line.at(indexAddr).tag       = tagBits; 
        }
        else {  //valid data and hit
            this->hits++;
            this->line.at(indexAddr).dirtyBit  = '1';
        }
    }
}