#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int nodes, edges, b, p, cost[sz];
vector <int> adj[sz], wt[sz], bank, police, ans;

void init()
{
    int i;
    for (i=0; i<nodes; i++)
        adj[i].clear(), wt[i].clear(), cost[i]=inf;
    bank.clear(), police.clear(), ans.clear();
}

void dijkstra()
{
    int i, x, tmp, tval, mx=0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    for (i=0; i<p; i++) pq.push({0, police[i]}), cost[police[i]]=0;
    while (!pq.empty()) {
        x=pq.top().second;
        pq.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            tval=cost[x]+wt[x][i];
            if (cost[tmp]<=tval) continue;
            pq.push({tval, tmp});
            cost[tmp]=tval;
        }
    }
    sort(bank.begin(), bank.end());
    for (i=0; i<b; i++) mx=max(mx, cost[bank[i]]);
    for (i=0; i<b; i++)
        if (cost[bank[i]]==mx) ans.push_back(bank[i]);
    cout << ans.size() << ' ';
    if (mx==inf) cout << '*' << endl;
    else cout << mx << endl;
    cout << ans[0];
    x=ans.size();
    for (i=1; i<x; i++) cout << ' ' << ans[i];
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int u, v, w, i;
    while (cin >> nodes >> edges >> b >> p) {
        init();
        while (edges--) {
            cin >> u >> v >> w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            wt[u].push_back(w);
            wt[v].push_back(w);
        }
        for (i=0; i<b; i++) {
            cin >> u;
            bank.push_back(u);
        }
        for (i=0; i<p; i++) {
            cin >> u;
            police.push_back(u);
        }
        dijkstra();
    }
    return 0;
}
