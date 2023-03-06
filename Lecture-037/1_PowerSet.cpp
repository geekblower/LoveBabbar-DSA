#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> arr, vector< vector<int> > &solution, vector<int> output, int index) {
    if(index == arr.size()) {
        solution.push_back (output);
        return;
    }

    subsets(arr, solution, output, index+1);

    output.push_back (arr[index]);
    subsets(arr, solution, output, index+1);
}

vector< vector<int> > powerSet(vector<int> arr) {
    vector< vector<int> > solution;
    vector<int> output;
    int index = 0;

    subsets(arr, solution, output, index);

    return solution;
}

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array : ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    vector< vector<int> > answer = powerSet(arr);

    cout << "All subsets : " << endl;
    for(int i=0; i<answer.size(); i++) {
        cout << "[ ";
        for(int j=0; j<answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}