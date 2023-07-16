// Design a special stack with getMin() method which works in O(1) time 
    // and O(1) pace complexity!

#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> st;
    int minE;

    public:
    void push(int data) {
        if(st.empty()) {
            st.push(data);
            minE = data;
        } else {

            if(data < minE) {
                st.push(2*data - minE);
                minE = data;
            } else {
                st.push(data);
            }

        }
    }

    int pop() {
        if(st.empty()) {
            return -1;
        } else {
            int curr = st.top();
            st.pop();

            if(curr > minE) {
                return curr;
            } else {
                int prevMin = minE;
                minE = 2*minE - curr;
                return prevMin;
            }

        }
    }

    int top() {
        if(st.empty()) {
            return -1;
        } else {
            return (st.top() > minE) ? st.top() : minE;
        }
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        return (st.empty()) ? -1 : minE;
    }
};

int main() {
    return 0;
}