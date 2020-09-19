#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <list>

int main() {
    using namespace std;
    vector<int> v;
    set<double> s;
    list<int> l;
    
    for(int i=0;i<25;i++){
        v.push_back(i);
        s.insert(i);
    }
    cout<<"Vector: ";
    ostream_iterator<int> o(cout," ");
    copy(v.begin(),v.end(),o);
    cout<<endl;
    
    cout<<"Set: ";
    copy(s.begin(),s.end(),o);
    
    for(int i=0;i<25;i++){
        s.insert(i);
    }
    cout<<endl;
    cout<<"Set after reinsertion: ";
    copy(s.begin(),s.end(),o);
    
    for(int i=0;i<10;i++){
        l.push_front(i);
        l.push_back(i);
    }
    cout<<endl;
    cout<<"List: ";
    copy(l.begin(),l.end(),o);
}
