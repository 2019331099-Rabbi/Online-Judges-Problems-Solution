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

// class BSTIterator {
// public:
//     int pos, len;
//     vector <int> v;
//     BSTIterator(TreeNode* root) {
//         inTraversal(root);
//         pos = 0;
//         len = v.size();
//         for (auto xx: v) cout << xx << ' ';
//         cout << endl;
//     }

//     void inTraversal(TreeNode *node) {
//         if (node == nullptr) return;
//         inTraversal(node->left);
//         v.push_back(node->val);
//         inTraversal(node->right);
//     }
    
//     int next() {
//         return v[pos++];
//     }
    
//     bool hasNext() {
//         return pos < len;
//     }
// };

class BSTIterator {
public:
    stack <TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        inTraversal(root);
    }

    void inTraversal(TreeNode *node) {
        if (node == nullptr) return;
        stk.push(node);
        inTraversal(node->left);
    }
    
    int next() {
        TreeNode *node = stk.top();
        stk.pop();
        inTraversal(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return stk.size();
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    TreeNode* root = new TreeNode(7);

    // Left subtree of the root
    root->left = new TreeNode(3);      // Left child of root is 3
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(5);
    

    // Right subtree of the root
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *bSTIterator = new BSTIterator(root);

    
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;



}