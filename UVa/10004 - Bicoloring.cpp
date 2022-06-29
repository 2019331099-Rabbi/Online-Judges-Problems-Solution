#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 30
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};
//int col[]={1, -1, 0, 0};

bool bfs(int nodes, vector<int> adj[])
{
    int x, i, len, tmp;
    bool flag;
    bool vis[nodes]={false}, color[nodes];
    queue <int> q;
    q.push(0);
    vis[0]=color[0]=true;
    while (!q.empty()) {
        x=q.front();
        q.pop();
        len=adj[x].size();
        for (i=0; i<len; i++) {
            tmp=adj[x][i];
            if (vis[tmp]) continue;
            q.push(tmp);
            vis[tmp]=true;
            color[tmp]=(color[x])?false:true;
        }
    }
    for (i=0; i<nodes; i++) {
        flag=!color[i];
        for (int xx: adj[i])
            if (color[xx]!=flag) return false;
    }
    return true;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v, i;
    bool flag;
    while (cin >> nodes) {
        if (!nodes) break;
        cin >> edges;
        vector <int> adj[nodes];
        for (i=0; i<edges; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        flag=bfs(nodes, adj);
        if (flag) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
