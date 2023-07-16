#include <bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int>> matrix) {
    stack<int> st;
    int size = matrix.size();

    // Step 1 :
    for(int i=0; i<size; i++) {
        st.push(i);
    }

    // Step 2 :
    while(st.size() != 1) {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        
        // Step 3 :
        if(matrix[first][second] == 1) {
            st.push(second);
        } else {
            st.push(first);
        }
    }

    // Step 5 : Verifing potential celebrity
    int candidate = st.top();

    for(int i=0; i<size; i++) {
        if(matrix[candidate][i] != 0) {
            return -1;
        }

        if(matrix[i][candidate] != 1 && candidate != i) {
            return -1;
        }
    }

    return candidate;
}

int main() {
    vector<vector<int>> matrix;
    int size;

    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the matrix : ";
    for(int i=0; i<size; i++) {
        vector<int> temp(size);
        for(int i=0; i<size; i++) {
            cin >> temp[i];
        }
        matrix.push_back(temp);
    }

    int celeb = findCelebrity(matrix);
    cout << "Celebrity element : " << celeb << endl;

    return 0;
}