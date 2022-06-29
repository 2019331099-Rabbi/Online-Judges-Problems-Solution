#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10001
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

pair <int, int> bfs(vector <int> adj[], vector <int> cost[], int nodes, int strt)
{
    int i, x, tmp, mx=0, vis[nodes]={0}, src;
    pair <int, int> ans;
    queue <int> q;
    q.push(strt), vis[strt]=1;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (vis[tmp]) continue;
            q.push(tmp);
            vis[tmp]=vis[x]+cost[x][i];
            if (vis[tmp]>mx) {
                mx=vis[tmp];
                src=tmp;
            }
        }
    }
    ans={mx, src};
    return ans;
}

int main()
{
    RUN_FAST;
    int T, nodes, i, u, v, w, j=1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &nodes);
        vector <int> adj[nodes], cost[nodes];
        for (i=1; i<nodes; i++) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        pair <int, int> ans=bfs(adj, cost, nodes, 0);
        ans=bfs(adj, cost, nodes, ans.second);
        printf("Case %d: %d\n", j++, ans.first-1);
    }
    return 0;
}
