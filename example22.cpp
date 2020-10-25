#include <iostream>

using namespace std;

class Test{
    private:
        //Not here
    protected:
        //Not here
    public:
        //Should be here for polymorhpism
        virtual void print(){std::cout<<"Test"<<std::endl;} 
        
};
class Test_Derived:public Test{
    private:
        
    public:
        void print(){std::cout<<"Test_Derived"<<std::endl;}
};
int main() {
    Test * T_ptr=new Test_Derived();
    T_ptr->print();
}
