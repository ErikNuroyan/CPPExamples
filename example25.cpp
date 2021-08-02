
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
struct A {
    void func() {
        if(std::is_same<T,A>::value) {
            std::cout << "A" << std::endl;
            return;
        }
        static_cast<T*>(this)->func();
    }
};

struct B:public A<B> {
    void func() {
         std::cout << "B" << std::endl;    
    }
};

struct C:public A<C> {
    void func() {
         std::cout << "C" << std::endl;    
    }
};

template<typename T>
void which(A<T>& obj) {
    obj.func();
}

int main()
{
    B b;
    which(b);
    C c;
    which(c);
        
    return 0;
}
