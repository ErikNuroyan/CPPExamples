#include <iostream>

using namespace std;


int main() {
    struct MyStr{
        int a; //4 bytes
    };
    std::cout<<sizeof(MyStr)<<std::endl;
    //Demonstrating the placement new
    //This is used to specify the space where the object should be stored
    //It can be useful when we have to use multiple times of new to create dynamic objects
    //We specify the memory where it should be stored
    //This becomes much faster as you take the overload of deciding where to allocate memory from
    int * buffer=new int[10]; //10*4 bytes = 40 bytes of memory
    MyStr* str_ptr=new (buffer) MyStr{5}; //Store MyStr starting from buffer[0]
    cout<<buffer[0];
    
    
    return 0;
}
