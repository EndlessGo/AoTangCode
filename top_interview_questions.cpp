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

//2. Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//	1. convert thought but wrong!
class Solution {
public:
    //链表转成整形相加，然后再将和转成链表，这样的问题：int溢出！而直接用链表操作就不会出现
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return Number2List(List2Number(l1) + List2Number(l2));
    }
    int List2Number(ListNode* l)
    {
        int num = 0, exp = 0;
        while(l)
        {
            num += l->val * pow(10,exp++);
            l = l->next;
        }
        return num;
    }
    ListNode* Number2List(int num)
    {
        ListNode* dummy = new ListNode(0), * node = dummy;
        while(num)
        {
            ListNode* tmp = new ListNode(num%10);
            node->next = tmp;
            node = tmp;
            num /= 10;
        }
        return dummy->next;
    }
};

//55. Jump Game
//	1. Backtracking but TLE, time complexity too high O(2^n), space O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(nums, 0);
    }
    bool canJumpFromPosition(vector<int>& nums, int pos)
    {
        int end_index = nums.size()-1;
        if (pos == end_index) return true;
        int furthest = min(pos+nums[pos], end_index);
        for (int next_pos = furthest; next_pos >= pos + 1; --next_pos)
        {
            if (canJumpFromPosition(nums, next_pos))
                return true;
        }
        return false;
    }
};

//	2. DP thought but TLE, time complexity too high O(n^2), space O(n)
class Solution {
public:
    enum 
    {
        GOOD,
        BAD,
        UNKNOWN,
    };
    vector<int> memo;
    bool canJump(vector<int>& nums) {
        memo.resize(nums.size(), UNKNOWN);
        memo[nums.size()-1] = GOOD;
        return canJumpFromPosition(nums, 0);
    }
    bool canJumpFromPosition(vector<int>& nums, int pos)
    {
        if (memo[pos] != UNKNOWN)
        {
            return memo[pos] == GOOD? true : false;
        }
        int furthest = min(pos+nums[pos], (int)nums.size()-1);
        for (int next_pos = pos + 1; next_pos <= furthest; ++next_pos)
        {
            if (canJumpFromPosition(nums, next_pos))
            {
                memo[pos] = GOOD;
                return true;
            }
        }
        memo[pos] = BAD;
        return false;
    }
};

//	3.Greedy thought, O(n) time and O(n) space, AC!
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;
        for (int i = last; i >= 0; --i)
        {
            if (i+nums[i] >= last)
                last = i;        
        }
        return last == 0;
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
