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
    TreeNode *divideANDconquer(int left, int right, vector <int> &nums) {
        if (left > right) return nullptr;
        
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = divideANDconquer(left, mid - 1, nums);
        root->right = divideANDconquer(mid + 1, right, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = divideANDconquer(0, nums.size() - 1, nums);
        return root;
    }

    void treeTraversal(TreeNode *root) {
        queue <TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << ' ';
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {-10,-3,0,5,9};
    TreeNode *root = soln->sortedArrayToBST(nums);
    return 0;
}