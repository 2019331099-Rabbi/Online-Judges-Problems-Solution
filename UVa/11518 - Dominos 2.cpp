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

int cnt;

void bfs(int points, int nodes, vector <int> adj[])
{
    int start, x, i, tmp, cnt=0;
    bool vis[nodes+1]={false};
    while (points--) {
        cin >> start;
        if (vis[start]) continue;
        queue <int> q;
        q.push(start);
        vis[start]=true;
        while (!q.empty()) {
            x=q.front();
            cnt++;
            q.pop();
            for (i=0; i<adj[x].size(); i++) {
                tmp=adj[x][i];
                if (vis[tmp]) continue;
                q.push(tmp);
                vis[tmp]=true;
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, nodes, edges, points, u, v;
    cin >> T;
    while (T--) {
        cin >> nodes >> edges >> points;
        vector <int> adj[nodes+1];
        while (edges--) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bfs(points, nodes, adj);
    }
    return 0;
}
