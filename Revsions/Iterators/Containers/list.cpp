#include <iostream>
#include <list>
#include <iterator>
#include <vector>

template <typename T> void printList(const std::list<T> &);

int main(){
    std::list <int>firstList;

    firstList.push_front(1);
    firstList.push_front(4);
    firstList.push_back(2);
    firstList.push_back(-1);
    std::cout << "Elements after pushing elements into list : ";
    printList(firstList);
    std::cout << std::endl;
    firstList.sort();
    std::cout << "Elements after sorting elements in list : ";
    printList(firstList);
    std::cout << std::endl;

    std::vector <int> intVec{1,2,-3,0,5};
    std::list <int> someList{1,2,34,5};

    someList.insert(someList.begin(),  intVec.begin(), intVec.end() - 3);
    std::cout << "Print after insertion: ";
    printList(someList);
    std::cout << std::endl;
    
    firstList.splice(firstList.end(), someList);
    std::cout << "Elements in FirstList after splicing someList into FirstList : ";
    printList(firstList);

    std::cout << std::endl;

    std::cout << "Elements in someList after Splice : ";
    printList(someList);
    std::cout << std::endl;
    
    someList.insert(someList.begin(), intVec.crbegin(), intVec.crend());
    std::cout << "Elements in someList after refilling someList : ";
    printList(someList);
    std::cout << std::endl;
    
    firstList.merge(someList);
    std::cout << "Elements in firstList after merging with  someList : ";
    printList(firstList);
    std::cout << std::endl;
    std::cout << "Elements in someList after merging with  firstList : ";
    printList(someList);

    std::cout << std::endl;
    someList.assign(intVec.rbegin(), intVec.rend());
    std::cout << "Some List after using assign: ";
    printList(someList);
    std::cout << std::endl;

    firstList.sort();
    firstList.unique();
    std::cout << "firstList after unique: ";
    printList(firstList);
    std::cout << std::endl;
    
    firstList.swap(someList);
    std::cout << "firstList after SWAP: ";
    printList(firstList);
    std::cout << std::endl;
    std::cout << "somelIST after SWAP: ";
    printList(someList);
    someList.pop_front();
    std::cout << std::endl;
    printList(someList);

    someList.

}

template<typename T>
    void printList(const std::list<T> &someList){
        std::ostream_iterator<int> outputContainer{std::cout, " "};
        
        if(someList.empty())
            std::cout << "List is empty";
        else 
            std::copy(someList.begin(), someList.end(), outputContainer);
    }
