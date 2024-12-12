#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int nodes;
vector <int> adj[sz];
bool vis[sz];

bool dfs(int strt)
{
    vis[strt]=true;
    for (auto xx: adj[strt]) {
        // if (vis[xx]) continue;
        if (dfs(xx) == 0) return true;
    }
    return false;
}

void solve(int T)
{
    int edges, strt;

    cin >> nodes >> edges >> strt;

    while (edges--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if(dfs(strt)) cout <<"Case " << T << ": " << "Yes" << endl;
    else cout <<"Case " << T << ": " << "No" << endl;

    for (int i = 1; i <= nodes; i++) {
        vis[i] = false;
        adj[i].clear();
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