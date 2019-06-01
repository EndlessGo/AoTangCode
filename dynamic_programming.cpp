//53.Maximum Subarray
//  1. basic thoughts, time complexity O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = INT_MIN;
        for (auto num : nums)
        {
            if (sum < 0)
                sum = max(sum, num);
            else
                sum += num;         
            res = max(res, sum);
        }
        return res;
    }
};
//  2. DP thoughts, time complexity O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 0;
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < size; ++i)
        {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            res = max(res, dp[i]);
        }
        return res;
    }
};

//322. Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        //init
        dp[0] = 0;
        int size = coins.size();
        for (int i = 1; i < amount+1; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (i >= coins[j])
                {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] != amount+1? dp[amount]:-1;
    }
};
