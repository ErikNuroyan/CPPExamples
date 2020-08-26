#include <iostream>


class A{
    private:
    int x,y;
    
    public:
    A(int x,int y){
        this->x=x;
        this->y=y;
    }
    //Automatic(Implicit) type conversion to int
    //It returns x times y
    
    operator int(){
        std::cout<<"Implicit"<<std::endl;
        return this->x*this->y;
    }
    
    /*
    explicit operator int(){
        std::cout<<"Explicit"<<std::endl;
        return this->x*this->y;
    }
    */
};

int main() {
    A a(7,8);
    std::cout<<int(a)<<std::endl;//Will work with implicit and explicit
    int z=a;//Will work only with implicit
}
