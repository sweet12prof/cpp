#include <Myarray.hpp>
#include <algorithm>
#include <stdexcept>
#include <span>

using namespace Array;

MyArray::MyArray(const std::size_t& size)
:size(size), arrPtr{std::make_unique<int[]>(size)} {}

MyArray::MyArray(std::initializer_list<int> List)
:size{List.size()}, arrPtr{std::make_unique<int[]>(List.size())} {
    std::copy(std::begin(List), std::end(List), this->arrPtr.get());        
}

MyArray::MyArray(const MyArray& arr)
:size(arr.size),  arrPtr{std::make_unique<int[]>(arr.Size())} {
    std::span<int> arrCtr{arr.arrPtr.get(), arr.Size()};
    std::copy(std::begin(arrCtr), std::end(arrCtr), arrPtr.get());
}

MyArray& MyArray::operator=(const MyArray& right){
    // this->size = right.Size();
    // this->arrPtr = std::make_unique<int[]>(right.Size());
    // std::span <int> arr {right.arrPtr.get(), right.Size()};
    // std::copy(std::begin(arr), std::end(arr), this->arrPtr.get());
    MyArray temp{right};
    std::swap(*this, temp);
    return *this;
}

MyArray::MyArray(MyArray&& arrArg)
:size{std::exchange(arrArg.size, 0)}, arrPtr{std::move(arrArg.arrPtr)}{}

MyArray& MyArray::operator=(MyArray&& right){
    // MyArray temp{std::move(right)};
    // std::swap(*this, temp);
    // return *this
    this->size   = std::exchange(right.size, 0);
    this->arrPtr = std::move(right.arrPtr);
    return *this;
}

void MyArray::toString() const{
    std::span<int> items {this->arrPtr.get(), this->size};
        std::print("Array: ");
        auto printfunct{
            [](auto &someval){
                for(auto item : someval)
                    std::print("{} ", item);
            }
        };
        printfunct(items);
}


std::istream& Array::operator>>(std::istream& in,  MyArray& arr){
    std::span <int> items {arr.arrPtr.get(), arr.Size()};
    for (auto &item: items)
        in >> item;
    return in;
}

std::ostream& Array::operator<< (std::ostream& out, const MyArray& arr){
    arr.toString();
    return out;
}

std::size_t MyArray::Size() const{
    return this->size;
} 

bool MyArray::operator==(const MyArray& arr){
    std::span <int> items1 {arr.arrPtr.get(), arr.Size()};
    std::span<int> items2 {this->arrPtr.get(), this->size};
    return std::equal(items1.begin(), items1.end(), items2.begin(), items2.end());
}

int& MyArray::operator[](const std::size_t& loc){
    if(loc >0 && loc  < this->size)
        return this->arrPtr[loc];
    else throw std::out_of_range("Index is Out of Range");
}

 int MyArray::operator[](const std::size_t& loc) const{
     if(loc >0 && loc < this->size)
        return this->arrPtr[loc];
    else throw std::out_of_range("Index is Out of Range");
}


MyArray::operator bool() const{
    return (this->size != 0);
}


MyArray&  MyArray::operator++() {
     std::span<int> items2 {this->arrPtr.get(), this->size};
     std::for_each(items2.begin(), items2.end(), [](auto &val){
        return val++;
     });
     return *this;
}

MyArray MyArray::operator++(int){
    auto temp{*this};
    ++(*this);
    return temp;
}

 MyArray& MyArray::operator+=(int val){
    std::span<int> items2 {this->arrPtr.get(), this->size};
    std::for_each(items2.begin(), items2.end(), [](auto &val){
        return val+=2;
     });
     return *this;
 }


 

MyArray::~MyArray(){
}
