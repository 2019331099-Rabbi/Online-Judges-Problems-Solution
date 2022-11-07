#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 500
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/country-roads
*/

vector <int> adj[sz], cost[sz];
int minCost[sz];

void init()
{
    for (int i = 0; i < sz; i++) adj[i].clear(), cost[i].clear(), minCost[i] = inf;
}

void dijkstra(int strt)
{
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push({0, strt});
    minCost[strt] = 0;

    while (!pq.empty()) {
        int c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (c > minCost[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int alt = max(c, cost[u][i]);
            if (alt >= minCost[v]) continue;
            pq.push({alt, v});
            minCost[v] = alt;
        }
    }
}

void solve(int i)
{
    init();
    int nodes, edges;

    cin >> nodes >> edges;
    while (edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v), adj[v].push_back(u);
        cost[u].push_back(w), cost[v].push_back(w);
    }
    int strt;
    cin >> strt;
    dijkstra(strt);

    cout << "Case " << i << ":\n";

    for (int i = 0; i < nodes; i++) {
        if (minCost[i] == inf) cout << "Impossible" << endl;
        else cout << minCost[i] << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}