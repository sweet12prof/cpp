#include <iostream>
#include "Time.hpp"
#include <sstream>
#include <string>
#include <iomanip>

Time::Time(){}

Time::Time(const int& h, const int & m, const int & s){
    if( (h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60) )
    {
        this->hour = h;
        this->minute = m;
        this ->second = s;
    }
    else 
        std::cout << "Input is wrong";
        
}

void Time::setTime(const int& h, const int & m, const int & s){
    if( (h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >=0 && s < 60) )
    {
        this->hour = h;
        this->minute = m;
        this ->second = s;
    }
    else 
        std::cout << "Input is wrong";
}

std::string Time::getStandardTime() const {
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) <<(hour % 12)  << " : "<< std::setw(2) << (minute % 60) << " : " << std::setw(2) << (second % 60) << std::setw(2) << (hour > 12 ? " PM" : " AM" );
    return stream.str();
}

std::string Time::getUniversalTime() const {
    std::stringstream streamT;
    streamT << std::setfill('0') << std::setw(2) << this->hour << " : " << std::setw(2) << this->minute  << " : " << std::setw(2) << this->second ;
    return streamT.str();
}