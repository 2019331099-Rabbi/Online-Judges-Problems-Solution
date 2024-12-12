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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> avgs;
        queue <TreeNode*> q;

        if (root) q.push(root);

        while (!q.empty()) {
            int len = q.size();
            int64_t sum = 0;
            for (int i = 0; i < len; i++) {
                TreeNode *node = q.front();
                sum += node->val;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            avgs.push_back((double)sum / (double)len);
        }
        return avgs;
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

    auto v = soln->averageOfLevels(root);
    for (auto xx: v) cout << xx << ' ';
    cout << endl;
}