#include <stdexcept>

double divide(const int &, const int &);

class DivideByZeroExpt : public std::runtime_error
{   public: 
        DivideByZeroExpt()
        :std::runtime_error{"Divisor is Zero, exception not possible"}
        {
            
        }
    };


double divide(const int & dividend, const int & divisor){
    if(divisor == 0)
        throw DivideByZeroExpt{};
    else 
        return (double) dividend / divisor;
}