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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node *parent = root, *childHead = nullptr, *child = nullptr;
        
        while (parent) {
            child = childHead = nullptr;

            while (parent) {
                if (child) {
                    if (parent->left) {
                        child->next = parent->left;
                        child = child->next;
                    }
                    if (parent->right) {
                        child->next = parent->right;
                        child = child->next;
                    }
                }
                else {
                    if (parent->left) {
                        child = parent->left;
                        if (!childHead) childHead = parent->left;
                        if (parent->right) {
                            child->next = parent->right;
                            child = child->next;
                        }
                    }
                    else if (parent->right) {
                        child = parent->right;
                        if (!childHead) childHead = parent->right;
                    }
                }
                parent = parent->next;
            }
            parent = childHead;
        }

        queue <Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            cout << node->val << " -> ";
            if (node->next) cout << node->next->val;
            cout << endl;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    Node* root = new Node(0);  // Root node with value 0

    // Left subtree of root
    root->left = new Node(2);       // Left child of root is 2
    root->left->left = new Node(1); // Left child of 2 is 1
    root->left->left->left = new Node(5);  // Left child of 1 is 5
    root->left->left->right = new Node(1); // Right child of 1 is 1

    // Right subtree of root
    root->right = new Node(4);      // Right child of root is 4
    root->right->left = new Node(3);  // Left child of 4 is 3
    root->right->left->right = new Node(6);  // Right child of 3 is 6
    root->right->right = new Node(-1); // Right child of 4 is -1
    root->right->right->right = new Node(8); // Right child of -1 is 8

    Solution *soln = new Solution();

    soln->connect(root);


}