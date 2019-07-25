7.15~7.21
1.     反转单链表
https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 
2.     链表环的入口
https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 
3.     二叉树的镜像
https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 
4.     Z字打印二叉树
https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 
5.     矩形覆盖
https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 
6.     换钱的方法数
给定一个数组arr，里面的元素都是正数且不重复。每个值代表一种面值的货币，每种货币可以使用任意张，给定一个正数target,代表要找的钱数，求换钱的方法数。
比如：arr={5,10,25,1},target=0,结果为0；
 Arr={5,10,25,1},target=15,结果是6
@黄环-研二-信息与通信工程 @李宗凯 

1.
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead->next)    return pHead;
        ListNode *cur = pHead, *pre = NULL, *next = NULL;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

2.
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if (!pHead || !pHead->next)	return NULL;
		ListNode dummy(-1);
		dummy.next = pHead;
		ListNode* slow = &dummy, * fast = &dummy;
		while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
		if (!fast->next || !fast->next->next)
            return NULL;
        ListNode* entry = &dummy;
        while (entry != slow)
        {
            entry = entry->next;
            slow = slow->next;
        }
        return entry;
    }
};

3.
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot) return;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

4.
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        //每一行从左到右或从右向左输出
        vector<vector<int> > res;
        if (!pRoot) return res;
        bool l2r = true;
        vector<vector<TreeNode> > resTree;
        vector<TreeNode*> row;
        row.push_back(pRoot);
        while (!row.empty())
        {
            vector<int> row_int;
            vector<TreeNode*> next_row;
            for (auto node: row)
            {
                row_int.push_back(node->val);
                if (node->left)
                    next_row.push_back(node->left);
                if (node->right)
                    next_row.push_back(node->right);
            }
            row = next_row;
            if (!l2r)
                reverse(row_int.begin(),row_int.end());
            res.push_back(row_int);
            l2r = !l2r;
        }
        return res;
    }
};

5.开始没想明白，就是一个斐波那契数列
class Solution {
public:
    int rectCover(int number) {
        if (number < 0)
            return 0;
        vector<int> dp(number+1, 0);//dp[i],i=0,1...,number, means all cover solutions number
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= number; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[number];
    }
};

7.22-7.28
1.数值的整数次方 https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
2.数据流中的中位数 https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
3.用非递归写法实现二叉树的中序遍历 https://leetcode.com/problems/binary-tree-inorder-traversal/
4.课程表（拓扑排序） https://leetcode.com/problems/course-schedule/description/
5.快速排序 https://leetcode.com/problems/sort-colors/
6.https://leetcode.com/problems/subsets-ii/

1.
1.1 O(n)解法
class Solution {
public:
    double Power(double base, int exponent) {
        bool non_negative = true;
        if (exponent < 0)
        {
            exponent = -exponent;
            non_negative = false;
        }
        double res = 1.0;
        for (int i = 1; i <= exponent; ++i)
            res *= base;
        if (!non_negative)
            res = 1.0/res;
        return res;
    }
};

1.2 C++ API
class Solution {
public:
    double Power(double base, int exponent) {
        return pow(base,exponent);
    }
};

1.3 二分法
class Solution {
public:
    double Power(double base, int exponent) {
        bool non_negative = true;
        if (exponent < 0)
        {
            exponent = -exponent;
            non_negative = false;
        }
        double res = MyPow(base, exponent);
        if (!non_negative)
            res = 1.0/res;
        return res;
    }
private:
    double MyPow(double base, int exponent)
    {
        if (!exponent)
            return 1.0;
        if (exponent == 1)
            return base;
        double res = MyPow(base, exponent/2) * MyPow(base, exponent/2);
        if (exponent % 2)
            res *= base;
        return res;
    }
};

2. 有点意思，可深入！
class Solution {
public:
    void Insert(int num)
    {
        if (p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);

        if (p.size() == q.size() + 2)//总数据个数为偶数时，保持左右数组大小相等
        {
            q.push(p.top());
            p.pop();
        }
        if (q.size() == p.size() + 1)//总数据个数为奇数时，保持左侧数组比右侧数组多一个元素
        {
            p.push(q.top());
            q.pop();
        }
        return;
    }

    double GetMedian()
    {
        return p.size() == q.size() ? (p.top()+q.top())/2.0 : p.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> p;//大根堆，排序后数组左半侧，包含奇数时的中间元素
    priority_queue<int, vector<int>, greater<int>> q;//大根堆，排序后数组右半侧，不包含奇数时的中间元素
};

4.
4.1 DFS
class Solution {
public:
    typedef vector<vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false), finished(numCourses, false);
        for (int i = 0; i < numCourses; ++i)
        {
            if (!finished[i] && hasCycle(g, visited, finished, i))
                return false;
        }
        return true;
    }
private:
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        graph g(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);//[u,v] v is prerequisite of u, push into g[v]
        }
        return g;
    }
    bool hasCycle(graph &g, vector<bool>& visited, vector<bool>& finished, int node)
    {
        if (visited[node])
            return true;
        if (finished[node])
            return false;
        visited[node] = finished[node] = true;
        for (auto after: g[node])
        {
            if (hasCycle(g, visited, finished, after))
                return true;
        }
        visited[node] = false;
        return false;
    }
};

4.2 BFS 有点意思，找到一个入度为0的就将其删除表示可以完成该课程及后续课程
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};

5. 三路快排
5.1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //left means left part contains 0, [0,left)
        //right means right part that contains 2, (right,size-1]
        int size = nums.size();
        int left = 0, right = size-1, index = 0;
        while (index <= right)
        {
            if (nums[index] < 1)
                swap(nums[left++], nums[index++]);
            else if (nums[index] > 1)
                swap(nums[right--], nums[index]);
            else//nums[index] == 1
                ++index;
        }
        return;
    }
};

5.2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //[0,zero]存0,[zero+1,i-1]存1，i为待访问的元素，[two,n-1]存2
        int zero = -1, i = 0;
        int two = nums.size();
        for(int i = 0; i < two; )
        while (i < two)
        {
            if(nums[i] == 1)
                i++;
            else if (nums[i] == 0)
                swap(nums[++zero],nums[i++]);
            else
                swap(nums[--two],nums[i]);
        }
    }
};
