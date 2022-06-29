#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

map <string, int> mp;

void bfs(int src, int dest, vector <int> adj[], vector <string>paths, int nodes)
{
    bool vis[sz]={false};
    int x, i, tmp, parent[sz];
    parent[dest]=-1;
    queue <int> q;
    q.push(src);
    vis[src]=true, parent[src]=-1;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (vis[tmp]) continue;
            q.push(tmp);
            vis[tmp]=true;
            parent[tmp]=x;
        }
        if (vis[dest]) break;
    }
    if (parent[dest]==-1) {
        cout << "No route" << endl;
        return;
    }
    vector <int> pathn;
    while (~dest) {
        pathn.push_back(dest);
        dest=parent[dest];
    }
    for (i=pathn.size()-1; i>=1; i--)
        cout << paths[pathn[i]] << ' ' << paths[pathn[i-1]] << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    bool flag=false;
    int edges, nodes, u, v, src, dest;
    string s1, s2;
       while (cin >> edges) {
        if (flag) cout << endl;
        flag=true;
        nodes=0;
        vector <int> adj[sz];
        while (edges--) {
            cin >> s1 >> s2;
            if (!mp.count(s1)) mp[s1]=nodes++;
            if (!mp.count(s2)) mp[s2]=nodes++;
            u=mp[s1], v=mp[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> s1 >> s2;
        if (!mp.count(s1) || !mp.count(s2)) {
            cout << "No route" << endl;
            mp.clear();
            continue;
        }
        src=mp[s1], dest=mp[s2];
        if (src==dest) {
            cout << s1 << ' ' << s2 << endl;
            mp.clear();
            continue;
        }
        vector <string> paths(nodes);
        for (auto it=mp.begin(); it!=mp.end(); it++) paths[it->second]=it->first;
        bfs(src, dest, adj, paths, nodes);
        mp.clear();
    }
    return 0;
}
