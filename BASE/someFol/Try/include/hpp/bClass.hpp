#include <memory>
class A{
    public :
        A(A&);
    private :
        std::unique_ptr<int> intPtr;
};