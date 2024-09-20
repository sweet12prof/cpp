#pragma once 
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
class TraceDrivenSim{
    public:
       TraceDrivenSim(const std::string&);
       ~TraceDrivenSim();
        
        std::vector<std::string> processChunk(const std::string&);
        void processFile();
        void makeAccess( std::vector<std::string>&);
         std::string path;
         uint64_t count{0};
          std::string readChunk();
    private:
        static std::ifstream FILE;
        inline const static std::size_t BUFFERSIZE = 20 * 1024;
       
};