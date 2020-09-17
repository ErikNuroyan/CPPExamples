#include <iostream>
#include <memory>



int main() {
    using namespace std;
    //The unique pointers assure that there's only 1 smart pointer pointing to that location
    unique_ptr<string> u_ptr1,u_ptr2;
    u_ptr1=unique_ptr<string>(new string("Aha"));
    //u_ptr2=u_ptr1;  this is not allowed as ownership of the string takes u_ptr2 and
    //u_ptr1 becomes null pointer, thus cannot be derreferenced
    //However we can use this to let u_ptr2 take the ownership
    u_ptr2=move(u_ptr1);
    std::cout<<(*u_ptr2)<<std::endl;
    
    //shared pointers allow multiple shared pointers point to the same location but the first one which had ownership
    //is responsible for destructor call which would delete the pointed to object
    //These pointers keep track of how many objects were created which point to the same object.
    shared_ptr<string> s_ptr1=shared_ptr<string>(new string("Wow")),s_ptr2;
    s_ptr2=s_ptr1;
    std::cout<<(&(*s_ptr1))<<"   "<<(&(*s_ptr2))<<std::endl;
    //in this case both of them point to the same location of the string
}

