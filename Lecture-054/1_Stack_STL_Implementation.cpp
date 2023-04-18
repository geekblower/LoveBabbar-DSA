#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creation of stack
    stack<int> s;

    // Push operation
    s.push(10);
    s.push(61);

    // Size operation
    cout << "Current size of stack : " << s.size() << endl;

    // Peek operation
    cout << "Top element : " << s.top() << endl;

    // Pop operation
    s.pop();

    cout << "Current size of stack : " << s.size() << endl;
    cout << "Top element : " << s.top() << endl;

    if(s.empty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    s.pop();
    
    if(s.empty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    cout << "Current size of stack : " << s.size() << endl;
    return 0;
}