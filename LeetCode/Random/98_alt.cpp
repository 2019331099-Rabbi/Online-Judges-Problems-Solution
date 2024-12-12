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
    TreeNode *prev = nullptr;
    bool isValid(TreeNode *root) {
        if (root == nullptr) return true;

        bool left = isValid(root->left);
        if (prev && prev->val >= root->val) return false;
        prev = root;
        bool right = isValid(root->right);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root);
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(6);
    cout << soln->isValidBST(root) << endl;

    return 0;
}