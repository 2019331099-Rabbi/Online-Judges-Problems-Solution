#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t nodes;
vector <int64_t> adj[sz], cost[sz];
bool vis[sz];
int64_t dis[sz];

void bfs(int64_t strt)
{
    int64_t u, v;
    queue <int64_t> q;

    q.push(strt);
    dis[strt] = 0;
    vis[strt] = true;

    while (!q.empty()) {
        u=q.front();
        q.pop();
        for (int64_t i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];
            if (vis[v]) continue;
            q.push(v);
            dis[v] = dis[u] + cost[u][i];
            vis[v] = true;
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t edges, u, v, c;

    cin >> nodes;
    for (int64_t i = 1; i < nodes; i++) {
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    int64_t q, strt;
    cin >> q >> strt;
    bfs(strt);
    while (q--) {
        cin >> u >> v;
        cout << dis[u] + dis[v] << endl;
    }

    return 0;
}