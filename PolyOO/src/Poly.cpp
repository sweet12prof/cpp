#include "Poly.hpp"
#include <iomanip>
//Constructor
Poly::Poly(const int & size = 1)
    : size{static_cast<std::size_t>(size)}, polyArrPtr{ new int[size]{}}
{
}

//Destructor
Poly::~Poly(){
    delete [] polyArrPtr;
}


//CopyConstructor
Poly::Poly(const Poly & poly)
:size{static_cast<std::size_t>(poly.getSize())}, polyArrPtr{new int[this->size]{}}{
    for(auto i{0}; i<this->size; i++){
        this->polyArrPtr[i] = poly.polyArrPtr[i];
    }
}


//utility
    //getSize
unsigned int Poly::getSize() const{
    return static_cast<int>(this->size);
}



std::istream& operator>>(std::istream& in, Poly& poly){
    int i{0};
    while ( i < poly.size && in >> poly.polyArrPtr[i++]);
    return in;
}

std::ostream& operator<<(std::ostream& out ,const Poly & poly){
    for (std::size_t i{0}; i <poly.getSize(); i++){
        out  <<std::internal << std::setw(3)  << std::showpos<< poly.polyArrPtr[i] << "x^" << i << " " ;
    }
    return out;
}

Poly& Poly::operator+(const Poly& poly){
   if (this->size > poly.getSize()){
        std::size_t newSize{this->size}; //get order of larger polynomial

        static Poly newPoly(newSize); //create a tempPolynomial which has the same order as larger polynomial
        
        for(auto i{0}; i<poly.getSize(); i++)
            newPoly.polyArrPtr[i] = poly.polyArrPtr[i]; //write intial smaller polynomial into bigone, leave zero in high orders it doesnt possess
        
        for(auto i{0}; i<this->size; i++)
            newPoly.polyArrPtr[i] += this->polyArrPtr[i];
        
        return newPoly;
   }
   else 
    {
        std::size_t newSize{poly.getSize()};
        static Poly newPoly(newSize);
        
        for(auto i{0}; i<this->size; i++)
            newPoly.polyArrPtr[i] = this->polyArrPtr[i];

        for(auto i{0}; i<this->size; i++)
            newPoly.polyArrPtr[i] += poly.polyArrPtr[i];

        return newPoly;  

    }   

}

Poly& Poly::operator-(const Poly& poly){
   if (this->size > poly.getSize()){
        std::size_t newSize{this->size}; //get order of larger polynomial

        static Poly newPoly(newSize); //create a tempPolynomial which has the same order as larger polynomial
        
        for(auto i{0}; i<poly.getSize(); i++)
            newPoly.polyArrPtr[i] = poly.polyArrPtr[i]; //write intial smaller polynomial into bigone, leave zero in high orders it doesnt possess
        
        for(auto i{0}; i<this->size; i++)
            newPoly.polyArrPtr[i] -= this->polyArrPtr[i];
        
        return newPoly;
   }
   else 
    {
        std::size_t newSize{poly.getSize()};
        static Poly newPoly(newSize);
        
        for(auto i{0}; i<this->size; i++)
            newPoly.polyArrPtr[i] = this->polyArrPtr[i];

        for(auto i{0}; i<this->size; i++)
            newPoly.polyArrPtr[i] -= poly.polyArrPtr[i];

        return newPoly;  

    }   

}

Poly& Poly::operator*(const Poly& poly){
    std::size_t tempsize = this->size + poly.getSize();
    static Poly mulPoly(tempsize);
    for(auto i{0}; i<this->size; i++)
        for (auto j{0}; j<poly.getSize(); j++)
        {
            mulPoly.polyArrPtr[i+j] += this->polyArrPtr[i] * poly.polyArrPtr[j];
        }
    return mulPoly;
}

const Poly& Poly::operator=(const Poly& poly){
    if(&poly != this){
        if(this->size != poly.getSize())
           { 
                this->size = poly.getSize();
                delete [] this->polyArrPtr;
                this->polyArrPtr =  new int [this->size]{};
            }
        for(auto i{0}; i<this->size; i++)
            this->polyArrPtr[i] = poly.polyArrPtr[i];
    }
    return *this;
}


Poly& Poly::operator+=(const Poly& right){
    *this = *this + right;
    return *this;
}


Poly& Poly::operator-=(const Poly& right){
    *this = *this - right;
    return *this;
}