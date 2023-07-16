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

int maxArea(vector<vector<int>> matrix) {
    int area = largestRectangularArea(matrix[0]);
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=1; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] += matrix[i-1][j];
            } else {
                matrix[i][j] = 0;
            }
        }

        int currArea = largestRectangularArea(matrix[i]);
        area = max(area, currArea);
    }

    return area;
}

int main() {
    vector<vector<int>> matrix;
    int size;

    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the matrix : ";
    // 0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0
    for(int i=0; i<size; i++) {
        vector<int> temp(size);
        for(int j=0; j<size; j++) {
            cin >> temp[j];
        }
        matrix.push_back(temp);
    }

    cout << "Maximum area : " << maxArea(matrix) << endl;

    return 0;
}