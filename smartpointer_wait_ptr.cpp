#include <memory>
#include <iostream>


class Entity{
    public:
        Entity(){
            std::cout<<"Entity created"<<std::endl;
        }
        ~Entity(){
            std::cout<<"Entity created"<<std::endl;
        }
        void Print(){
            std::cout<<"Hello"<<std::endl;
        }
};

int main(){


    // Best to see the comments about shared_ptr
    { //Scope inside main()

        // Construct weak_ptr and make_share with Entity Class 
        std::weak_ptr<Entity> entity01;

        {// Sope inside Scope
            std::shared_ptr<Entity> entity02 = std::make_shared<Entity>();
            entity01 = entity02;
        }// WEAK POINTER gets deleted

    }// WEAK POINTER is already deleted, a shared pointer would be still alive here
     // You can ask a weak pointer if it is still valid/actve, are you expired

    std::cin.get();
}