//53.Maximum Subarray
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
