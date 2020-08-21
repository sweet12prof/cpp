#include <string>


#ifndef TIME_H
#define TIME_H
class Time {
     private :
        int hour{0};
        int minute{0};
        int second{0};
    
    

    public :
        Time();
        Time(const int &, const int &, const int &);
        void setTime(const int &, const int &, const int &);
        std::string getStandardTime  () const;
        std::string getUniversalTime () const;
};
#endif