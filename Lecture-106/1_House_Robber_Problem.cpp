#include <bits/stdc++.h>
using namespace std;

int maxMoneyRec(vector<int> &houses, int index, int n, int sum) {
    if(index >= n) return sum;

    int inc = maxMoneyRec(houses, index+2, n, sum+houses[index]);
    int exc = maxMoneyRec(houses, index+1, n, sum);

    return max(inc, exc);
}

int maxMoneyMem(vector<int> &dp, vector<int> &houses, int index, int n, int sum) {
    if(index >= n) return sum;
    if(dp[index] != -1) return max(sum, dp[index]);

    int inc = maxMoneyMem(dp, houses, index+2, n, sum+houses[index]);
    int exc = maxMoneyMem(dp, houses, index+1, n, sum);

    dp[index] = max(inc, exc);
    return dp[index];
}

int maxMoneyTab(vector<int> &houses, int index, int n, int sum) {
    vector<int> dp(houses.size(), -1);

    dp[0] = 0;
    dp[1] = houses[index];

    for(int i=index+1; i<n; i++) {
        int inc = dp[i-2] + houses[i];
        int exc = dp[i-1];

        dp[i] = max(inc, exc);
    }

    return max(dp[n-1], dp[n-2]);
}

int maxMoneySpc(vector<int> &houses, int index, int n) {
    int prev0 = 0;
    int prev1 = houses[index];

    for(int i=index+1; i<n; i++) {
        int inc = prev0 + houses[i];
        int exc = prev1;

        int curr = max(inc, exc);

        prev0 = prev1;
        prev1 = curr;
    }

    return max(prev0, prev1);
}

int main() {
    vector<int> houses;
    cout << "Enter the money of houses (-1 to stop) : ";
    int i;
    cin >> i;
    while(i != -1) {
        houses.push_back(i);
        cin >> i;
    }

    int money1 = maxMoneyRec(houses, 0, houses.size()-1, 0);
    int money2 = maxMoneyRec(houses, 1, houses.size(), 0);

    cout << "Maximum money that can be robbed : " << max(money1, money2) << endl;

    return 0;
}
