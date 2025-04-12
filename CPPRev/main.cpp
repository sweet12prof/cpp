#include <format>
#include <iostream>

struct fred_t{
 int x;
};

void somefunct(int *f){
    *f = 7;
    f=nullptr;
}
void  do_something(int x){
    std::cout << x;
}

void f1(struct fred_t *p)
{
    // dereference p and then check if it's NULL
    int x = p->x;
    if (p)
        do_something(x);
}

int main(){
    //using namespace std;
    int *c;
    int a{5}, b{6};
    somefunct(&a);
        
        std::cout << std::format("{} Hello World {}",  a, b+1);
    
}