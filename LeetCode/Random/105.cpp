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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int, int> preorderPos, inorderPos;
        int len = preorder.size();

        for (int i = 0; i < len; i++) inorderPos[inorder[i]] = i;

        function<TreeNode*(int, int, int)> test = [&](int rootIndex, int left, int right) -> TreeNode* {
            if (left > right) return nullptr;

            TreeNode *newNode = new TreeNode(preorder[rootIndex]);
            int mid = inorderPos[preorder[rootIndex]];
            newNode->left = test(rootIndex + 1, left, mid - 1);
            newNode->right = test(rootIndex + (mid - left) + 1, mid + 1, right);
            return newNode;
        };
        return test(0, 0, preorder.size() - 1);
    }

    void postOrder(TreeNode *root) {
        if (root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << ',';
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> preorder = {8, 2, 7, 1, 9, 3, 6}, inorder = {7, 2, 1, 8, 3, 9, 6};

    TreeNode *root = soln->buildTree(preorder, inorder);
    soln->postOrder(root);
    cout << endl;

}