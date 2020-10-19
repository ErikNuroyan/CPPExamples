#include <iostream>

using namespace std;
class Base{};
class Derived:public Base{public: operator int(){return 5;}};

class A{public: int x; virtual void say(){cout<<"From A"<<endl;}};
class B:public A{public: void say(){cout<<"From B"<<endl;}};
class C:public A{public: void say(){cout<<"From C"<<endl;}};

void constCastTest(const A* a_ptr);
void constCastTest(const A& a_ref);

int main() {
    //static_cast example
    char *c =new char('a');
    //int * i_ptr=static_cast<int *>(c); //This is invalid since there's no relation between int* and char* 
    int * i_ptr=(int*)c; //This will compile successfully, however not recommended
    cout<<*(i_ptr)<<std::endl;
    char Ch='b';
    int a=static_cast<int>(Ch);//This will work since there's a cast from char to int
    cout<<a<<std::endl;
    Base b;
    Derived* d=static_cast<Derived*>(&b); //This will also work since it's possible to cast from Base pointer to Derived pointer
    //Derived dd=static_cast<Derived>(b);//This will not work as there's no conversion constructor Derived(Base& b)
    a=static_cast<int>(*d); //This will work since there's a cast from Derived to int
    cout<<a<<endl;
    delete c;
    cout<<"_________________________________________________"<<std::endl;
    
    //dynamic_cast example
    //this works with pointer types or reference types, there must be polymorphic behaviour for it to work(at least one virtual function)
    //This is a slow process since the check for the type is done at runtime
    C* c_ptr=new C();
    B* b_ptr=dynamic_cast<B*>(c_ptr); //Since they're connected hierarchically dynamic_cast works, static_cast wouldn't as there's no conversion from C* to B* (B is not one of the ancestors of C)
    //If A's say wasn't virtual, this wouldn't work as there would be no polymorphic type.
    A* a_ptr=dynamic_cast<A*>(c_ptr);//static_cast would work as well as A is base for C
    delete c_ptr;
    
    //const_cast example
    //This is used for removing const references or const pointers in order to be able to alter the content
    A a_obj=A();
    constCastTest(&a_obj);//Pointer Version
    cout<<a_obj.x<<endl;
    constCastTest(a_obj);//Reference Version
    cout<<a_obj.x<<endl;
    cout<<"_________________________________________________"<<std::endl;
    
    //reinterpret_cast example
    //This is used to cast from any pointer type to any other pointer type
    //Is used to work in byte level
    struct MyStruct{
        int a; // 4 bytes
        int b; // 4 bytes
        char c; //1 byte
        bool d; // 1 byte
    }obj{1,1,'a',false};
    //The size of the struct is 12 byte as it is loaded 4 byte at a time and in memory we have the following picture
    /*
     a a a a b b b b c d - -   
    | | | | | | | | | | | | |
    
    There are 2 empty spaces to ensure that it reads full 4 bytes without loss of information
    */
    MyStruct * struct_ptr=&obj;
    i_ptr=reinterpret_cast<int *>(struct_ptr);
    cout<<*(i_ptr)<<endl;
    i_ptr++; //forward by 4 bytes
    cout<<*(i_ptr)<<endl;
    i_ptr++; // forward by 4 bytes
    char * ch_ptr=reinterpret_cast<char *>(i_ptr);
    cout<<ch_ptr<<endl;
    ch_ptr++;//forward by 1 byte
    bool * bool_ptr=reinterpret_cast<bool *>(ch_ptr);
    cout<<std::boolalpha<<*(bool_ptr)<<endl;
}
void constCastTest(const A* a_ptr){
    A* non_const= const_cast<A*>(a_ptr);
    non_const->x=14;
}
void constCastTest(const A& a_ref){
    A& non_const= const_cast<A&>(a_ref);
    non_const.x=18;
}
