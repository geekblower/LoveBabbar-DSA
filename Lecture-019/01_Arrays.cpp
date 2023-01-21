#include <iostream>
#include <array>
using namespace std;

int main() {
    int basic[3] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for(int i=0; i<size; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"Size of array = "<<a.size()<<endl;

    cout<<"Element at second index = "<<a.at(2)<<endl;

    cout<<"Empty or not = "<<a.empty()<<endl;

    cout<<"First element = "<<a.front()<<endl;
    cout<<"Last element = "<<a.back()<<endl;

    return 0;
}