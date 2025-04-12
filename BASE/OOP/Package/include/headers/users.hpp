#pragma once
#include <string>
#include <array>

namespace Users{
    enum class cities{Accra, Kumasi, Hohoe, DEF};
    enum class states{GA, AS, VR, DEF};
    using namespace std::string_literals;
    
    class User{
        public:
            User(const std::string_view&, const std::string_view&, const cities&, const states&, const std::string&);
            void UserDetails() const;
        private: 
            std::string name{""};
            std::string address{""}; 
            cities city{cities::DEF};
            states state{states::DEF};
            std::string zip{""};
            inline const static std::array<std::string, 4> statesStr{"GA"s, "AS"s, "VR"s, "DEF"s};  
            inline const static std::array<std::string, 4> citiesStr{"Accra"s, "Kumasi"s, "Hohoe"s, "sef"s};  
    };
}
    