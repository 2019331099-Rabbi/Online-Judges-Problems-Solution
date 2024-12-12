#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

auto init = []() -> int {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;

        bool flag1 = isSameTree(p->left, q->left);
        bool flag2 = isSameTree(p->right, q->right);
        return flag1 && flag2;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;

    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(2);
    TreeNode *node6 = new TreeNode(3);
    
    node4->left = node6;
    node4->right = node5;

    cout << soln->isSameTree(node1, node4) << endl;
}