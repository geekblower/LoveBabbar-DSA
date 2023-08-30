#include <bits/stdc++.h>
using namespace std;

int cutSegmentsRec(int n, int x, int y, int z) {
    if(n == 0) {return 0;}
    if(n < 0) {return INT_MIN;}

    int cutx = cutSegmentsRec(n-x, x, y, z) + 1;
    int cuty = cutSegmentsRec(n-y, x, y, z) + 1;
    int cutz = cutSegmentsRec(n-z, x, y, z) + 1;

    return max(cutx, max(cuty, cutz));
}

int cutSegmentsMem(vector<int> &dp, int n, int x, int y, int z) {
    if(n == 0) {return 0;}
    if(n < 0) {return INT_MIN;}

    if(dp[n] != -1) {return dp[n];}

    int cutx = cutSegmentsMem(dp, n-x, x, y, z) + 1;
    int cuty = cutSegmentsMem(dp, n-y, x, y, z) + 1;
    int cutz = cutSegmentsMem(dp, n-z, x, y, z) + 1;

    dp[n] = max(cutx, max(cuty, cutz));
    return dp[n];
}

int cutSegmentsTab(int n, int x, int y, int z) {
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        if(i-x >= 0) dp[i] = max(dp[i], dp[i-x] + 1);
        if(i-y >= 0) dp[i] = max(dp[i], dp[i-y] + 1);
        if(i-z >= 0) dp[i] = max(dp[i], dp[i-z] + 1);
    }

    return dp[n] < 0 ? 0 : dp[n];
}

int cutSegmentsTab(int n, int x, int y, int z) {
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        if(i-x >= 0) dp[i] = max(dp[i], dp[i-x] + 1);
        if(i-y >= 0) dp[i] = max(dp[i], dp[i-y] + 1);
        if(i-z >= 0) dp[i] = max(dp[i], dp[i-z] + 1);
    }

    return dp[n] < 0 ? 0 : dp[n];
}

int main() {
    int n, x, y, z;
    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Enter the value of x, y and z : ";
    cin >> x >> y >> z;
    
    cout << "Max cuts : " << cutSegmentsRec(n, x, y, z) << endl;

    vector<int> dp(n+1, -1);
    cout << "Max cuts : " << cutSegmentsMem(dp, n, x, y, z) << endl;
   
    return 0;
}