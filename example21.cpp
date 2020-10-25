#include <iostream>

using namespace std;

//Namespaces should be defined in global scope
namespace first{
    int x,y;
}
//Extending first should be done only in global scope not in any local scope
namespace first{
    int a,b;
}

void some_func();
void print_func();
void add_attributes_func();

int main() {
    print_func();
}
void some_func(){
    //Namespace definition is not allowed here,Compile Error
    /*
    namespace second{
        int x,y;
    }
    */
}
void print_func(){
    first::x=first::y=5;
    std::cout<<first::x<<" "<<first::y<<" "<<first::a<<" "<<first::b<<std::endl;
}
