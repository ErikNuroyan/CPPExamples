#include <iostream>
#include <functional> //IMPORTANT! To be always included 

class MyFunctor{
    private:
    public:
        int operator()(int x,int p);
};
int power(int x,int p);

template<class Functor>
void power_transform(int * arr,int n,int p,Functor f); 

int main() {
    //The prvious approach would create 2 different versions for power_transform function one for MyFunctor 
    //object and the other one for function pointer 
    //Using function wrapper reduces the problem to create one function of specified type
    int arr[]={1,2,3,4};
    std::function<int(int,int)> function_wrapper=MyFunctor();//Using MyFunctor object
    power_transform<std::function<int(int,int)>>(arr,4,2,function_wrapper);
    for(int i:arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    function_wrapper=power;//changing the wrapper to power function pointer
    power_transform<std::function<int(int,int)>>(arr,4,2,function_wrapper);
    for(int i:arr)
        std::cout<<i<<" ";
    //The Function wrapper template type should be of this general form
    //std::function<return_type(parameter_type1,parameter_type2...)>
    
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
