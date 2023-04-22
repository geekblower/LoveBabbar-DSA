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

void insertSorted(stack<int> &st, int data) {
    if(st.empty() || (!st.empty() && st.top() <= data)) {
        st.push(data);
        return;
    }

    int top = st.top();
    st.pop();

    insertSorted(st, data);
    st.push(top);
}

void sortStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int top = st.top();
    st.pop();

    sortStack(st);
    insertSorted(st, top);
}

int main() {
    stack<int> st;
    inputStack(st);

    cout << "Before Sorting : ";
    printStack(st);

    sortStack(st);

    cout << "After Sorting : ";
    printStack(st);
    return 0;
}