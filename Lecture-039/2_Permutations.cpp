#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, vector< vector<int> > &solution, int index) {
    if(index == arr.size()) {
        solution.push_back(arr);
        return;
    }

    for(int i=index; i<arr.size(); i++) {
        swap(arr[i], arr[index]);
        solve(arr, solution, index+1);
        swap(arr[i], arr[index]);
    }
}

vector< vector<int> > permutations(vector<int> arr) {
    vector< vector<int> > solution;
    int index = 0;

    solve(arr, solution, index);
    sort(solution.begin(), solution.end());
    return solution;
}

int main() {
    int size;
    cout << "Enter the size : ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements : ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }
    
    vector< vector<int> > solution = permutations(arr);
    
    cout << "All permutations : " << endl;
    for(int i=0; i<solution.size(); i++) {
        cout << "[ ";
        for(int j=0; j<solution[i].size(); j++) {
            cout << solution[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}