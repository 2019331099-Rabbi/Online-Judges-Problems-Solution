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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> zigzagV;
        stack <TreeNode*> stk1, stk2;
        if (root) stk1.push(root);

        bool level = true;

        while (stk1.size() || stk2.size()) {
            zigzagV.push_back({});
            int i = zigzagV.size() - 1;
            if (level) {
                while (!stk1.empty()) {
                    TreeNode *node = stk1.top();
                    zigzagV[i].push_back(node->val);
                    stk1.pop();
                    if (node->left) stk2.push(node->left);
                    if (node->right) stk2.push(node->right);
                }
            }
            else {
                while (!stk2.empty()) {
                    TreeNode *node = stk2.top();
                    zigzagV[i].push_back(node->val);
                    stk2.pop();
                    if (node->right) stk1.push(node->right);
                    if (node->left) stk1.push(node->left);
                }
            }
            level = !level;
        }
        return zigzagV;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    TreeNode* root = new TreeNode(3);  // Root node with value 3

    // Left subtree of root
    root->left = new TreeNode(9);      // Left child of root is 9

    // Right subtree of root
    root->right = new TreeNode(20);    // Right child of root is 20
    root->right->left = new TreeNode(15);  // Left child of 20 is 15
    root->right->right = new TreeNode(7);  // Right child of 20 is 7

    Solution *soln = new Solution();

    vector <vector <int>> v = soln->zigzagLevelOrder(root);
    for (int i = 0; i < v.size(); i++) {
        for (auto xx: v[i]) cout << xx << ' ';
        cout << endl;
    }
}