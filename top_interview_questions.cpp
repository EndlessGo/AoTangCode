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

## 2019.6.17-2019.6.23
### Tree专题
MEDIUM
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
https://leetcode.com/problems/path-sum/
https://leetcode.com/problems/path-sum-ii/                                      
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/        
HARD
https://leetcode.com/problems/recover-binary-search-tree/
### 动态规划专题
easy:
1. https://leetcode.com/problems/climbing-stairs/
medium:
1. https://leetcode.com/problems/unique-paths/
2. https://leetcode.com/problems/longest-palindromic-substring/        
### 二进制专题
easy:
1. www.lintcode.com/zh-cn/problem/count-1-in-binary
2. www.lintcode.com/zh-cn/problem/add-binary

# 题目摘要
## 2019.6.24-2019.6.30
###链表专题
easy:
1. https://leetcode.com/problems/linked-list-cycle/
medium:
1. https://leetcode.com/problems/linked-list-cycle-ii/
2. https://leetcode.com/problems/rotate-list/

###二分查找
medium:
1. https://leetcode.com/problems/search-in-rotated-sorted-array/
2. https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
3. https://leetcode.com/problems/search-a-2d-matrix/

###搜索专题
medium:
1. https://leetcode.com/problems/pacific-atlantic-water-flow/          
2. https://leetcode.com/problems/decode-string/                         
hard:
1. https://leetcode.com/problems/24-game/                               
2. https://leetcode.com/problems/recover-binary-search-tree/

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
5. https://leetcode.com/problems/sort-list/		Redo

hard:
1. https://leetcode.com/problems/median-of-two-sorted-arrays/	Redo
2. https://leetcode.com/problems/first-missing-positive/	Redo
3. https://leetcode.com/problems/trapping-rain-water/		Redo

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

//4. Median of Two Sorted Arrays
//	1. Recursion, O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return ( getkth(nums1, m ,nums2, n, l) + getkth(nums1, m ,nums2, n, r) ) / 2.0;
    }
    int getkth(vector<int>& nums1, int m, vector<int>& nums2, int n, int k){//find kth num in nums1 and nums2
        // let m <= n
        if (m > n) 
            return getkth(nums2, n, nums1, m, k);
        if (m == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);

        int i = min(m, k / 2), j = min(n, k / 2);
        if (nums1[i - 1] > nums2[j - 1]){
            vector<int> vec(nums2.begin() + j,nums2.end());
            return getkth(nums1, m, vec, n - j, k - j);
        }
            
        else{
            vector<int> vec(nums1.begin() + i,nums1.end());
            return getkth( vec, m - i, nums2, n, k - i);
        }
            
        return 0;
    }
};

//	2.Binary Search, log(min(m,n)) video https://www.youtube.com/watch?v=LPFhl65R7ww
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //ensure x <= y, to make time complexity log(min(x,y)) and we only move num in short vector
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        //partitionX = partition(x) means divide two parts in nums1, left are[0...x-1] and right are [x...m)
        //partitionX + partitionY = (x+y+1)/2, plus 1 ensure in odd case left part can contain one num more.
        int low = 0, high = m;
        while (low <= high)
        {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1)/ 2 - partitionX;
            
            int maxLeftX = (partitionX == 0)?INT_MIN:nums1[partitionX-1];
            int minRightX = (partitionX == m)?INT_MAX:nums1[partitionX];
            
            int maxLeftY = (partitionY == 0)?INT_MIN:nums2[partitionY-1];
            int minRightY = (partitionY == n)?INT_MAX:nums2[partitionY];
                
            if (maxLeftX <= minRightY && maxLeftY <= minRightX)
            {
                if ((m+n)%2)//odd
                    return (double)max(maxLeftX, maxLeftY);
                return (max(maxLeftX,maxLeftY) + min(minRightX, minRightY))/2.0;
            }
            else if (maxLeftX > minRightY)
                high = partitionX - 1;
            else
                low = partitionX + 1;
        }
        //throw err
        throw 0.0;
    }
};

//41. First Missing Positive
//	1. My thought,time complexity O(n), but space O(n)!
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // nums.size() can save size count integers [1,2,...,size, size+1] names record, so can direct find nums[i] in record
        int size = nums.size();
        if (!size) return 1;
        unordered_map<int, bool> record;
        for (int i = 1; i <= size+1; ++i)
        {
            //O(n) time but O(n) space!!!
            record.insert(pair<int,bool>(i,false));
        }
        for (auto num : nums)
        {
            auto it = record.find(num), eit = record.end();
            if ( it != eit && it->second == false)
            {
                it->second = true;
            }
        }
        int small = INT_MAX;
        for (auto it = record.begin(), eit = record.end(); it != eit; ++it)
        {
            if (it->second == false)
                small = min(small , it->first);
        }
        return small;
    }
};
//	2. Wonderfull thought,time complexity O(n) and space O(1)!
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};

//42. Trapping Rain Water
//	1. Solution DP thought, O(n) time and O(n) space!
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (!size) return 0;
        int ans = 0;
        //left_max[i] mean the heightest from left, as left_max[0] to left_max[i]
        vector<int> left_max(size,0);
        vector<int> right_max(size,0);
        left_max[0] = height[0];
        for (int i = 1; i < size; ++i)
            left_max[i] = max(height[i], left_max[i-1]);
        right_max[size-1] = height[size-1];
        for (int i = size-2; i >= 0 ; --i)
            right_max[i] = max(height[i], right_max[i+1]);
        for (int i = 0; i < size; ++i)
            ans += min(left_max[i], right_max[i]) - height[i];//key algorithm
        return ans;
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

//148. Sort List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //i can do O(n^2) like selection sort or bubble sort, how to reduce to O(n log n)? --> merge sort!
        if (!head || !head->next)   return head;
        ListNode* second = partion(head);
        head = sortList(head);
        second = sortList(second);
        return merge(head, second);
    }
private:
    ListNode* partion(ListNode *head)
    {
        //partion list into two part use fast-slow pointers
        if (!head || !head->next)   return head;
        ListNode* fast = head->next, * slow = head;
        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        return second;
    }
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        //merge two sorted list with l1 and l2 node, no new ListNode!
        if (!l1)    return l2;
        if (!l2)    return l1;
        ListNode* head = l1;
        if (l1->val > l2->val)
        {
            head = l2;
            l2 = l1;
            l1 = head;
        }
        while (l1->next)
        {
            if (l1->next->val > l2->val)
            {
                ListNode* temp = l2;
                l2 = l1->next;
                l1->next = temp;
            }
            l1 = l1->next;
        }
        l1->next = l2;
        return head;
    }
};
//can simplified see https://leetcode.com/problems/sort-list/discuss/46714/Java-merge-sort-solution


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

## 2019.6.17-2019.6.23  
### Tree专题  
MEDIUM
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
https://leetcode.com/problems/path-sum/
https://leetcode.com/problems/path-sum-ii/					Optimize code
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/		Optimize code
HARD
https://leetcode.com/problems/recover-binary-search-tree/

//112. Path Sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        //cout<<"sum="<<sum<<" "<<"value="<<root->val<<endl;
        if (!root->left && !root->right)//leaf node
            if(sum-root->val == 0) return true;
        bool left = false, right = false;
        if (root->left)
            left = hasPathSum(root->left, sum-root->val);
        if (root->right)
            right = hasPathSum(root->right, sum-root->val);
        return  left || right;
    }
};

//113. Path Sum II
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        findPathSum(root, sum, path);
        return res;
    }
    void findPathSum(TreeNode* root, int sum, vector<int>& path) {
        if(!root)
            return;
        //cout<<"sum="<<sum<<" "<<"valu="<<root->val<<endl;
        path.push_back(root->val);
        if (!root->left && !root->right)//leaf node
        {
            if(sum-root->val == 0) 
            {                
                res.push_back(path);
                return;
            }
        }        
        if (root->left)
        {
            findPathSum(root->left, sum-root->val, path);
            path.pop_back();
        }
        if (root->right)
        {
            findPathSum(root->right, sum-root->val, path);
            path.pop_back();
        }
        return;
    }
private:
    vector<vector<int>> res;
};

//103. Binary Tree Zigzag Level Order Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        bool odd = true;
        que.push(root);
        while (!que.empty())
        {
            int level_size = que.size();
            vector<int> level;
            for (int i = 1; i <= level_size; ++i)
            {
                TreeNode* node = que.front();
                level.push_back(node->val);
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            if (!odd)
            {
                reverse(level.begin(),level.end());
            }
            odd = !odd;
            res.push_back(level);
        }
        return res;
    }
};

### 动态规划专题  
easy:  
1. https://leetcode.com/problems/climbing-stairs/  see dynamic_programming.cpp 70. Climbing Stairs
medium:  
1. https://leetcode.com/problems/unique-paths/
2. https://leetcode.com/problems/longest-palindromic-substring/		Optimize time

//62. Unique Paths
//	1. time O(mn), space O(mn)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        //grid[i][j] = grid[i-1][j] + grid[i][j-1]
        //init grid[0][0~m-1] = 1 and grid[0~n-1][0] = 1
        vector<vector<int>> grid(n, vector<int>(m,0));
        for (int i = 0; i < m; ++i)
            grid[0][i] = 1;
        for (int i = 1; i < n; ++i)
            grid[i][0] = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[n-1][m-1];
    }
};

//	2. O(mn) time and O(min(m,n)) space
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m > n) return uniquePaths(n,m);// ensure m <= n
        //grid[i] = grid[i-1] + grid[i]
        vector<int> grid(m,0);
        grid[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
                grid[j] += grid[j-1];
        }
        return grid[m-1];
    }
};

//5. Longest Palindromic Substring
//	1.O(n^3), out time limit
class Solution {
public:
    string longestPalindrome(string s) {
        //dp[i] means longest palindromic substring's length in s[0]..s[i-1]
        //dp[i] = max( dp[i-1], len(string that contain s[i-1]) ), so we can find from s[i-1] to s[0]
        string res;
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j <= i; ++j)// worst case need O(1^2+2^2+n^2)->o(n^3)
            {
                int temp_size = i-j+1;
                if (res.size() >= temp_size)//after no need to check palindrome
                    break;
                string temp = s.substr(j,temp_size);
                //cout<<"i="<<i<<" j="<<j<<" temp="<<temp<<endl;
                if (isPalindrome(temp))
                {
                    if ( res.size() < temp_size)
                    {
                        res = temp;
                        //cout<<"i="<<i<<" j="<<j<<" res="<<temp<<endl;
                    }
                    break;
                }
            }
        }
        return res;
    }
    bool isPalindrome(string s)
    {
        int size = s.size();
        for (int i = 0; i <= (size - 1) / 2; ++i)
        {
            if (s[i] != s[size-1-i])
                return false;
        }
        return true;
    }
};

//	2.Direct DP, O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        //dp[i][j] = P[i+1][j-1] && (s[i]==s[j]), dp[i][j] = true means from s[i] to s[j] is palindrome
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        string res;
        if (!size) return res;
        //init
        for (int i = 0; i < size; ++i)
        {
            dp[i][i] = true;
            if (i == size - 1) break;
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        //dp
        for (int i = size-3; i >= 0; --i)
        {
            for (int j = i + 2; j < size; ++j)
            //    cout<<"dp["<<i<<"]["<<j<<"]"<<dp[i][j]<<endl;
                dp[i][j] = (dp[i+1][j-1] && s[i]==s[j]);
        }
        //get max, need to contain init case!
        int start = 0, len = 1;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (dp[i][j] && len < j-i+1)
                {
                    start = i;
                    len = j-i+1;
                }
            }
        }
        return s.substr(start,len);
    }
};

//	2.//dp[i][j] = P[i+1][j-1] && (s[i]==s[j]), dp[i][j] = true means from s[i] to s[j] is palindrome

### 二进制专题  
easy:  
1. www.lintcode.com/zh-cn/problem/count-1-in-binary  
2. www.lintcode.com/zh-cn/problem/add-binary  

//lintcode 365. Count 1 in Binary
//1. Integer is n bits with m 1 bits, time complexity O(m)
class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        while (num)
        {
            num &= (num-1);
            ++count;
        }
        return count;        
    }
};

//lintcode 408. Add Binary
//1. Notice that string low bit in the right! Time complexity O(max(m,n))
class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        // write your code here
        int alen = a.size(), blen = b.size();
        if (!alen) return b;
        if (!blen) return a;
        int size = max(alen,blen);
        string res(size,'0');
        int carry = 0;
        //string right are low bit!
        for (int i = 1; i <= alen || i <= blen; ++i)
        {
            int sum = 0;
            if (i > alen)
                sum = b[blen-i] - '0' + carry;
            else if (i > blen)
                sum = a[alen-i] - '0' + carry;
            else
                sum = a[alen-i] - '0' + b[blen-i] - '0' + carry;
            cout<<"i="<<i<<" "<<"sum="<<sum<<endl;
            res[size-i] = sum % 2 + '0';
            carry = sum / 2;
        }
        return carry == 1 ? '1'+res : res;
    }
};

# 题目摘要  
## 2019.6.24-2019.6.30  
###链表专题  
easy:
1. https://leetcode.com/problems/linked-list-cycle/
medium:
1. https://leetcode.com/problems/linked-list-cycle-ii/
2. https://leetcode.com/problems/rotate-list/

###二分查找
medium:
1. https://leetcode.com/problems/search-in-rotated-sorted-array/	
2. https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
3. https://leetcode.com/problems/search-a-2d-matrix/

###搜索专题
medium:
1. https://leetcode.com/problems/pacific-atlantic-water-flow/		Not understand!
2. https://leetcode.com/problems/decode-string/				Optimize code and time
hard:
1. https://leetcode.com/problems/24-game/				Redo
2. https://leetcode.com/problems/recover-binary-search-tree/

//141. Linked List Cycle
//	1. If cycle, absolute fast can chase slow because the worst case fast = 2*slow can meet at the end
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* fast, *slow;
        fast = slow = dummyHead;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

//142. Linked List Cycle II
//	1. My, use dummyHead
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* fast, *slow;
        fast = slow = dummyHead;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)//no cycle
            return NULL;
        slow = dummyHead;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

//	2. Others
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {                      // there is a cycle
                while(slow != entry) {               // found the entry location
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;                                 // there has no cycle
    }
};

//61. Rotate List
//	1. My solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
	//left part[1,size-k], right part[size-k+1,size]:  (size-k)th node -> NULL, (size-k+1)th node -> 1th node and return head node
	//compute list size, then k = k % size
        if (!head||!head->next) return head;
        ListNode* node = head, * tail = NULL;
        int size = 0;
        while (node)
        {
            ++size;
            if (!node->next)//find tail node
                tail = node;
            node = node->next;
        }
        k = k % size;
        int new_end = size-k;
        node = head;
        while (new_end - 1 > 0)
        {
            --new_end;
            node = node->next;
        }
        ListNode* newHead = node->next;
        if (!newHead)//right part are null
        {
            newHead = head;
        }
        else
        {
            node->next = NULL;
            tail->next = head;
        }        
        return newHead;
    }
};

//	2.Other Solution, logic is same but code more cleaner
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};

//33. Search in Rotated Sorted Array
//	1.My Solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int size = nums.size();
        return search(nums, 0, size-1, target);
    }
    //find target in nums[l...r]
    int search(vector<int>& nums, int l, int r, int target){
        if (l > r)  return -1;
        if (l == r)
        {
            if (target == nums[l])
                return l;
            return -1;
        }
        int mid = l + (r-l)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            if ( (nums[l] < nums[mid] && nums[l] <= target) || nums[l] > nums[mid])//consider two case!
                return search(nums, l, mid-1, target);
            return search(nums, mid+1, r, target);
        }
        else//nums[mid] < target
        {
            if ((nums[r] > nums[mid] && nums[r] >= target) || nums[r] < nums[mid])
                return search(nums, mid+1, r, target);
            return search(nums, l, mid-1, target);
        }
    }
};

//	2.Change, another thought!
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int size = nums.size();
        return search(nums, 0, size-1, target);
    }
    //find target in nums[l...r]
    int search(vector<int>& nums, int l, int r, int target){
        if (l > r)  return -1;
        if (l == r)
        {
            if (target == nums[l])
                return l;
            return -1;
        }
        int mid = l + (r-l)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > nums[r])
        {
            if (nums[mid] > target && nums[l] <= target)
                return search(nums, l, mid-1, target);
            return search(nums, mid+1, r, target);
        }
        else//nums[mid] < nums[r]
        {
            if (nums[mid] < target && nums[r] >= target)
                return search(nums, mid+1, r, target);
            return search(nums, l, mid-1, target);
        }
    }
};

//81. Search in Rotated Sorted Array II
//	1.Other solution, worst case O(n), average O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int size = nums.size();
        return search(nums, 0, size-1, target);
    }
    //find target in nums[l...r]
    int search(vector<int>& nums, int l, int r, int target){
        if (l > r)  return false;
        if (l == r)
        {
            if (target == nums[l])
                return true;
            return false;
        }
        int mid = l + (r-l)/2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] < nums[r])
        {
            if (nums[mid] < target && nums[r] >= target)
                return search(nums, mid+1, r, target);
            return search(nums, l, mid-1, target);
        }
        else if (nums[mid] > nums[r])
        {
            if (nums[mid] > target && nums[l] <= target)
                return search(nums, l, mid-1, target);
            return search(nums, mid+1, r, target);
        }
        else//nums[mid] == nums[r]
            return search(nums, l, r-1, target);
    }
};

//394. Decode String
//	1. My solution, need to optimize
class Solution {
public:
    string decodeString(string s) {
        //push char into stack, when meet ']' stack pop until '[' and repeated times 'number' before '['
        if (s.empty()) return s;
        stack<char> stk;
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            cout<<"s["<<i<<"]="<<s[i]<<endl;
            if (s[i] == ']')
            {
                string out;
                while (stk.top() != '[')
                {
                    out = stk.top() + out;
                    stk.pop();
                }
                stk.pop();//pop '['
                //k is guaranteed to be a positive integer.
                int k, count;
                k = count = 0;
                while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9')
                {
                    int digit = stk.top() - '0';
                    k += pow(10,count)*digit;
                    stk.pop();
                    count++;
                }
                cout<<"k="<<k<<endl;
                //repeated k times
                string in = out;
                for (int i = 1; i < k; ++i)
                    out += in;
                int size_out = out.size();
                cout<<"out="<<out<<endl;
                for (int i = 0; i < size_out; ++i)
                    stk.push(out[i]);
            }
            else
                stk.push(s[i]);            
        }
        string res;        
        size = stk.size();
        for (int i = 0; i < size; ++i)
        {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};

//679. 24 Game
//	1. C++
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr(nums.begin(), nums.end());
        
        return Recursion(arr);
        
    } 

    bool Recursion(vector<double>& nums) {
      if(nums.size() == 1) { 
         if(abs(nums[0] - 24) < 0.001) {
            return true;
         }
         return false;
      }
      for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
          double p = nums[i], q = nums[j];
          vector<double> ops{p + q, p - q, q - p, p * q};
          if(p > 0.001) ops.push_back(q / p);
          if(q > 0.001) ops.push_back(p / q);

          
          nums.erase(nums.begin() + j);
          nums.erase(nums.begin() + i);

          for(auto op : ops) {
            nums.push_back(op);
            if(Recursion(nums)) {
                return true;
            };
            nums.pop_back();
          }

          nums.insert(nums.begin() + i, p);
          nums.insert(nums.begin() + j, q);
        }
      }
        return false;
    }
};

//	2. Java
class Solution {
    public boolean judgePoint24(int[] nums) {
        ArrayList A = new ArrayList<Double>();
        for (int v: nums) A.add((double) v);
        return solve(A);
    }
    private boolean solve(ArrayList<Double> nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return Math.abs(nums.get(0) - 24) < 1e-6;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    ArrayList<Double> nums2 = new ArrayList<Double>();
                    for (int k = 0; k < nums.size(); k++) if (k != i && k != j) {
                        nums2.add(nums.get(k));
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && j > i) continue;
                        if (k == 0) nums2.add(nums.get(i) + nums.get(j));
                        if (k == 1) nums2.add(nums.get(i) * nums.get(j));
                        if (k == 2) nums2.add(nums.get(i) - nums.get(j));
                        if (k == 3) {
                            if (nums.get(j) != 0) {
                                nums2.add(nums.get(i) / nums.get(j));
                            } else {
                                continue;
                            }
                        }
                        if (solve(nums2)) return true;
                        nums2.remove(nums2.size() - 1);
                    }
                }
            }
        }
        return false;
    }
}
