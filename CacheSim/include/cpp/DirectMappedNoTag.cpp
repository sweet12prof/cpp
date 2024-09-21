#include <DirectMappedNoTag.hpp>

DirectMappedNoTag::DirectMappedNoTag(const int& cSize, const int& bSize,  const int& assoc, const int& abits)
:Cache(cSize, bSize, 1, abits) {
    cacheline defline;
    line.reserve(this->numOfentries);
    for (std::size_t i{0}; i<numOfentries; i++)
        line.push_back(defline);
}


void DirectMappedNoTag::displaySpec() const{}

void DirectMappedNoTag::Read(const std::size_t& address){
    std::size_t indexAddr {DirectMappedNoTag::getIndex_i(address)};
    if(this->line.at(indexAddr).validBit == '0') {
        this->misses++;
        this->misses++;
        this->line.at(indexAddr).validBit = '0';
        this->line.at(indexAddr).dirtyBit = '0';
        this->line.at(indexAddr).tag      = "";
    }else {
        this->hits++;
        this->read_hits++;
    }
   
} 


void DirectMappedNoTag::Write(const std::size_t& address){
     std::size_t indexAddr {DirectMappedNoTag::getIndex_i(address)};
    std::string tagBits{DirectMappedNoTag::getTag(address)};
     if(this->line.at(indexAddr).validBit == '0'){ //no valid data at location, write miss
        this->misses++;
        this->write_misses++;
        this->line.at(indexAddr).validBit = '0';
        this->line.at(indexAddr).dirtyBit = '0';
        this->line.at(indexAddr).tag      = "";
    } else{
            //valid data and hit
            this->hits++;
            this->write_hits++;
    }
}

void DirectMappedNoTag::ValidateAllEntries(){
    for(auto& item: this->line)
        item.validBit = '1';
}
