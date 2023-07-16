#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr) {
    vector<int> solution(arr);
    stack<int> st;
    st.push(-1);

    for(int i=arr.size()-1; i>=0; i--) {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr) {
            st.pop();
        }

        solution[i] = st.top();
        st.push(i);
    }

    return solution;
}

vector<int> previousSmallerElement(vector<int> arr) {
    vector<int> solution(arr);
    stack<int> st;
    st.push(-1);

    for(int i=0; i<arr.size(); i++) {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr) {
            st.pop();
        }

        solution[i] = st.top();
        st.push(i);
    }

    return solution;
}

int largestRectangularArea(vector<int> height) {
    int n = height.size();
    int maxArea = 0;
    vector<int> next = nextSmallerElement(height);
    vector<int> prev = previousSmallerElement(height);

    for(int i=0; i<n; i++) {
        if(next[i] == -1) {
            next[i] = n;
        }

        int length = height[i];
        int breadth = next[i] - prev[i] - 1; 

        int newArea = length * breadth;
        maxArea = max(newArea, maxArea);
    }

    return maxArea;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};

    cout << "Required area : " << largestRectangularArea(height) << endl;

    return 0;
}