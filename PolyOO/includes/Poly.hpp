#include <cstddef>
#include <iostream>

#ifndef POLY_HPP
#define POLY_HPP

class Poly{

    friend std::istream& operator>>(std::istream&, Poly &);
    friend std::ostream& operator<<(std::ostream&, const Poly &);

    private:
        std::size_t size;
        int  *polyArrPtr;
    
    public:
        Poly(const int &);  //Constructor
        Poly(const Poly &); //Copy Constructor
        ~Poly();            //destructor
        unsigned int getSize() const;
        //Overloads
        Poly& operator+(const Poly &); // addition oo 
        Poly& operator-(const Poly &); //subtract oo 
        const Poly& operator=(const Poly&); //assignment oo
        Poly& operator*(const Poly &);      //multiply oo
        Poly& operator+=(const Poly &);     //
        Poly& operator-=(const Poly &);     //
};
#endif