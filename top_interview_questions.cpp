# 题目摘要
## 2019.6.9-2019.6.15 
### Range in leetcode 145 Top Interview Questions
easy:
1. https://leetcode.com/problems/two-sum/
2. https://leetcode.com/problems/power-of-three/ 

medium:
1. https://leetcode.com/problems/add-two-numbers/
2. https://leetcode.com/problems/3sum/  
3. https://leetcode.com/problems/jump-game/
4. https://leetcode.com/problems/word-break/
5. https://leetcode.com/problems/sort-list/

hard:
1. https://leetcode.com/problems/median-of-two-sorted-arrays/
2. https://leetcode.com/problems/first-missing-positive/
3. https://leetcode.com/problems/trapping-rain-water/

## 题解
//1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //use map<int/* num */, int /* index */>
        // time complexity O(n), space O(n)
        map<int, int> save;
        vector<int> res;
        auto eit = save.end();
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            if (save.find(target-nums[i]) != eit)
            {
                res.push_back(i);
                res.push_back(save[target-nums[i]]);
                break;
            }
            save[nums[i]] = i;
        }
        return res;
    }
};

//326. Power of Three
//	1. loop thought
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n)
        {
            if (n==1)
                return true;
            else if (n%3)
                return false;
            n /= 3;
        }
        return false;
    }
};

//	2.mathmatics
class Solution {
public:
    bool isPowerOfThree(int n) {        
        // 1162261467 is 3^19,  3^20 is bigger than int  
        return ( n>0 &&  1162261467%n==0);
    }
};

//	3.ln() is wrong? why
class Solution {
public:
    bool isPowerOfThree(int n) {        
        if (n <= 0) return false;
        //return fmod(log(n)/log(3), 1)==0; why wrong?
        return fmod(log10(n)/log10(3), 1)==0;
    }
};
