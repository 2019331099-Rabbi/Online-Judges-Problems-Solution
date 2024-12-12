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

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    int isLeaf(int xi, int yi, int sq, Node *node, vector<vector<int>>& grid) {
        int cnt1 = 0;
        for (int i = xi; i < xi+sq; i++) {
            for (int j = yi; j < yi+sq; j++) cnt1 += grid[i][j];
        }
        if (cnt1 == sq*sq || cnt1 == 0) {
            if (cnt1 == 0) node->val = 0;
            else node->val = 1;
            return 1;
        }
        node->val = 0;
        return 0;
    }

    Node* quadTree(int xi, int yi, int sq, vector<vector<int>>& grid) {
        if (sq == 0) return nullptr;

        Node *node = new Node();
        node->isLeaf = isLeaf(xi, yi, sq, node, grid);
        if (node->isLeaf) return node;
        node->topLeft = quadTree(xi, yi, sq/2, grid);
        node->topRight = quadTree(xi, yi+sq/2, sq/2, grid);
        node->bottomLeft = quadTree(xi+sq/2, yi, sq/2, grid);
        node->bottomRight = quadTree(xi+sq/2, yi+sq/2, sq/2, grid);
        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        Node *root = quadTree(0, 0, grid.size(), grid);
        return root;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0}
    };
    Node *root = soln->construct(grid);
    soln->labelOrderTraversal(root);

    return 0;
}