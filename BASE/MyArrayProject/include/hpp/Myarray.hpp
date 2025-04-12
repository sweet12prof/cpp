#pragma once
#include <memory>
#include <iostream>
#include <print>
namespace Array{
    class MyArray{
        public:
            friend std::istream& operator>>(std::istream&, MyArray& );
            friend std::ostream& operator<<(std::ostream&, const MyArray&);
            
            MyArray(std::initializer_list<int>);
            explicit MyArray(const std::size_t&);
            ~MyArray();      
            
            MyArray(const MyArray& );
            MyArray& operator=(const MyArray& );
            
            MyArray(MyArray&& );
            MyArray& operator=( MyArray&&);
            
            std::size_t Size() const;
            void toString() const;
           //--Operators
            
            bool operator==(const MyArray&);
            
             int& operator[](const std::size_t&);
              int operator[](const std::size_t&) const; 
            
            explicit operator bool() const;

            
           
            MyArray& operator++();
            MyArray operator++(int);
            MyArray& operator+=(int);
         

        private: 
            std::size_t     size;
            std::unique_ptr<int[]> arrPtr;
          
    };
        // MyArray operator+(MyArray, MyArray);
        // MyArray operator-(MyArray, MyArray);
};
