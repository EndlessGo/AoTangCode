# 题目摘要  
## 2019.6.9-2019.6.15  
### Range in leetcode 145 Top Interview Questions  
easy:
1. https://leetcode.com/problems/two-sum/
2. https://leetcode.com/problems/power-of-three/ 

medium:
1. https://leetcode.com/problems/add-two-numbers/
2. https://leetcode.com/problems/3sum/  		Redo
3. https://leetcode.com/problems/jump-game/		Redo
4. https://leetcode.com/problems/word-break/		Redo
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

//	2.simplified list operation use dummy head, AC!
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 || l2)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry)
        {
            cur->next = new ListNode(carry);
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

//15. 3Sum
//	1.Discuss solution use two pointers and sort unique, AC!
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {
                int sum = nums[front] + nums[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1]) front++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
};

//139. Word Break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, Dict);
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.size();
        //dp[i] means can find word sequence from wordDict end in index i
        vector<bool> dp(size+1, false);
        dp[0] = true;
        for(int i = 1; i <= size; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                //notice that c++ string.substr(start_index, length)
                if (dp[j] && wordDict.end() != wordDict.find(s.substr(j, i-j)))
                {
                        dp[i] = true;
                        break;
                }
            }
        }
        return dp[size];
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
