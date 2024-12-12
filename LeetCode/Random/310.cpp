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

class Solution {
public:
    vector <int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector <vector <int>> adj(n);
        for (auto xx: edges) {
            adj[xx[0]].push_back(xx[1]);
            adj[xx[1]].push_back(xx[0]);
        }
        vector <int> indeg(n);
        queue <int> q;
        for (int i = 0; i < n; i++) {
            indeg[i] = adj[i].size();
            if (indeg[i] == 1) q.push(i);
        }

        while (n > 2) {
            int len = q.size();
            while (len--) {
                int u = q.front();
                q.pop();
                n--;
                for (auto xx: adj[u]) {
                    indeg[xx]--;
                    if (indeg[xx] == 1) q.push(xx);
                }
            }
        }
        vector <int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <vector <int>> edges = {
        {0,1},
        {0,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {0,7},
        {7,8},
        {7,9},
        {8,10},
        {9,11},
        {10,12},
        {11,13}
    };

    // vector <vector <int>> edges = {
    //     {1, 0},
    //     {1, 2},
    //     {1, 3}
    // };

    int nodes = edges.size() + 1;
    
    auto result = soln->findMinHeightTrees(nodes, edges);

    for (auto xx: result) cout << xx << ' ';
    cout << endl;

    return 0;

}

/*
9
0

*/