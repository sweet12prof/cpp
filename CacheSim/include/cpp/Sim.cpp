#include <Sim.hpp>
#include <cstdint>
using namespace std::string_literals;

std::ifstream TraceDrivenSim::FILE;

TraceDrivenSim::~TraceDrivenSim(){
    TraceDrivenSim::FILE.close();
}

TraceDrivenSim::TraceDrivenSim(const std::string& path)
:count{0} {   
    this->path = path;
    TraceDrivenSim::FILE.open(TraceDrivenSim::path, std::ios::in);
    if(!TraceDrivenSim::FILE.good()){
          std::cout << "Error opening file";
          std::exit(EXIT_FAILURE);
    }
      
}


std::vector<std::string> TraceDrivenSim::processChunk(const std::string& chunk2){
    static std::string leftover;
    static std::string chunk ;

    chunk = leftover + chunk2;
    std::vector<std::string> currAccessChunk;  
    currAccessChunk.resize(0);
    std::size_t start{0};
    std::size_t end{chunk.find('\n')};
    
    
    while(end != std::string::npos){
     //   std::cout << chunk.substr(start, end-start);
        currAccessChunk.push_back(chunk.substr(start, end-start));
        count++;
        start = end + 1;
        end = chunk.find('\n', start);
    }

    leftover = chunk.substr(start);
    return currAccessChunk;    
}


std::string TraceDrivenSim::readChunk(){
    static std::size_t currLocation = 0;
    TraceDrivenSim::FILE.seekg(currLocation, std::ios::beg);
    
    std::vector<char> Buffer(TraceDrivenSim::BUFFERSIZE);
    TraceDrivenSim::FILE.read(Buffer.data(),TraceDrivenSim::BUFFERSIZE);

    std::string dataOut(Buffer.data(), BUFFERSIZE);
    // Buffer.resize(0);
    currLocation = FILE.tellg();
    return dataOut;
}

void TraceDrivenSim::processFile(){
    while(TraceDrivenSim::FILE.good()){
    //  std::string someStr = TraceDrivenSim::readChunk();
    //  std::vector<std::string> someVec = TraceDrivenSim::processChunk(someStr);
    //  TraceDrivenSim::makeAccess(someVec);
    auto p {TraceDrivenSim::processChunk(TraceDrivenSim::readChunk())};
    TraceDrivenSim::makeAccess(p);
    }
      
    std::cout << "processed " << count << "lines";
}


 void TraceDrivenSim::makeAccess(std::vector<std::string>& someVec){
    std::stringstream someStr;
    std::string r_w;
    int r_w_bool;
    std::string addr, addrCut;
    for (auto item : someVec)
    {   
        someStr.str("");
        someStr.str(item);
        someStr >> r_w >> addr;
        if(r_w == "R") r_w_bool = true;
        else if(r_w == "W") r_w_bool = false;
        addrCut = addr.substr(2);
        std::cout << std::boolalpha << r_w <<" " << addrCut << std::endl;
       
            //  std::cout << someVec.size();
        // while()
        // {
        //     if(r_w = 'R') r_w_bool = true;
        //     else if(r_w == 'W') r_w_bool = false;
        //     else throw std::invalid_argument("something happended with r, ws");

        //     addrCut = addr.substr(2);

        //     std::cout << std::boolalpha << r_w <<" " << addrCut << std::endl;
        // }
    }
 }

