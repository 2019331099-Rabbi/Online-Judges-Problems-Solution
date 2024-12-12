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
    int ans;
    int solve(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftVal = solve(root->left);
        int rightVal = solve(root->right);

        int case1 = max(max(leftVal, rightVal) + root->val, root->val);
        int case2 = max(case1, leftVal + rightVal + root->val);
        ans = max(case2, ans);
        return case1;
    }

    int maxPathSum(TreeNode* root) {
        ans = INT32_MIN;
        solve(root);
        return ans;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    TreeNode* root = new TreeNode(2);

    root->left = new TreeNode(-1);
    

    // // Right subtree of the root
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    Solution *soln = new Solution();
    cout << soln->maxPathSum(root) << endl;





}