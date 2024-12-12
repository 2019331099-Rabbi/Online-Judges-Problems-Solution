#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void eventualSafeNodes(vector<vector<int>>& graph)
{   
    int nodes = graph.size();

    vector <vector <int>> rgraph(nodes);
    vector <int> indeg(nodes);

    for (int i = 0; i < nodes; i++) {
        for (auto xx: graph[i]) {
            indeg[i]++;
            rgraph[xx].push_back(i);
        }
    }

    queue <int> q;
    for (int i = 0; i < nodes; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector <int> ans;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto xx: rgraph[u]) {
            indeg[xx]--;
            if (indeg[xx] == 0) q.push(xx);
        }
    }

    sort(ans.begin(), ans.end());
    for (auto xx: ans) cout << xx << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    // vector <vector <int>> adj = {
    //     {1, 2},
    //     {2, 3},
    //     {5},
    //     {0},
    //     {5},
    //     {},
    //     {}
    // };
    vector <vector <int>> adj = {
        {1,2,3,4},
        {1,2},
        {3,4},
        {0,4},
        {}
    };
    

    eventualSafeNodes(adj);
    return 0;
}