#pragma once
#include <print>
#include <cacheline.hpp>
#include <random>

static std::random_device rd;
static std::default_random_engine engine{rd()};

class Cache{    
    public: 
        virtual ~Cache() = default;
        Cache(const int&, const int&, const int&, const int&);
      //  Cache() = default;
        void bRead(const std::size_t &);
        void bWrite(const std::size_t &);
        void bDisplaySpec() const;
        //helpers
        std::string getIndex(const unsigned int&) const;
        std::string getTag(const unsigned int& )  const;
        std::size_t getIndex_i(const unsigned int&) const;

        inline int getassoc() const{
            return this->associaticity;
        }

        inline int getNumOfEntries() const {
            return this->numOfentries;
        };

    const inline static int aBus{32}; 

    protected:
         int addressBits{32};
         int hits{0};
         int misses{0};
         int  numOfentries;
         int  tagBits;
         int  indexBits;
         int  offsetBits;
        
    private: 
        int cacheSize{0};
        int associaticity{0} ;
        int blockSize{0};  

 

        virtual void displaySpec() const        =0;
        virtual void Read(const std::size_t &)  = 0;
        virtual void Write(const std::size_t &) = 0;

};