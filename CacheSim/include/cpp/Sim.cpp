#include <Sim.hpp>
#include <cstdint>
#include <bitset>


using namespace std::string_literals;

std::ifstream TraceDrivenSim::FILE;

TraceDrivenSim::~TraceDrivenSim(){
    TraceDrivenSim::FILE.close();
}

TraceDrivenSim::TraceDrivenSim(const std::string& path)
:count{0}, leftover{""}, chunk{""}, currLocation{0} {   
    this->path = path;
    TraceDrivenSim::FILE.open(TraceDrivenSim::path, std::ios::in | std::ios::binary);
    if(!TraceDrivenSim::FILE.good()){
          std::cout << "Error opening file";
          std::exit(EXIT_FAILURE);
    }
      
}


std::vector<std::string> TraceDrivenSim::processChunk(const std::string& chunk){
    std::vector<std::string> currAccessChunk;  
    std::size_t start{0};
    std::size_t end{chunk.find('\n')};
    
    
    while(end != std::string::npos){
        currAccessChunk.push_back(chunk.substr(start, end-start));
        count++;
        start = end + 1;
        end = chunk.find('\n', start);
    }

    leftover = chunk.substr(start);
    this->currLocation = this->currLocation - leftover.size();
    return currAccessChunk;    
}


std::string TraceDrivenSim::readChunk(){
    TraceDrivenSim::FILE.seekg(currLocation, std::ios::beg);
    std::vector<char> Buffer(BUFFERSIZE);
    TraceDrivenSim::FILE.read(Buffer.data(),TraceDrivenSim::BUFFERSIZE);
      currLocation = FILE.tellg();
    std::string dataOut(Buffer.data(), TraceDrivenSim::FILE.gcount());
    return dataOut;
}

void TraceDrivenSim::processFile(Cache& cache){
    while(TraceDrivenSim::FILE.good()){
    auto p {TraceDrivenSim::processChunk(TraceDrivenSim::readChunk())};
    TraceDrivenSim::makeAccess(p, cache);
   }
      
    std::cout << "processed " << count << "lines";
}


 void TraceDrivenSim::makeAccess(std::vector<std::string>& someVec, Cache& cache){
    someVec.shrink_to_fit();
    std::stringstream someStr;
    std::string r_w{""};
    std::string addr, addrCut, a, b;
    std::bitset <64> address;
    
    for (auto &item : someVec)
    {   
         someStr.clear();
         someStr.str(item);
         someStr >> a >> r_w >> addr >> b; 
        if (r_w == "#eof")
            break;
        if(!addr.empty()) {
            addrCut = addr.substr(2);
         std::bitset <64> address(std::stoull(addrCut, nullptr, 16));
        if(r_w == "0")
            TraceDrivenSim::DoRead(static_cast<std::size_t>(address.to_ullong()), cache);
        if(r_w == "1")
            TraceDrivenSim::DoWrite(static_cast<std::size_t>(address.to_ullong()), cache);
        }
        r_w = "";
        addr = "";
    }
 }



void TraceDrivenSim::DoRead(std::size_t address, Cache& cache){
  cache.bRead(address);
}

void TraceDrivenSim::DoWrite(std::size_t address, Cache& cache){
  cache.bWrite(address);
}


// void TraceDrivenSim::DoTest(std::vector<std::size_t>& stimVec, Cache& Cache1){
//     int f =static_cast<int> (stimVec.size()); f--;
//     std::uniform_int_distribution dist1{0, f};
//     std::uniform_int_distribution dist2{0, 1};
//    // std::random_device rd2;
//    // std::mt19937 engine1{rd2()};
//     int j{0};
//     int rCount{0}, wCount{0};
//     //std::mt19937 engine2{rd2()};

//     for(auto i{0}; i <100; i++){
//      //bool abs = static_cast<bool>(dist2(engine));
//      bool abs{true};
//       switch(abs){
//         case true : 
//           j = engine() % stimVec.size();//dist1(engine);
//           try {
//           DoRead(stimVec.at(j), Cache1);
//           rCount++;
//           } catch(std::exception ex){
//             ex.what();
//           }
//           break;
        
//         case false: 
//            j = engine() % stimVec.size();//dist1(engine);
//            try{
//             DoWrite(stimVec.at(j), Cache1);
//             wCount++;
//            }catch( std::exception ex){ex.what();}
//            break;
//       }
//     }
    
//       if(rCount != Cache1.getReadNum() || wCount != Cache1.getWriteNum())
//           std::print("Error Somewhere, accesses not matching with that in stimulus drive");


// }