#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


int minReorder(int n, vector<vector<int>>& connections)
{
    vector <vector <int>> adj(n);

    for (int i = 0; i < n-1; i++) {
        int u = connections[i][0], v = connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector <int> dis(n, 0);
    queue <int> q;

    q.push(0);
    dis[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (dis[v]) continue;
            q.push(v);
            dis[v] = dis[u] + 1;
        }
    }

    int cnt = 0;
    for (auto xx: connections) {
        int u = xx[0], v = xx[1];
        if (dis[v] > dis[u]) cnt++;
    }
    return cnt;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int nodes;
    cin >> nodes;
    vector<vector<int>> connections(nodes - 1);

    for (int i = 0; i < nodes - 1; i++) {
        int u, v;
        cin >> u >> v;
        connections[i].push_back(u);
        connections[i].push_back(v);
    }
    auto ans = minReorder(nodes, connections);
    cout << ans << endl;
    
}

// 118.179.223.10
// 202.4.96.6