#include "users.hpp"
#include "pack.hpp"
#include <numeric>
#include <twoDayPack.hpp>
#include <memory>
#include <TwoDaycost.hpp>
#include <pack_DImethod.hpp>

int main(){
    using namespace Users;
    User user1("chris", "Ahado, Hospital", 
    cities::Accra, states::GA, "1120-22-1099");

    User user2("christoph", "Madina", 
    cities::Accra, states::VR, "1120-22-1099");

    TwoDayCost twoday1(250.00);
    CostModel *twoDayModel =&twoday1;

    Package_DI pack1{user1, user2, 20, twoDayModel};
    pack1.packageDetails();

    // int p {5};
    // int *ptr{&p};
    // //delete ptr;
    // ptr = nullptr;

}