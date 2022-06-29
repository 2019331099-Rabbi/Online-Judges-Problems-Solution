#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int nodes, edges, u, v, w, dis[sz];
vector <int> adj[sz], cost[sz];

void init()
{
    for (int i=0; i<sz; i++) dis[i]=inf, adj[i].clear(), cost[i].clear();
}

bool bellmanford()
{
    int i, j, k, alt;
    dis[0]=0;
    for (k=1; k<nodes; k++) {
        for (i=0; i<nodes; i++) {
            for (j=0; j<adj[i].size(); j++) {
                alt=dis[i]+cost[i][j];
                if (alt>=dis[adj[i][j]]) continue;
                dis[adj[i][j]]=alt;
            }
        }
    }
    for (i=0; i<nodes; i++) {
        for (j=0; j<adj[i].size(); j++) {
            alt=dis[i]+cost[i][j];
            if (alt>=dis[adj[i][j]]) continue;
            return true;
        }
    }
    return false;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        cin >> nodes >> edges;
        init();
        while (edges--) {
            cin >> u >> v >> w;
            adj[u].push_back(v);
            cost[u].push_back(w);
        }
        cout << ((bellmanford())?"possible":"not possible") << endl;
    }
    return 0;
}
