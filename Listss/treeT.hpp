#include <string>
#include <iostream>


// predecessor 
// successor
// maximum 
// minimum
// traverse-tree
// search

// insert
// transplant 
// delete

namespace StringTree{
    struct Node{
        int key;
        Node *parent;
        Node *left;
        Node *right;
    };

    class BSHTree{
         Node *root;
        public:
        BSHTree():root{nullptr}{}
        BSHTree(std::initializer_list<int> intList):root(nullptr){
            for(const auto &item : intList){
                Node newNode{item, nullptr, nullptr, nullptr};
              //  newNode->key = item; newNode->parent=nullptr; newNode->left=nullptr; newNode->right=nullptr;
            
                this->insert(newNode);
            }
        }
    
        void walktree(){
            treeWalk(root);
        }

        void treeWalk(Node *temp){
            if(temp != nullptr){
                treeWalk(temp->left);
                std::cout << temp->key << " ";
                treeWalk(temp->right); 
            }
        }
    
        Node* Maximum(Node *temp){
            while (temp != nullptr && temp->right != nullptr)
                temp = temp->right;
            return temp;
                
        }

        Node* Maximum(){
            Node *temp = root;
            temp = Maximum(temp);
        }
    
        Node* Minimum( Node *temp){
            while(temp != nullptr && temp->left != nullptr)
               temp = temp->left;
            return temp;
        }

        Node* Minimum(){
            Node *temp = root;
            temp = Minimum(temp);
        }
            Node* search(Node * val){
            Node *temp = root;
            while(temp != nullptr || temp->key != val->key){
                if(val->key < temp->key)
                    temp = temp->left;
                else 
                    temp = temp->right;
            }
            return temp;
        }

    
        void insert(Node val){
            Node *temp = root;
            Node *y;



            if(temp == nullptr) //node is root
              {  
                Node *newNode = new Node(); 
                newNode->key    = val.key;
                newNode->right = nullptr;
                newNode->left  = nullptr;
                newNode->parent =nullptr;
                root = newNode;
                return;
            }
            else {
                while(temp != nullptr) { //break if leaf node
                    y = temp;
                    if(val.key < temp->key)
                        temp = temp->left;
                    else 
                        temp = temp->right;
                }          
                Node *newNode = new Node(); 
                newNode->key    = val.key;
                newNode->right = nullptr;
                newNode->left  = nullptr;
                newNode->parent = y;
                if(newNode->key < y->key)
                    y->left = newNode;
                else 
                    y->right = newNode; 
            }
        }

        Node* Successor(Node* val){
            Node *found = this->Minimum(val->right);
            if(found == nullptr)
            {
                while(found->left == nullptr)
                    found = found->parent;
                return found;
            }
        }
    };
};

