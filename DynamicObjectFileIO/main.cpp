#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <memory>
#include <iomanip>

class User{
    public:
        User(){};
        User(std::string name, int age ):name{name}, age{age}
        {
            size = name.size();
        }

         std::size_t Size(){
            return size;
        }

        std::string Name(){
            return name;
        }

        
        void  Age_(int age){
            this->age = age;
        }

        int Age(){
            return this->age;
        }

       void Name_(std::string name){
            this->name = name;
            this->size = name.size();
        }


    private:    
    std::size_t size;
    std::string name;
    int age;
};


void writeUser(std::fstream &fPtr, User& user ){
    int age{user.Age()};
    std::size_t size{user.Size()};
    std::string name{user.Name()};

    if(fPtr){
        fPtr.write(reinterpret_cast<const char*>( &size), sizeof(std::size_t) );
        fPtr.write(reinterpret_cast<const char*>( &name[0]), user.Size());
        fPtr.write(reinterpret_cast<const char*>( &age), sizeof(int));
    }else std::cerr << "File not Found";
}

User readUser(std::fstream &fPtr){
    if(fPtr){
        std::size_t sizeTemp = 0;
        fPtr.read(reinterpret_cast<char *>(&sizeTemp), sizeof(std::size_t));

        std::string someStr(sizeTemp, 'o');
        fPtr.read(reinterpret_cast<char *>(&someStr[0]), sizeTemp);

        int agePtr;
        fPtr.read(reinterpret_cast<char *>(&agePtr), sizeof(int));

        
        return User(someStr, agePtr) ;

    }else{ std::cerr << "File not Found"; return User();}
}


void displayUser(User usr){

        std::cout <<  std::setw(58) << std::left << usr.Name() <<":" << std::right << usr.Age() << std::endl;

}

int main(){
    std::vector<User> users(10);
    std::string val{"chris"};
  
    //std::cout << name;

    int i{0};
    for (auto& item : users){
        std::string name{val.append(5,'s')};
        item.Name_(name);  item.Age_(i);
        i++;
    }
    

    // for(auto item : users)
    //     std::cout << item.Name() << std::endl;
    //
    std::fstream myFilePtr{"myfile.txt", std::ios::out | std::ios::binary};

    if(!myFilePtr){
        std::cerr << "File not Opened";
        return -1;
    }else {
        // myFilePtr.write(reinterpret_cast<const char*>(users.data()), users.size()*sizeof(User));
        for(auto item : users)
            writeUser(myFilePtr, item);
         myFilePtr.close();
        
         myFilePtr.open("myfile.txt", std::ios::in | std::ios::binary);

         std::vector <User> readArray;
         while(myFilePtr.peek() != EOF){
            readArray.push_back(readUser(myFilePtr));
         }

         for(auto item: readArray){
            displayUser(item);
         }
    }
}   