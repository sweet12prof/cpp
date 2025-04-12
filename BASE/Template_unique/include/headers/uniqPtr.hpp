#pragma once
#include <memory>
#include <print>
#include <string>

template <typename T>
class uPtr{
    public:
        uPtr(T someval) :uptr{&someval}{};
        ~uPtr(){
            std::print("Object destroyd");
        };

    
    private:
        std::unique_ptr<T> uptr;
};


class Account{
    public: 
        int Id();
        void Id(const int &);
        std::string name();
    private:
        int id{0};
        std::string name{""};
};