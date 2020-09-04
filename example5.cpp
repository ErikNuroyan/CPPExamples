#include <iostream>
#include <string>

class A{
    private:
    int a;
    double b;
    std::string c;
    
    public:
    A(int a_1,double b_1,std::string c_1);
    A(){};
    virtual void v_function();
    virtual ~A();
};

class B:public A{
  private:
  int d;
  public:
  B(int a_1,double b_1,std::string c_1,int d_1);
  B(){};
  virtual void v_function();//May omit keyword virtual(by default it is)
  ~B();
};

int main() {
    {
        A * obj_A=new A(5,4.5,"Something");
        B * obj_B=new B(7,8.0,"Something else",9);
        A * a_ptr= obj_B;
        a_ptr->v_function();//B's function is called as v_function is virtual
        
                            //Since the destructor of A is virtual first destructor of B is called than
        delete a_ptr;       //That of A, otherwise only destructor for A would be called and remaining part
        delete obj_A;       //Of B would still be in the heap resulting in memory leak
    }
}

A::A(int a_1,double b_1,std::string c_1):a(a_1),b(b_1),c(c_1){
    std::cout<<"Constructor A is called"<<std::endl;
};
void A::v_function(){
    std::cout<<"I am from A"<<std::endl;
}
A::~A(){
    std::cout<<"Destructor of A is called"<<std::endl;
}

B::B(int a_1,double b_1,std::string c_1,int d_1):A(a_1,b_1,c_1),d(d_1){
    std::cout<<"Constructor B is called"<<std::endl;
};
void B::v_function(){
    std::cout<<"I am from B"<<std::endl;
}
B::~B(){
    std::cout<<"Destructor of B is called"<<std::endl;
}
