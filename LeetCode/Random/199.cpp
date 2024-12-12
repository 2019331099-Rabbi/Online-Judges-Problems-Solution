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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        vector <int> rightNodes;
        queue <TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int len = q.size();
            rightNodes.push_back(q.back()->val);
            while (len--) {
                TreeNode *u = q.front();
                q.pop();
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }
        }
        return rightNodes;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(3, nullptr, node4);
    TreeNode* node2 = new TreeNode(2, nullptr, node5);
    TreeNode* root = new TreeNode(1, node2, node3);

    auto rightNodes = soln->rightSideView(root);
    for (auto xx: rightNodes) cout << xx << ' ';
    cout << endl;
}