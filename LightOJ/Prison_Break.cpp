#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz], cost[sz];
int price[sz], cap, minCost[sz][sz], vis[sz];

void init()
{
    for (int i = 0; i < sz; i++) adj[i].clear(), cost[i].clear();
}

int dijkstra(int strt, int dst)
{
    priority_queue <pair <pair <int, int>, int>, vector <pair <pair <int, int>, int>>, greater <pair <pair <int, int>, int>>> pq;
    memset(minCost, 0x7f, sizeof(minCost));

    pq.push({{0, 0}, strt});
    minCost[strt][0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int curgas = pq.top().first.second;
        int c = pq.top().first.first;
        pq.pop();
        if (c > minCost[u][curgas]) continue;
        if(u == dst) return minCost[u][curgas];

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int w = cost[u][i];

            if (w > cap) continue;
            if (curgas >= w && minCost[v][curgas - w] > minCost[u][curgas]) {
                minCost[v][curgas - w] = minCost[u][curgas];
                pq.push({{minCost[v][curgas - w], curgas - w}, v});
            }
        }
        if(curgas < cap){
            minCost[u][curgas + 1] = minCost[u][curgas] + price[u];
            pq.push({{minCost[u][curgas + 1], curgas + 1}, u});
        }
    }
    return inf;
}

void solve(int T)
{
    int nodes, edges;

    cin >> nodes >> edges;
    for (int i = 0; i < nodes; i++) cin >> price[i];
    while (edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v), adj[v].push_back(u);
        cost[u].push_back(w), cost[v].push_back(w);
    }
    cout << "Case " << T << ':' << endl;
    int q;
    cin >> q;
    while (q--) {
        int strt, dst;
        cin >> cap >> strt >> dst;
        int ans = dijkstra(strt, dst);
        if (ans == inf) cout << "impossible" << endl;
        else cout << ans << endl;
    }
    init();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}