#include <iostream>
#include <algorithm>

using namespace std;

int increment_1(int x){return x+1;};
class Functor{
    private:
        int par;
    public:
        Functor(int p):par{p}{};
        int operator() (int x){return x+par;}
};
int main() {
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    std::transform(arr,arr+n,arr,increment_1);//When used in this form increment_1 should be unary(takes 1 parameter)
    for(int i:arr)
        std::cout<<i<<" ";
    cout<<endl;
    //If we want to have 2 parameters, the number by which we want to increment be 2nd parameter
    //We may use Functors(have operator() overloaded), objects of which behave like functions
    int par_2=7;
    Functor func=Functor(par_2);
    std::transform(arr,arr+n,arr,func);
    for(int i:arr)
        std::cout<<i<<" ";
    cout<<endl;
    
    return 0;
}
