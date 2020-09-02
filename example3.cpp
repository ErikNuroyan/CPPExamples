#include <iostream>

using namespace std;

class MyClass{
    private:
    int size;
    int * arr;
    public:
    MyClass(){};
    MyClass(int s);
    MyClass(const MyClass & obj2);
    MyClass& operator=(const MyClass & obj2);
    ~MyClass(){
        delete [] arr;
    }
};

int main() {
    MyClass obj1(5),obj2(10);
    obj1=obj2;//Calls the assignment operator
    MyClass obj3=obj1;//Calls the copy constructor
    
}

MyClass& MyClass::operator=(const MyClass & obj2){
    if(this==&obj2){
        return *this;
    }
    std::cout<<"Assignment operator called"<<std::endl;
    size=obj2.size;
    delete [] arr;
    arr=new int[size];
    for(int i=0;i<obj2.size;i++){
        arr[i]=obj2.arr[i];
    }
    return (*this);
}

MyClass::MyClass(int s):size(s){
    arr=new int[size];
    for(int i=0;i<size;i++){
        arr[i]=i;
    }
}

MyClass::MyClass(const MyClass & obj2){
    std::cout<<"Copy constructor called"<<std::endl;
    size=obj2.size;
    arr=new int[size];
    for(int i=0;i<obj2.size;i++){
        arr[i]=obj2.arr[i];
    }
}

