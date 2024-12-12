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

class Node {
public:
    int val;
    vector <Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        vector <Node*> created(101, NULL);
        queue <Node*> q;
        q.push(node);
        node = created[node->val] = new Node(node->val);
        

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v: u->neighbors) {
                if (created[v->val]) created[u->val]->neighbors.push_back(created[v->val]);
                else {
                    created[v->val] = new Node(v->val);
                    created[u->val]->neighbors.push_back(created[v->val]);
                    q.push(v);
                }
            }

        }
        return created[1];
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node2};


    Solution *solution = new Solution();
    auto root = solution->cloneGraph(node1);
    cout << root->val << endl;


    

}