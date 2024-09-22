#pragma once 
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <Cache.hpp>

class TraceDrivenSim{
    public:
       TraceDrivenSim(const std::string&);
       ~TraceDrivenSim();
        
        void processFile(Cache&);
        std::string path;
        uint64_t count{0};
       
        void DoRead( const std::size_t, Cache&);
        void DoWrite( const std::size_t, Cache&);
        

    private:
        //class utilities
        static std::ifstream FILE;
        std::string leftover{""}, chunk{""};
        std::size_t currLocation{0};
        std::vector<char> Buffer;
        std::vector<std::string> transformedChunk{""};
        inline const static std::size_t BUFFERSIZE = 1024*20;
       
       
        void processChunk(); 
        void makeAccess( Cache&);
        void readChunk();
};