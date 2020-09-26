#include <iostream>
#include <algorithm>
#include <initializer_list>

using namespace std;

class MyIntArray{
    private:
        int * arr;
        const int size;
    public:
        class MIAIterator{
            private:
                int index;
                int * start;
            public:
                using iterator_category = random_access_iterator_tag;       //These are all very important 
                using value_type = int;
                using difference_type = int;
                using pointer = int*;
                using reference = int&;
                MIAIterator(int* s,int i=0):index(i){start=s;};
                MIAIterator(const MIAIterator& it):index(it.index),start(it.start){};
                MIAIterator& operator=(const MIAIterator& it);
                bool operator==(const MIAIterator & it){return this->index==it.index;}
                bool operator!=(const MIAIterator & it){return this->index!=it.index;}
                bool operator <(const MIAIterator & it){return this->index<it.index;}
                bool operator <=(const MIAIterator & it){return this->index<=it.index;}
                bool operator >(const MIAIterator & it){return this->index>it.index;}
                bool operator >=(const MIAIterator & it){return this->index>=it.index;}
                MIAIterator& operator++();
                MIAIterator operator++(int);
                MIAIterator& operator--();
                MIAIterator operator--(int);
                MIAIterator operator+(int n);
                MIAIterator operator-(int n);
                int operator-(const MIAIterator & it){return this->index-it.index;}
                int& operator[](int i){return *(start+i);}
                int& operator*(){return *(start+index);}
                friend MIAIterator operator+(int n,const MIAIterator& mia);
        };
        friend class MIAIterator;
        MyIntArray(int s,int n);
        MyIntArray(initializer_list<int> il);
        ~MyIntArray();
        void print();
        MIAIterator begin(){return MIAIterator(&arr[0],0);}
        MIAIterator end(){return MIAIterator(&arr[0],size);};
};

int main() {                        
    MyIntArray mia={4,-1,8,-1,3,-8,-16,2};
    mia.print();
    sort(mia.begin(),mia.end());
    mia.print();
}
//Friend Function
MyIntArray::MIAIterator operator+(int n,const MyIntArray::MIAIterator& mia){
    return MyIntArray::MIAIterator(mia.start,mia.index+n);
}

//MyIntArray Class
MyIntArray::MyIntArray(int s=10,int n=0):size(s){
    arr=new int [size+1];
    for(int i=0;i<size;i++){
        arr[i]=n;
    }
}
MyIntArray::MyIntArray(initializer_list<int> il):size(il.size()){
    arr=new int [size+1];
    int i=0;
    for(auto it= il.begin();it!=il.end();it++,i++){
        arr[i]=(*it);
    }
}
MyIntArray::~MyIntArray(){
    delete [] arr;
}
void MyIntArray::print(){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}


//The MIAIterator Class
MyIntArray::MIAIterator& MyIntArray::MIAIterator::operator=(const MIAIterator& it){
    if(this==&it)return (*this);
    this->index=it.index;
    this->start=it.start;
    return (*this);
}
MyIntArray::MIAIterator& MyIntArray::MIAIterator::operator++(){
    this->index+=1;
    return (*this);
}
MyIntArray::MIAIterator MyIntArray::MIAIterator::operator++(int){
    this->index+=1;
    return MIAIterator(this->start,this->index-1);
}
MyIntArray::MIAIterator& MyIntArray::MIAIterator::operator--(){
    this->index-=1;
    return (*this);
}
MyIntArray::MIAIterator MyIntArray::MIAIterator::operator--(int){
    this->index-=1;
    return MIAIterator(this->start,this->index+1);
}
MyIntArray::MIAIterator MyIntArray::MIAIterator::operator+(int n){
    return MIAIterator(this->start,this->index+n);
}
MyIntArray::MIAIterator MyIntArray::MIAIterator::operator-(int n){
    return MIAIterator(this->start,this->index-n);
}



