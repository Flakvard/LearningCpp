#include <memory>
#include <iostream>

class Entity{
    public:
    Entity(){
        std::cout<<"Created a new Entity"<<std::endl;
    }
    ~Entity(){
        std::cout<<"Delete Entity"<<std::endl;
    }
    void Print(){

    }
};
int main(){
    
    {// Scope inside main()
        // Constructor for unique pointer is Explicit, so you cannot implict converstion
        // This does not work:
        // std::unique_ptr<Entity> entity = new Entity; 

        // Construct the unq_ptr with operators ()
        // std::unique_ptr<Entity> entity(new Entity);

        // Allthough the prefered way to initiate and construct a unique pointer:
        // Because of exception handeling write like this:
           std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // More safe if the pointer throws an exception and ends up being a memory leak
           entity->Print();
        // OUTPUT: Created a new Entity

        // YOU CANNOT ASSAIGN/COPY THE UNIQUE POINTER ANOTHER POINTER
        // std::unique_ptr<Entity> entity2 = entity; // does not work 
        // Operator '=' is removed from std:unique_ptr
        // USE A SHARED POINTER
    }
    // Scope ends and unique points gets deleted
    // OUTPUT: Delete Entity
    std::cin.get();

}