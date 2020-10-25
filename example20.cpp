#include <iostream>

using namespace std;
class Test{
    private:
        static int _x; //You cannot initialize it in class
    public:
        void print(){std::cout<<_x;}
};
int Test::_x=1; //should be here

int main() {
    Test t;
    t.print();
}
