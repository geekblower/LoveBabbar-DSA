#include <bits/stdc++.h>
using namespace std;

int maxSumRec(vector<int> &nums, int index, int sum) {
    if(index >= nums.size()) return sum;

    int inc = maxSumRec(nums, index+2, sum+nums[index]);
    int exc = maxSumRec(nums, index+1, sum);

    return max(inc, exc);
}

int maxSumMem(vector<int> &dp, vector<int> &nums, int index, int sum) {
    if(index >= nums.size()) return sum;
    if(dp[index] != -1) return max(sum, dp[index]);

    int inc = maxSumMem(dp, nums, index+2, sum+nums[index]);
    int exc = maxSumMem(dp, nums, index+1, sum);

    dp[index] = max(inc, exc);
    return dp[index];
}

int maxSumTab(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    dp[1] = nums[1];

    for(int i=2; i<nums.size(); i++) {
        int inc = dp[i-2] + nums[i];
        int exc = dp[i-1];

        dp[i] = max(inc, exc);
    }

    return dp[nums.size() - 1];
}

int maxSumSpc(vector<int> &nums) {
    int prev0 = 0;
    int prev1 = nums[0];

    for(int i=1; i<nums.size(); i++) {
        int inc = prev0 + nums[i];
        int exc = prev1;

        int curr = max(inc, exc);

        prev0 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    vector<int> nums;
    cout << "Enter the array (-1 to stop) : ";
    int i;
    cin >> i;
    while(i != -1) {
        nums.push_back(i);
        cin >> i;
    }

    // int ans = maxSumRec(nums, 0, 0);

    // vector<int> dp(nums.size(), -1);
    // int ans = maxSumMem(dp, nums, 0, 0);

    // int ans = maxSumTab(nums);

    int ans = maxSumSpc(nums);

    cout << "Maximum sum of non-adjacent elements : " << ans << endl;
    return 0;
}