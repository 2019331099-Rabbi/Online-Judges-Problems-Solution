#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 700
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board


void bfs(int start, int nodes, vector <int> adj[])
{
    bool vis[nodes+1]={false};
    int x, i, tmp, cnt=0;
    queue <int> q;
    q.push(start);
    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (vis[tmp]) continue;
            q.push(tmp);
            vis[tmp]=true, cnt++;
        }
    }
    cout << nodes-cnt;
    for (i=1; i<=nodes; i++) {
        if (vis[i]) continue;
        cout << ' ' << i;
    }
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, u, v;
    while (cin >> nodes) {
        if (!nodes) break;
        vector <int> adj[nodes+1];
        while (cin >> u) {
            if (!u) break;
            while (cin >> v) {
                if (!v) break;
                adj[u].push_back(v);
            }
        }
        cin >> u;
        while (u--) {
            cin >> v;
            bfs(v, nodes, adj);
        }
    }
    return 0;
}
