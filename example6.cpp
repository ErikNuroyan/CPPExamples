#include <iostream>

//The Diamond shape multiple inheritance
/*
            A
           / \
          B   C
           \ /
            D

The C++ rule:
The initialization of the base virtual class
is the responsibility of the most derived class. (D in this case)
*/
class A{
    private:
        int a;
    public:
        A(int a_1):a(a_1){};
};
class B:virtual public A{
    private:
        int b;
    public:    
        B(int a_1,int b_1):A(a_1),b(b_1){};
};
class C:virtual public A{
    private:
        int c;
    public:
        C(int a_1,int c_1):A(a_1),c(c_1){};
};
class D:public B,public C{
    private:
        int d;
    public:
        D(int a_1,int b_1,int c_1,int d_1):B(a_1,b_1),C(a_1,c_1),A(a_1){}; //Note the explicit constructor call to indirect virtual base class constructor
};

int main() {
    D d(1,2,3,4);
}
