#include <iostream>
#include <string>
namespace DLIST{
    struct Node{
        std::string key;
        Node * prev;
        Node * next;
    };
    
    class List{
        private:
          Node * Head;
        public:
        friend void insert(const DLIST::Node & eleM, DLIST::Node* y );
        List() :Head{nullptr}{ }
    
        explicit List(std::string val) :Head(){
            prepend(val);        
        }
    
        List(std::initializer_list<std::string> strList):Head(){
            for(auto item : strList)
            this->prepend(item);
        }
    
        void prepend(std::string val){
            Node *newNode = new Node();
            newNode->key = val;
            newNode->next = Head;
            newNode->prev = nullptr;
            if(Head != nullptr)
            Head->prev = newNode;
            Head = newNode;
        }

        void prepend(Node &node){
            Node *newNode = new Node();
            newNode->key = node.key;
            newNode->next = Head;
            newNode->prev = nullptr;
            if(Head != nullptr)
            Head->prev = newNode;
            Head = newNode;
        }
    
    
        ~List(){
            while(Head){
                Node *temp = Head->next;
                delete Head;
                Head = temp;
            }
        }
        
        void displayList(){
            Node* temp = this->Head;
            while(temp)
            {
                std::cout << temp->key<< "-> ";
                temp = temp->next;
            }
            std::cout << "nullptr \n";
        }

        void remove(std::string val){
            Node *prevElem = nullptr;
            Node *currElem = Head;
            
            while(currElem){
                if(currElem->key == val){
                   Node *temp =currElem->next;
                    if(currElem == Head){
                         Head->next->prev = nullptr;
                         Head = Head->next;
                    }
                    else {
                        prevElem->next = currElem->next;
                        if(currElem->next != nullptr)
                            currElem->next->prev = prevElem;  
                        
                    }
                    delete currElem;
                    currElem = temp;
                }
                else{
                    prevElem = currElem;
                    currElem = currElem->next;
                }
            }
        }

        Node* search(std::string key){
            Node *temp =Head;

            while(temp){
                if(temp->key == key)
                    return temp;
                else temp = temp->next;
            }
            return temp;
        }

        


        void deleteElem(std::string key){
            Node * foundNode = search(key);
            if(foundNode){
              //  Node * temp = foundNode->next;
                if(foundNode == Head){
                    foundNode->next->prev = nullptr;
                    Head = foundNode->next;
                }else {
                   if(foundNode->next != nullptr)
                        foundNode->next->prev = foundNode->prev;
                    foundNode->prev->next = foundNode->next;
                }
                delete foundNode;
            }
        }
      
    };

    void insert(const DLIST::Node & eleM, DLIST::Node* y ){
        Node *newNode = new Node();
        newNode->key = eleM.key;
        newNode->next = y->next;
        newNode->prev = y;
        y->next = newNode;
    }

    
    
}
