#include <Cache.hpp>

Cache::Cache(const int& cSize, const int& bSize, const int& assoc, const int& aBits)
:cacheSize{cSize}, associaticity{assoc}, blockSize{bSize}, addressBits{aBits}, hits{0}, misses{0}, writeNum{0}, readNum{0}{
    this->numOfentries = ((cSize * 1024)/(bSize * assoc));
    this->indexBits = log2(this->numOfentries);
    this->offsetBits = log2(bSize);
    this->tagBits = this->addressBits - (this->indexBits + offsetBits);
    // this->engine(rd);
}

void Cache::bRead(const std::size_t& address){
    this->readNum++;
    this->Read(address);
}

void Cache::bWrite(const std::size_t & address){
    this->writeNum++;
    this->Write(address);
}

void  Cache::bDisplaySpec() const{
    std::print("Cache Size in bytes         : {}\n", this->cacheSize);
    std::print("Associativity               : {}\n", this->associaticity);
    std::print("BlockSize                   : {}\n", this->blockSize);
    std::print("Number of Entries           : {}\n", this->numOfentries);
    std::print("Number of TagBits           : {}\n", this->tagBits);
    std::print("Number of Hits              : {}\n", this->hits);
    std::print("Number of Misses            : {}\n", this->misses);
    std::print("Number of Write Accesses    : {}\n", this->writeNum);
    std::print("Number of Read Accesses     : {}\n", this->readNum);
    std::print("Hit Ratio                   : {:.2f}\n", static_cast<float>(this->hits)/(this->writeNum+this->readNum));
    std::print("Miss Ratio                  : {:.2f}\n",  static_cast<float>(this->misses)/(this->writeNum+this->readNum));
    displaySpec();
}

std::string Cache::getIndex(const unsigned int& address) const{
    std::bitset<Cache::aBus>addr(address);
    std::bitset a {(((addr << tagBits) >> tagBits)>>offsetBits)};
    return a.to_string().substr((this->aBus - this->indexBits), this->indexBits);
}

std::string Cache::getTag(const unsigned int& address) const{
    std::bitset<Cache::aBus>addr(address);
    std::bitset a {(addr>> this->offsetBits)>>this->indexBits};
    return a.to_string().substr((this->aBus - this->tagBits), this->tagBits);
}

std::size_t Cache::getIndex_i(const unsigned int& address) const{
    std::bitset<Cache::aBus>addr(address);
    std::bitset a {(((addr << tagBits) >> tagBits)>>offsetBits)};
    return static_cast<std::size_t>(a.to_ulong());
}