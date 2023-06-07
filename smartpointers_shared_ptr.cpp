#include <memory>
#include <iostream>

class Entity{
    public:
        Entity(){
            std::cout<<"Create new Entity"<<std::endl;
        }

        ~Entity(){
            std::cout<<"Destroy new Entity"<<std::endl;
        }
        void Print(){
            std::cout<<"hello"<<std::endl;
        }
};
int main(){
    // You can construct a shared poitner like this, but don't ever do that.
    //  std::shared_ptr<Entity> entity1(new Entity);
    // This is because of exception, but more importantlly the shared pointer
    // allocates and stores a reference count to keep track of all shared pointers
    // when this count goes down to zero, it deletes the shared pointer.
    // use make_shared<Entity> insted of (new Entity)

    // make_shared is the reference count.
    // using both make_shared and shared_ptr they get constructed together. 
    // Which means: 
    // make_shared is the same as new
    // shared_ptr does the deleteing

    {// Scope inside main()
      // construcr shared_ptr and make_shared with Entity
      std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        {// Scope inside Scope
            std::shared_ptr<Entity> entity2 = entity1;
            entity2->Print();
        }// shared pointer entity2 gets deleted

        // entity2->Print(); //this would not work, because entity2 is deleted

    }// shared pointer entity1 gets deleted

    std::cin.get();

}