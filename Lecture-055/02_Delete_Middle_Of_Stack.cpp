#include <bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &st, int count, int size) {
    if(count == size/2) {
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();

    deleteMiddle(st, count+1, size);

    st.push(top);
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);

    int count = 0;
    int n = st.size();

    cout << "Size of stack : " << st.size() << endl;

    deleteMiddle(st, count, n);

    cout << "Size of stack : " << st.size() << endl;

    return 0;
}