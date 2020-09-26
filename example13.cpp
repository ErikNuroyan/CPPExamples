#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    private:
        char* s;
    public:
        MyString(const char* ss){
            std::cout<<"Constructor"<<std::endl;
            int length=strlen(ss);
            s=new char[length];
            for(int i=0;i<length;i++){
                s[i]=ss[i];
            }
        };
        MyString(const MyString& ms){
            cout<<"Copy Constructor"<<endl;
            int length=strlen(ms.s);
            s=new char[length];
            for(int i=0;i<length;i++){
                s[i]=ms.s[i];
            }
        }
        //Move constructor
        MyString(MyString&& ms){
            std::cout<<"Move Constructor"<<std::endl;
            this->s=ms.s;
            ms.s=nullptr;   //Done to prevent deletion of ms.s which was assigned to this->s
        }
        MyString& operator=(const MyString& ms){
            std::cout<<"Assignment"<<std::endl;
            if(this==&ms)return (*this);
            int length=strlen(ms.s);
            for(int i=0;i<length;i++){
                this->s[i]=ms.s[i];
            }
            return (*this);
        }
        ~MyString(){
            delete [] s;
        }
        const char* getS(){return this->s;}
        void setS(const char* ss){
            delete s;
            int length=strlen(ss);
            s=new char[length];
            for(int i=0;i<length;i++){
                s[i]=ss[i];
            }
        }
};

class Another{
    private:
        MyString mys;
    public:
        Another(const MyString& ms):mys(ms){};
        Another(MyString&& ms):mys((MyString&&)ms){};
};

int main() {                        
                                 //If There's no move constructor
    Another("What");             //Implicit invokation of MyString(const char* )
                                 //If the constructor was explicit there would be 
                                 //No matching call for constructor
                                 
    //A temporary object is created and copied if there's no move constructor
    //Move constructor takes as an argument a reference to rvalue 
    
    //If there's move constructor it takes the temporarily created object 
    //assigns its pointers and other stuff to the object to be created
    //And when the temporary object is destructed, these actions make sure
    //that the data it had are unaffected
    
}
