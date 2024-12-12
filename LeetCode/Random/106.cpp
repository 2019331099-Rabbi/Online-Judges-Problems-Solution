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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map <int, int> inorderPos;
        int len = postorder.size();

        for (int i = 0; i < len; i++) inorderPos[inorder[i]] = i;

        function<TreeNode*(int, int, int)> test = [&](int rootIndex, int left, int right) -> TreeNode* {
            if (left > right) return nullptr;

            TreeNode *newNode = new TreeNode(postorder[rootIndex]);
            int mid = inorderPos[postorder[rootIndex]];
            newNode->left = test(rootIndex - ((right - mid) + 1), left, mid - 1);
            newNode->right = test(rootIndex - 1, mid + 1, right);
            return newNode;
        };
        return test(len - 1, 0, len - 1);
    }

    void preOrder(TreeNode *root) {
        if (root == nullptr) return;
        cout << root->val << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> postOrder = {7, 1, 2, 3, 6, 9, 8}, inorder = {7, 2, 1, 8, 3, 9, 6};

    auto root = soln->buildTree(inorder, postOrder);
    cout << root->val << endl;


    soln->preOrder(root);
    cout << endl;
}