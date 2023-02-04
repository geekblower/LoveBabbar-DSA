#include <iostream>
#include <vector>
using namespace std;

int main() {
    int basic[3] = {1, 2, 3};

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    int size = v.size();

    for(int i=0; i<size; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<"Size of vector = "<<v.size()<<endl;
    cout<<"Capacity of vector = "<<v.capacity()<<endl;

    cout<<"Element at second index = "<<v.at(2)<<endl;

    cout<<"Empty or not = "<<v.empty()<<endl;

    cout<<"First element = "<<v.front()<<endl;
    cout<<"Last element = "<<v.back()<<endl;


    cout<<"\nBefore pop operation : ";
    for(int i:v) {
        cout<<i<<" ";
    }

    v.pop_back();
    
    cout<<"\nAfter pop operation : ";
    for(int i:v) {
        cout<<i<<" ";
    }

    cout<<"\n\nBefore clear operation : Size = "<<v.size()<<endl;

    v.clear();

    cout<<"After clear operation : Size = "<<v.size()<<endl;

    vector<int> v1(5, 1);
    cout<<"\nPrinting new vector : ";
    for(int i:v1) {
        cout<<i<<" ";
    }

    return 0;
}