#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1e9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int64_t row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int64_t col[] = {1, -1, 0, 0, -1, 1, 1, -1};

struct TreeNode {
    int64_t val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int64_t x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int64_t x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print64_tLevelOrder(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// bool isValidBST(TreeNode* root)
// {
//     queue <pair <TreeNode*, pair <int64_t, int64_t>>> q;
//     q.push({root, {INT64_MIN, INT64_MAX}});

//     while (!q.empty()) {
//         TreeNode *curr = q.front().first;
//         int64_t leftLim = q.front().second.first;
//         int64_t rightLim = q.front().second.second;
//         q.pop();

//         if (curr->left) {
//             if ((leftLim < curr->left->val) && (curr->left->val < curr->val)) q.push({curr->left, {leftLim, curr->val}});
//             else return false;
//         }
//         if (curr->right) {
//             if ((curr->val < curr->right->val) && (curr->right->val < rightLim)) q.push({curr->right, {curr->val, rightLim}});
//             else return false;
//         }
//     }
//     return true;
// }

bool valid(TreeNode *node, int64_t left, int64_t right)
{
    if (node == NULL) return true;
    if (!(node->val > left && node->val < right)) return false;
    return valid(node->left, left, node->val) && valid(node->right, node->val, right);
}

bool isValidBST(TreeNode* root)
{
    return valid(root, INT64_MIN, INT64_MAX);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // Manually constructing the BST based on the given structure
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4, node3, node6);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* root = new TreeNode(5, node1, node4);

    cout << isValidBST(root) << endl;

    // Clean up memory (important to avoid memory leaks)
    delete node3;
    delete node6;
    delete node4;
    delete node1;
    delete root;

    return 0;
}