#include <bits/stdc++.h>
using namespace std;

vector<int> smallerElements(vector<int> arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> answer(arr);

    for(int i=n-1; i>=0; i--) {
        while(st.top() >= arr[i]) {
            st.pop();
        }

        answer[i] = st.top();
        st.push(arr[i]);
    }

    return answer;
}

int main() {
    vector<int> arr = {2,3,1};
    vector<int> ans = smallerElements(arr, arr.size());

    cout << "Original array : ";
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Smaller array : ";
    for(int i=0; i<arr.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}