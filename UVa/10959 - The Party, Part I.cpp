#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board


void bfs(vector <int> adj[], int nodes)
{
    int i, x, tmp, lev[nodes];
    bool vis[nodes]={false};
    queue <int> q;
    q.push(0);
    vis[0]=true, lev[0]=0;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (vis[tmp]) continue;
            q.push(tmp);
            lev[tmp]=lev[x]+1;
            vis[tmp]=true;
        }
    }
    for (i=1; i<nodes; i++) {
        if (vis[i]) cout << lev[i] << endl;
        else cout << -1 << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, nodes, edges, u, v, i;
    bool flag=false;
    cin >> T;
    while (T--) {
        if (flag) cout << endl;
        flag=true;
        cin >> nodes >> edges;
        vector <int> adj[nodes];
        for (i=0; i<edges; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(adj, nodes);
    }
    return 0;
}
