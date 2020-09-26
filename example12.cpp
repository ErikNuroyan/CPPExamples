#include <iostream>
using namespace std;
class MyString{
    private:
        string s;
    public:
        MyString(const string& ss):s(ss){};
        MyString(const MyString& ms):s(ms.s){
            cout<<"Copy Constructor"<<endl;
        }
        MyString& operator=(const MyString& ms){
            std::cout<<"Assignment"<<std::endl;
            if(this==&ms)return (*this);
            this->s=ms.s;
            return (*this);
        }
        string getS(){return this->s;}
        void setS(const string & ss){s=ss;}
};

int main() {
    int a=5;
    int b=7;
    int& a_ref=a;
    int& b_ref=b;
    a_ref=b_ref;
    std::cout<<a_ref<<"  "<<b_ref<<endl;
    a_ref++;
    std::cout<<a_ref<<"  "<<b_ref<<endl;
    MyString ms_1("One");
    MyString ms_2("Two");
    MyString& ms_1_ref=ms_1;
    MyString& ms_2_ref=ms_2;
    ms_1=ms_2;
    std::cout<<ms_1.getS()<<"  "<<ms_2.getS()<<endl;
    ms_1.setS("Smth");
    std::cout<<ms_1.getS()<<"  "<<ms_2.getS()<<endl;
    //As we can see assigning one reference to another 
    //Uses the assignment operator for objects
    //And for primitive types copies the value not the address

}
