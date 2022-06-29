#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10001
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int bfs(int src, int dst, vector <int> adj[], int nodes)
{
    int i, x, tmp, vis[nodes]={0};
    queue <int> q;
    q.push(src);
    vis[src]=1;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (vis[tmp]) continue;
            q.push(tmp);
            vis[tmp]=vis[x]+1;
        }
        if (vis[dst]) return vis[dst]-1;
    }
    return -1;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cout << "SHIPPING ROUTES OUTPUT" << endl;
    int T, nodes, edges, q, i, u, v, j=1;
    string s1, s2;
    cin >> T;
    while (T--) {
        cout << endl << "DATA SET  " << j++ << endl << endl;
        cin >> nodes >> edges >> q;
        map <string, int> mp;
        vector <int> adj[nodes];
        u=0;
        for (i=0; i<nodes; i++) {
            cin >> s1;
            mp[s1]=u++;
        }
        while (edges--) {
            cin >> s1 >> s2;
            u=mp[s1], v=mp[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while (q--) {
            cin >> v >> s1 >> s2;
            u=bfs(mp[s1], mp[s2], adj, nodes);
            if (u==-1) cout << "NO SHIPMENT POSSIBLE" << endl;
            else cout << '$' << v*u*100 << endl;
        }
    }
    cout << endl << "END OF OUTPUT" << endl;
    return 0;
}
