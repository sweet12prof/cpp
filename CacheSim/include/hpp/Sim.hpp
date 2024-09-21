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
        
        std::vector<std::string> processChunk(const std::string&);
        void processFile(Cache&);
        void makeAccess( std::vector<std::string>&, Cache&);
        std::string path;
        uint64_t count{0};
        std::string readChunk();

        void DoRead( const std::size_t, Cache&);
        void DoWrite( const std::size_t, Cache&);
        //void DoTest(std::vector<std::size_t>& , Cache&);

    private:
       // Cache& cache;
        static std::ifstream FILE;
        std::string leftover, chunk;
        std::size_t currLocation;
        inline const static std::size_t BUFFERSIZE = 128;
       
};