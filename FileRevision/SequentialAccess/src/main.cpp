#include <iostream>
#include <fstream>
#include <random>
#include <print>
#include <sstream>
#include <iterator>
#include <iomanip>

static std::random_device rd;
static std::default_random_engine engine(rd());
static std::uniform_int_distribution dist{0x459697, 0x38383838};
static std::bernoulli_distribution dist2(0.45);

static std::size_t chunkCtr{0};
static const std::size_t CHUNKSIZE = 20;
static std::stringstream lineStream;
static std::vector <std::string> chunk(CHUNKSIZE);
 std::fstream fa;
void WriteFile();

void ReadFileByByte();
void ReadChunkByByte();
void ProcessChunkByByte();
void PrintByByteLines();

void ReadFileByLine();

static size_t currLocation{0}, lineCount{0}; 
std::vector<char> byteChunk(CHUNKSIZE);
std::string byteChunkStr, leftover;
std::vector<std::string> byByteLines;


int main(){
    std::string path{"demofile.txt"};
    fa.open(path,  std::ios::out);
    if(!fa.good()) std::print("something wrong");
    WriteFile();
    fa.close();
    fa.open(path,  std::ios::in);
    // ReadFileByByte();
    ReadFileByLine();
    fa.close();
   //std::print("\n Print {} lines", lineCount);
}

void WriteFile(){
    unsigned int addr{0};
    char aMode{' '};
    for (std::size_t i{0}; i < 1024; i++)  
    {
            addr  = static_cast<unsigned int>( dist(engine));
            aMode = dist2(engine) == 1 ? 'R' : 'W';
            lineStream << std::setbase(16) << aMode << " " << addr << "\n";
        if(chunkCtr < CHUNKSIZE){
            chunk.push_back(lineStream.str()); 
            lineStream.str("");
            lineStream.clear();
            chunkCtr++;
        } else {
            for(const auto &item : chunk){
                fa << item;
            }
            chunkCtr = 1;
            chunk.clear();
            chunk.push_back(lineStream.str());
            lineStream.str("");
            lineStream.clear();
        }
    }  
     if(!chunk.empty()){
         for(const auto &item : chunk)
            fa << item;
     }
}

void ReadFileByByte(){
    while(fa.good()){
        ReadChunkByByte();
        ProcessChunkByByte();
        PrintByByteLines();
    }
}

void ReadChunkByByte(){
    fa.seekg(currLocation, std::ios::beg);
    fa.read(byteChunk.data(), CHUNKSIZE);
    byteChunkStr.assign(byteChunk.data(), fa.gcount());
    currLocation = fa.tellg();
}

void ProcessChunkByByte(){
    std::size_t start{0};
    std::size_t end{byteChunkStr.find("\n")};

    while(end != std::string::npos){
        lineCount++;
        byByteLines.push_back(byteChunkStr.substr(start, end-start));
        start = end + 1;
        end = byteChunkStr.find("\n", start);
    }
    leftover = byteChunkStr.substr(start);
    currLocation = currLocation - leftover.size();
}

void PrintByByteLines(){
    for(auto &item : byByteLines)
        std::print("{}\n", item);
}


void ReadFileByLine(){
    std::size_t lineCount{0}, chunktrack{0};
    std::string line;
    byByteLines.clear();
    while( std::getline(fa, line)){
        if(chunktrack < CHUNKSIZE){
            byByteLines.push_back(line);
            lineCount++;
            chunktrack++;
        }
        else {
            std::print("Got Chunk\n");
            PrintByByteLines();
            byByteLines.clear();
            byByteLines.push_back(line);
            lineCount++;
            chunktrack = 1;
        }
    }
    std::print("Printed {} lines from lineFunc", lineCount);
  //  std::getline()
}