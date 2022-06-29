#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 20001
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int bfs(vector <int> adj[], vector <int> alln)
{
    int i, j, x, tmp, nodes=alln.size(), src, ans=0, tot, cnt;
    queue <int> q;
    bool vis[sz]={false}, race[sz];
    for (i=0; i<nodes; i++) {
        src=alln[i];
        if (vis[src]) continue;
        q.push(src);
        vis[src]=true, race[src]=true;
        tot=cnt=0;
        while (!q.empty()) {
            x=q.front();
            if (race[x]) cnt++;
            tot++;
            q.pop();
            for (j=0; j<adj[x].size(); j++) {
                tmp=adj[x][j];
                if (vis[tmp]) continue;
                q.push(tmp);
                vis[tmp]=true, race[tmp]=!race[x];
            }
        }
        ans+=max(cnt, tot-cnt);
    }
    return ans;
}

int main()
{
    RUN_FAST;
    int T, edges, u, v, i=1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &edges);
        vector <int> adj[sz], alln;
        bool flag[sz]={false};
        while (edges--) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v); adj[v].push_back(u);
            if (!flag[u]) alln.push_back(u), flag[u]=true;
            if (!flag[v]) alln.push_back(v), flag[v]=true;
        }
        printf("Case %d: %d\n", i++, bfs(adj, alln));
    }
    return 0;
}
