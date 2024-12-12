#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz], cost[sz];
int nodes;
bool vis[sz];

void solve()
{
    cin >> nodes;
    for (int i = 1; i < nodes; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    T = 1;
    while (T--) solve();
    return 0;
}