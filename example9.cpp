#include <iostream>

using namespace std;

class Demo{
    private:
        int n;
    public:
        Demo(int n_1):n(n_1){};
        Demo(const Demo& d);
        Demo& operator=(const Demo& d);
};
void test(Demo obj){
    std::cout<<"In test"<<std::endl;
}

int main() {
    //When passed by value the copy constructor is called
    
    Demo a=Demo(4); //int constructor called
    a=Demo(5);      //Assignment operator called
    test(a);        //Copy constructor called
}

Demo::Demo(const Demo& d){
    std::cout<<"Copy constructor"<<std::endl;
    this->n=d.n;
}
Demo& Demo::operator=(const Demo& d){
    std::cout<<"The assignmend operator is called"<<std::endl;
    if(this==&d)return *this;
    this->n=d.n;
    return *this;
}
