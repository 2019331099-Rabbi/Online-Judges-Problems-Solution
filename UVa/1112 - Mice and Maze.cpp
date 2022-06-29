#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

vector <int> adj[sz], wt[sz];
int cell, tlim, strt, cost[sz];

void init()
{
    int i;
    for (i=1; i<=cell; i++) adj[i].clear(), wt[i].clear(), cost[i]=inf;
    cost[strt]=0;
}

void dijkstra()
{
    int i, x, tmp, tval, ans=0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push({0, strt});

    while (!pq.empty()) {
        x=pq.top().second;
        pq.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            tval=cost[x]+wt[x][i];
            if (cost[tmp]<=tval) continue;
            cost[tmp]=tval;
            pq.push({tval, tmp});
        }
    }
    for (i=1; i<=cell; i++)
        if (cost[i]<=tlim) ans++;
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, edges, u, v, w, cnt, i;
    bool flag=false;
    cin >> T;
    while (T--) {
        if (flag) cout << endl;
        flag=true;
        cin >> cell >> strt >> tlim >> edges;
        init();
        while (edges--) {
            cin >> u >> v >> w;
            adj[v].push_back(u);
            wt[v].push_back(w);
        }
        dijkstra();
    }
    return 0;
}
