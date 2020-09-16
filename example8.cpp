#include <iostream>
#include <exception>

class MyException:public std::exception{
    private:
    const char* msg;
    public:
    MyException(const char* s);
    const char* what();
};

void test_function(){
    throw MyException("This is my Exception");
}
int main() {
    try{
        test_function();
    }
    catch(MyException& me){
        std::cout<<me.what()<<std::endl;
    }
    catch(std::exception & exc){
        std::cout<<exc.what()<<std::endl;
    }
}

MyException::MyException(const char* s):exception(),msg(s){
    std::cout<<"MyException constructor"<<std::endl;
}
const char* MyException::what(){
    return msg;
}
