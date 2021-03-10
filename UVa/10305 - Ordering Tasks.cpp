#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 700
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void toposort(int indeg[], int nodes, vector <int> adj[])
{
    int i, x, tmp, len;
    vector <int> ans;
    queue <int> q;
    bool vis[nodes+1]={false};
    for (i=1; i<=nodes; i++)
        if (!indeg[i]) q.push(i), vis[i]=true;
    while (!q.empty()) {
        x=q.front();
        ans.push_back(x);
        len=adj[x].size();
        q.pop();
        for (i=0; i<len; i++) {
            tmp=adj[x][i];
            indeg[tmp]--;
            if (!indeg[tmp] && !vis[tmp])
            vis[tmp]=true, q.push(tmp);
        }
    }
    for (i=0; i<nodes; i++)
        cout << ans[i] << " \n"[i==nodes-1];
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v;
    while (cin >> nodes >> edges) {
        if (!nodes && !edges) break;
        vector <int> adj[nodes+1];
        int indeg[nodes+1]={0};
        while (edges--) {
            cin >> u >> v;
            adj[u].push_back(v);
            indeg[v]++;
        }
        toposort(indeg, nodes, adj);
    }
    return 0;
}
