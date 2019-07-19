7.15~7.22
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
