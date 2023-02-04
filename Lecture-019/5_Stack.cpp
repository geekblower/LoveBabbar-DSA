#include <iostream>
#include <stack>
using namespace std;

int main() {
    int basic[3] = {1, 2, 3};

    stack<string> s;

    s.push("Akash");
    s.push("Gautam");


    cout<<"First element : "<<s.top()<<endl;

    s.pop();

    cout<<"First element after pop : "<<s.top()<<endl;

    cout<<"Size of stack : "<<s.size()<<endl;
    cout<<"Empty or not : "<<s.empty()<<endl;

    return 0;
}




// Wo nahi mera, magar usse mohabbat hai to hai...
// Ye agar rashmo reewajo se bagawat hai to hai...
// Sach ko maine sach kha, jab keh diya to keh diya...
// Ab jamane ki najar me ye hamaqat hai to hai...

// Dost ban ke dushmano sa wo satata hai mujhe...
// Phir bhi us jaalim pe marna, apni fidrat hai to hai...