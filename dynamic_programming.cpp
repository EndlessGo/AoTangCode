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

//70. Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i < n+1; ++i)
            dp[i] = dp[i-1]+dp[i-2];
        return dp[n];
    }
};

//120. Triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //bottom-to-top
        //two dimensionals thought : dp[i-1][j] = triangle[i][j] + min(triangle[i][j], triangle[i][j+1]);
        //can be reduced into one dimensional:  dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2 ; i >= 0; --i)
        {
            for(int j = 0; j <= i; ++j)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp.empty()? 0:dp[0];
    }
};

//121. Best Time to Buy and Sell Stock
//  1. DP thoughts, time complexity O(n), space complexity O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        //profit[i] = max(profit[i-1], prices[i]-min(prices[j])), profit[i] means 1~i'th day max profit, j=0~i-1
        int size = prices.size(), min_in_range = prices[0];
        vector<int> profit(size, 0);
        for (int i = 1; i < size; ++i)
        {
            min_in_range = min(min_in_range, prices[i-1]);
            profit[i] = max(profit[i-1], prices[i] - min_in_range);
        }
        return *max_element(profit.begin(), profit.end());
    }
};
//  2. DP thoughts, time complexity O(n), space complexity O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (!size) return 0;
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < size; ++i)
        {
            min_price = min(min_price, prices[i-1]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};

//309. Best Time to Buy and Sell Stock with Cooldown
class Solution {
public:
    int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}
};

//322. Coin Change
//  1. DP thoughts, time complexity O(m*n) m = coins.size(), n = amount, space complexity O(n)
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

