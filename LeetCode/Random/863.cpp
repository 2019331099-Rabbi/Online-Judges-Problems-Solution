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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector <int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    vector <vector <int>> adj(501);
    queue<TreeNode*> q;
    int mx = -1;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        mx = max(mx, current->val);
        q.pop();

        if (current->left) {
            adj[current->val].push_back(current->left->val);
            adj[current->left->val].push_back(current->val);
            q.push(current->left);
        }
        if (current->right) {
            adj[current->val].push_back(current->right->val);
            adj[current->right->val].push_back(current->val);
            q.push(current->right);
        }
    }

    vector <int> result;
    queue <pair <int, int>> pq;
    vector <bool> vis(mx + 1, false);

    pq.push({target->val, 0});
    vis[target->val] = true;

    while (!pq.empty()) {
        int curr = pq.front().first;
        int dis = pq.front().second;
        pq.pop();
        if (dis == k) {
            result.push_back(curr);
            continue;
        }
        for (auto xx: adj[curr]) {
            if (vis[xx]) continue;
            pq.push({xx, dis + 1});
            vis[xx] = true;
        }
    }
    return result;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    TreeNode* node0 = new TreeNode(0);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);

    // Manually link nodes to form the tree
    node3->left = node5;
    node3->right = node1;
    node5->left = node6;
    node5->right = node2;
    node1->left = node0;
    node1->right = node8;
    node2->left = node7;
    node2->right = node4;

    auto result = distanceK(node3, node5, 2);
    for (auto xx: result) cout << xx << ' ';
    cout << endl;

    // // Optional: print the tree in level order for verification
    // std::queue<TreeNode*> q;
    // q.push(node3);  // Root node is node3
    // while (!q.empty()) {
    //     TreeNode* current = q.front();
    //     q.pop();
    //     if (current) {
    //         std::cout << current->val << " ";
    //         q.push(current->left);
    //         q.push(current->right);
    //     } else {
    //         std::cout << "null ";
    //     }
    // }

    // // Cleanup: Deleting allocated nodes to avoid memory leak
    // delete node0;
    // delete node1;
    // delete node2;
    // delete node3;
    // delete node4;
    // delete node5;
    // delete node6;
    // delete node7;
    // delete node8;

    return 0;

    
}