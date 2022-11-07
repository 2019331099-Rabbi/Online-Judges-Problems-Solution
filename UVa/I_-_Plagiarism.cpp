#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz  10010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz];
bool vis[sz];

void init(int nodes)
{
    for (int i = 1; i <= nodes; i++) vis[i] = false, adj[i].clear();
}

int bfs(int strt)
{
    vis[strt] = true;
    queue <int> q;
    q.push(strt);

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto xx: adj[u]) {
            if (vis[xx]) continue;
            q.push(xx);
            vis[xx] = true;
        }
    }
    return cnt;
}

void solve()
{
    int nodes, edges, k;
    cin >> nodes >> edges >> k;

    while (edges--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    while (k--) {
        int strt;
        cin >> strt;
        if (!vis[strt]) ans += bfs(strt);
    }
    cout << ans << endl;
    init(nodes);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}