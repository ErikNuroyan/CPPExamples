#include <iostream>
#include <string>

class A{
    private:
    int a;
    double b;
    std::string c;
    
    protected:
    double getB();
    std::string getC();
    
    public:
    A(int a_1,double b_1,std::string c_1);
    A(){};
    int getA();
};

class B:public A{
  private:
  int d;
  public:
  B(int a_1,double b_1,std::string c_1,int d_1);
  B(){};
  int getA_Derived();
  int getD();
};
int main() {
    A obj_A={5,4.5,"Something"};
    B obj_B={7,8.0,"Something else",9};
}

A::A(int a_1,double b_1,std::string c_1):a(a_1),b(b_1),c(c_1){
    std::cout<<"Constructor A called"<<std::endl;
};
double A::getB(){
    return this->b;
}
int A::getA(){
    return this->a;
}
std::string A::getC(){
    return this->c;
}

B::B(int a_1,double b_1,std::string c_1,int d_1):A(a_1,b_1,c_1),d(d_1){
    std::cout<<"Constructor B called"<<std::endl;
};
