#include <iostream>


class A{
    private:
    int x,y;
    
    public:
    A(int x,int y){
        this->x=x;
        this->y=y;
    }
    A operator+(const A& a){
        this->x+=a.x;
        this->y+=a.y;
        return (*this);
    }
    friend std::ostream& operator<<(std::ostream& os,const A& a);
};

std::ostream& operator<<(std::ostream& os,const A& a){
        os<<"x: "<<a.x<<" y: "<<a.y<<std::endl;
        return os;
}
int main() {
    A a(7,8),b(9,10);
    std::cout<<"Initial object a"<<std::endl;
    std::cout<<"Address:"<<&a<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<"Initial object b"<<std::endl;
    std::cout<<"Address:"<<&b<<std::endl;
    std::cout<<b<<std::endl;
    A c=a+b;
    std::cout<<"This is object c"<<std::endl;
    std::cout<<"Address:"<<&c<<std::endl;
    std::cout<<c<<std::endl;
    std::cout<<"After modification"<<std::endl;
    std::cout<<"_______________________________"<<std::endl;
    std::cout<<"Initial object a"<<std::endl;
    std::cout<<"Address:"<<&a<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<"Initial object b"<<std::endl;
    std::cout<<"Address:"<<&b<<std::endl;
    std::cout<<b<<std::endl;
    //As we can see c is just a copy of a after the modification
}
