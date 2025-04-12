#include "users.hpp"
#include <print>
#include <iomanip>
 Users::User::User(const std::string_view& name, const std::string_view& address, 
        const cities& city, const states& state, const std::string& zip)
:name{name}, address{address}, city{city}, state{state}, zip{zip}
{}

void Users::User::UserDetails() const{
    std::print("Name: {:<10} \nAddress: {:<10} \nCity: {:<10} \nState: {:>3} \nZip: {:<10}", 
    this->name, this->address, this->citiesStr[static_cast<int>(this->city)], 
    this->statesStr[static_cast<int>(this->state)], this->zip);
}