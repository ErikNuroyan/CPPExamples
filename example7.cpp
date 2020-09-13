#include <iostream>

template <typename T>
class Stack{
    private:
        const int CAPACITY;
        T * arr;
        int index;
    public:
        Stack();
        Stack(int cap);
        ~Stack();
        void push(T & e);
        T & pop();
        bool is_empty();
        bool is_full();
};

int main() {
    
    Stack<int> st_1=Stack<int>();
    Stack<double> st_2=Stack<double>(10);
    
    for(int i=0;i<10;i++){
        try{
            st_1.push(i);
            st_2.push((double&)i);
        }
        catch(const char* msg){
            std::cout<<msg<<std::endl;
        }
    }
    
    for(int i=0;i<10;i++){
        try{
            st_1.pop();
            st_2.pop();
        }
        catch(const char* msg){
            std::cout<<msg<<std::endl;
        }
    }
    
}
template<typename T>
Stack<T>::Stack():CAPACITY(5){
    arr=new T[CAPACITY];
    index=0;
}
template<typename T>
Stack<T>::Stack(int cap):CAPACITY(cap){
    arr=new T[CAPACITY];
    index=0;
}
template<typename T>
void Stack<T>::push(T & e){
    if(is_full()){
        throw "Stack is full";
        return;
    }
    arr[index++]=e;
}
template<typename T>
T& Stack<T>::pop(){
    if(is_empty()){
        throw "Stack is empty";
    }
    return arr[--index];
}
template<typename T>
Stack<T>::~Stack(){
    delete [] arr;
}

template<typename T>
bool Stack<T>::is_empty(){
    return index==0;
}
template<typename T>
bool Stack<T>::is_full(){
    return index==CAPACITY;
}
