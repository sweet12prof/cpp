#include <memory>
#include <iostream>
#include <string>
#include <list>
//#include <treeT.hpp>
#include <dList.hpp>



    struct Node
{
    Node * next;
    std::string data;
};



    class List {
    private:
        Node* Head;
    public:
        List() :Head(nullptr) {}

        List(std::string val)
            :Head(nullptr) {
            this->insertNode(val);
        }


        List(std::initializer_list<std::string> strList) :List() {
            for (auto item : strList)
                insertNode(item);
        }

        void displayList() {
            Node* temp = this->Head;
            while (temp)
            {
                std::cout << temp->data << "-> ";
                temp = temp->next;
            }
            std::cout << "nullptr \n";
        }

        void insertNode(std::string val) {
            Node* newNode = new Node();
            newNode->next = Head;
            newNode->data = val;
            Head = newNode;
        }

        Node* search(Node val) {
            Node* temp = Head;
            while (temp != nullptr && temp->data != val.data)
                temp = temp->next;
            return temp;
        }

        void clear() {
            while (Head) {
                Node* temp = Head;
                Head = Head->next;
                delete temp;
            }
        }

        ~List() {
            clear();
        }

        void remove(std::string val) {
            Node* LastElem = nullptr;
            Node* CurrElem = Head;
            while (CurrElem) {
                Node* temp = CurrElem->next;
                if (CurrElem->data == val) {
                    if (CurrElem == Head) {
                        Head = CurrElem->next;
                    }
                    else {
                        LastElem->next = CurrElem->next;
                    }
                    delete CurrElem;
                    CurrElem = temp;
                }
                else {
                    LastElem = CurrElem;
                    CurrElem = CurrElem->next;
                }

            }
        }
    };



int main(){
    // std::list<int> someList;
    // someList.insert(s)
    // List someList{"chris", "melod", "myself"};
    // someList.displayList(); 
    // someList.remove("chris");
    // someList.displayList(); 
     DLIST::List someList{"chris", "melod", "myself"};
     // someList.displayList();
     // someList.prepend("max");
     // someList.displayList();
     // someList.remove("chris");
     // someList.remove("max");
     // someList.displayList();
     // someList.remove("melod");
     // someList.displayList();

     DLIST::Node newnode{"eve", nullptr, nullptr};
     someList.prepend(newnode);
     someList.displayList();

     DLIST::insert(newnode, someList.search("chris"));
    // someList.displayList();

     someList.deleteElem("eve");
    // someList.deleteElem("eve");

    // someList.displayList();

   //StringTree::BSHTree tree{5, 0, 1, 18, 2, 3, 7};
   //tree.insert({-1, nullptr, nullptr, nullptr});
   //tree.walktree();
   //std::cout <<"\nMaximum is " << tree.Maximum()->key;
   //std::cout <<"\nMinimum is " << tree.Minimum()->key;
}