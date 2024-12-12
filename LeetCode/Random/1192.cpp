#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <vector <int>> bridges;

void init(int nodes, vector <int> &dt, vector <int> &low, vector <int> &parent)
{
    for (int i = 0; i < nodes; i++) dt[i] = low[i] = parent[i] = -1;
}

void dfs(int strt, vector <int> &dt, vector <int> &low, vector <int> &parent, int timer, vector <vector <int>> &adj)
{
    dt[strt] = low[strt] = ++timer;
    for (auto xx: adj[strt]) {
        if (dt[xx] == -1) {
            parent[xx] = strt;
            dfs(xx, dt, low, parent, timer, adj);
            low[strt] = min(low[strt], low[xx]);
            if (low[xx] > dt[strt]) bridges.push_back({strt, xx});
        }
        else if (xx != parent[strt]) low[strt] = min(low[strt], dt[xx]);
    }
}

vector <vector <int>> criticalConnections(int n, vector<vector<int>>& connections)
{
    vector <vector <int>> adj(n);
    vector <int> dt(n), low(n), parent(n);
    int timer = 0;
    
    for (auto xx: connections) {
        int u = xx[0], v = xx[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    init(n, dt, low, parent);

    for (int i = 0; i < n; i++) {
        if (dt[i] == -1) dfs(i, dt, low, parent, timer, adj);
    }
    return bridges;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int nodes, edges;
    cin >> nodes >> edges;

    vector <vector <int>> connections(edges, vector <int>(2));

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> connections[i][0] >> connections[i][1];
    }
    criticalConnections(nodes, connections);

    for (auto xx: bridges) cout << xx[0] << ' ' << xx[1] << endl;

    return 0;

}

// 118.179.223.10
// 202.4.96.6