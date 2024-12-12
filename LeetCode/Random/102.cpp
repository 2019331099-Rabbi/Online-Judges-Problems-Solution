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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> levelNodes;
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector <int> level;
            while (len--) {
                TreeNode *u = q.front();
                q.pop();
                if (u) {
                    level.push_back(u->val);
                    q.push(u->left);
                    q.push(u->right);
                }
            }
            levelNodes.push_back(level);
        }
        return levelNodes;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    TreeNode *node15 = new TreeNode(15);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node20 = new TreeNode(20, node15, node7);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *root = new TreeNode(3, node9, node20);

    Solution *soln = new Solution();
    auto levelNodes = soln->levelOrder(root);

    cout << levelNodes.size() << endl;

    for (int i = 0; i < levelNodes.size(); i++) {
        for (auto xx: levelNodes[i]) cout << xx << ' ';
        cout << endl;
    }

    return 0;
}