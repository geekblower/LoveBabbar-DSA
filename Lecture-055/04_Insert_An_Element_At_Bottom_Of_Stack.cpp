#include <bits/stdc++.h>
using namespace std;

void inputStack(stack<int> &st) {
    int size;
    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter stack elements : ";
    for(int i=0; i<size; i++) {
        int temp;
        cin >> temp;
        st.push(temp);
    }
}

void printStack(stack<int> st) {
    cout << "Stack : ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void insertBottom(stack<int> &st, int data) {
    if(st.empty()) {
        st.push(data);
        return;
    }

    int top = st.top();
    st.pop();
    insertBottom(st, data);
    st.push(top);
}

int main() {
    stack<int> st;
    inputStack(st);

    printStack(st);

    insertBottom(st, 10);

    printStack(st);
    return 0;
}