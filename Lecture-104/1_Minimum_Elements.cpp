#include <bits/stdc++.h>
using namespace std;

/*
    Recursion
*/
int minElementsRec(vector<int> &coins, int target) {
    if(target == 0) return 0;
    if(target < 0) return INT_MAX;

    int mini = INT_MAX;

    for(int i=0; i<coins.size(); i++) {
        int ans = minElementsRec(coins, target-coins[i]);

        if(ans != INT_MAX) {
            mini = min(mini, ans+1);
        }
    }

    return mini;
}  

/*
    Recursion + Memoisation
*/
int minElementsDP(vector<int> &dp, vector<int> &coins, int target) {
    if(target == 0) return 0;
    if(target < 0) return INT_MAX;

    if(dp[target] != -1) return dp[target];

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int ans = minElementsDP(dp, coins, target-coins[i]);

        if(ans != INT_MAX) {
            mini = min(mini, ans+1);
        }
    }
    
    dp[target] = mini;
    return mini;
}

/*
    Tabulation
*/
int minElementsTab(vector<int> &coins, int target) {
    vector<int> dp(target+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=target; i++) {

        for(int c=0; c<coins.size(); c++) {

            if(i-coins[c] >= 0 && dp[i-coins[c]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-coins[c]] + 1);
            }

        }
    }

    return dp[target];
}

int main() {
    vector<int> coins;
    int target;

    cout << "Enter the coins array (-1 to stop) : ";
    int temp;
    cin >> temp;
    while(temp != -1) {
        coins.push_back(temp);
        cin >> temp;
    }

    cout << "Enter the target : ";
    cin >> target;
    
    vector<int> dp(target+1, -1);
    
    int minCoin = minElementsTab(coins, target);
    if(minCoin != INT_MAX) {
        cout << "Required minimum coins : " << minCoin << endl;
    } else {
        cout << "Required minimum coins : " << -1 << endl;
    }
    

    return 0;
}