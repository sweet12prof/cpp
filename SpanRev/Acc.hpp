#pragma once

#include <string>
#include <string_view>

class Account{
    public:
        Account(std::string_view ={}, std::string_view={}, const int & = 0);
        
        void setFName(std::string_view);
        void setlName(std::string_view);
        void setAge(const int &);

        std::string getfName() const;
        std::string getlName() const;
        int getAge() const;
    private: 
        char fName[10]{};
        char lName[10]{};
        int age=0;
};