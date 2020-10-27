#include <iostream>

using namespace std;

class MyFunctor{
    private:
    public:
        int operator()(int x,int p);
};
int power(int x,int p);

template<class Functor>
void power_transform(int * arr,int n,int p,Functor f); 

int main() {
    int arr[]={3,4,8,10};
    MyFunctor mf;
    power_transform(arr,(sizeof(arr)/sizeof(int)),3,mf);
    std::cout<<"Using Functor"<<std::endl;
    for(int x:arr){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl<<"Using Simple Function"<<std::endl;
    power_transform(arr,(sizeof(arr)/sizeof(int)),3,power);
    for(int x:arr){
        std::cout<<x<<" ";
    }
    //Note: it calculates corresponding powers on already modified version of arr
}
template<class Functor>
void power_transform(int * arr,int n,int p,Functor f){
    for(int i=0;i<n;i++){
        arr[i]=f(arr[i],p);
    }
}
int MyFunctor::operator()(int x,int p){
    int res=1;
    for(int i=1;i<=p;i++){
        res*=x;
    }
    return res;
}
int power(int x,int p){
    if(p==0){
        return 1;
    }
    int x1=power(x,p/2);
    if(p%2==0){
        return x1*x1;
    }
    else{
        return x1*x1*x;
    }
}
