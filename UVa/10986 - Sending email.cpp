#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 20000
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int nodes, edges, strt, dst, k=1, cost[sz];
vector <int> adj[sz], wt[sz];

void init()
{
    int i;
    for (i=0; i<nodes; i++) adj[i].clear(), wt[i].clear(), cost[i]=inf;
    cost[strt]=0;
}

void dijkstra()
{
    int u, v, w, i;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push({0, strt});
    while (!pq.empty()) {
        u=pq.top().second;
        pq.pop();
        for (i=0; i<adj[u].size(); i++) {
            v=adj[u][i];
            w=cost[u]+wt[u][i];
            if (cost[v]<=w) continue;
            cost[v]=w;
            pq.push({w, v});
        }
    }
    cout << "Case #" << k++ << ": ";
    if (cost[dst]==inf) cout << "unreachable" << endl;
    else cout << cost[dst] << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, u, v, w;
    cin >> T;
    while (T--) {
        cin >> nodes >> edges >> strt >> dst;
        init();
        while (edges--) {
            cin >> u >> v >> w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            wt[u].push_back(w);
            wt[v].push_back(w);
        }
        dijkstra();
    }
    return 0;
}
