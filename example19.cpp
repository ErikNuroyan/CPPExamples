#include <iostream>

using namespace std;

class MyClass{
    private:
        int val;
    public:
        MyClass(int v=0):val{v}{std::cout<<val<<std::endl;};
};

int main() {
    MyClass * ptr=new MyClass[5]; //Allocated and default constructor called
    MyClass arr[10]; //Default constructor called 10 times;
    
    delete[] ptr;
    return 0;
}
