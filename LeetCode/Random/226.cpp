#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
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

TreeNode* invertTree(TreeNode* root)
{
    if (root == nullptr) return root;
    queue <TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
        swap(current->left, current->right);
    }
    return root;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    // Create leaf nodes
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node9 = new TreeNode(9);

    // Create internal nodes and attach leaf nodes
    TreeNode* node2 = new TreeNode(2, node1, node3);
    TreeNode* node7 = new TreeNode(7, node6, node9);

    // Create the root node and attach internal nodes
    TreeNode* root = new TreeNode(4, node2, node7);


    invertTree(root);
    return 0;
    
}