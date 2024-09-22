#include <Sim.hpp>
#include <cstdint>
#include <bitset>


//using namespace std::string_literals;

std::ifstream TraceDrivenSim::FILE;

TraceDrivenSim::~TraceDrivenSim(){
    TraceDrivenSim::FILE.close();
}

TraceDrivenSim::TraceDrivenSim(const std::string& path)
:count{0}, leftover{""}, chunk{""}, currLocation{0} {   
    this->path = path;
    this->Buffer.resize(BUFFERSIZE);
    TraceDrivenSim::FILE.open(TraceDrivenSim::path, std::ios::in | std::ios::binary);
    if(!TraceDrivenSim::FILE.good()){
          std::print ("Error opening file");
          std::exit(EXIT_FAILURE);
    }
      
}


void TraceDrivenSim::processChunk(){ 
    std::size_t start{0};
    std::size_t end{chunk.find('\n')};
    
    
    while(end != std::string::npos){
        this->transformedChunk.push_back(chunk.substr(start, end-start));
        count++;
        start = end + 1;
        end = chunk.find('\n', start);
    }

    leftover = chunk.substr(start);
    this->currLocation = this->currLocation - leftover.size();  
}


void TraceDrivenSim::readChunk(){
    TraceDrivenSim::FILE.seekg(currLocation, std::ios::beg);
    TraceDrivenSim::FILE.read(this->Buffer.data(),TraceDrivenSim::BUFFERSIZE);
    currLocation = FILE.tellg();
    this->chunk.clear();
    this->chunk.assign(this->Buffer.data(), TraceDrivenSim::FILE.gcount());
}

void TraceDrivenSim::processFile(Cache& cache){
    while(TraceDrivenSim::FILE.good()){
        TraceDrivenSim::readChunk();
        TraceDrivenSim::processChunk();
        TraceDrivenSim::makeAccess(cache);
   }
      
    std::print ("\nprocessed {} lines\n", this->count);
}


 void TraceDrivenSim::makeAccess(Cache& cache){
    this->transformedChunk.shrink_to_fit();
    std::stringstream someStr;
    std::string r_w{""};
    std::string addr, addrCut, a, b;
    std::bitset <64> address;
    
    for (auto &item : this->transformedChunk)
    {   
         someStr.clear();
         someStr.str(item);
         someStr >>  r_w >> addr; 
        if (r_w == "#eof")
            break;
        if(!addr.empty()) {
            addrCut = addr.substr(2);
         std::bitset <64> address(std::stoull(addrCut, nullptr, 16));
        if(r_w == "R")
            TraceDrivenSim::DoRead(static_cast<std::size_t>(address.to_ullong()), cache);
        if(r_w == "W")
            TraceDrivenSim::DoWrite(static_cast<std::size_t>(address.to_ullong()), cache);
        }
        r_w = "";
        addr = "";
    }
    transformedChunk.clear();
 }



void TraceDrivenSim::DoRead(std::size_t address, Cache& cache){
  cache.bRead(address);
}

void TraceDrivenSim::DoWrite(std::size_t address, Cache& cache){
  cache.bWrite(address);
}