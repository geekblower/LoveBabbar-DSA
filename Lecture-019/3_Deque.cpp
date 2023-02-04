#include <iostream>
#include <deque>
using namespace std;

int main() {
    int basic[3] = {1, 2, 3};

    deque<int> d;

    d.push_back(1);
    d.push_back(2);

    d.push_front(3);
    d.push_front(4);

    for(int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    // d.pop_back() ;

    // for(int i:d) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // d.pop_front();

    // for(int i:d) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    cout<<"Size of deque = "<<d.size()<<endl;

    cout<<"Element at second index = "<<d.at(2)<<endl;

    cout<<"First element = "<<d.front()<<endl;
    cout<<"Last element = "<<d.back()<<endl;

    cout<<"Empty or not : "<<d.empty()<<endl;

    d.erase(d.begin(), d.begin()+1);
    
    for(int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}