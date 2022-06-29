#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 202
#define inf 1e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int nodes, edges, u, v, w, dis[sz];
vector <int> adj1[sz], cost1[sz], adj2[sz], cost2[sz];
map <string, int> mp;
string s1, s2;
bool vis[sz];

void init()
{
    for (int i=0; i<sz; i++) adj1[i].clear(), adj2[i].clear(), cost1[i].clear(), cost2[i].clear(), dis[i]=0, vis[i]=false;
    mp.clear();
}

int bfs(int strt, int dst)
{
    int i;
    queue <int> q;
    q.push(strt);
    dis[strt]=inf;

    while (!q.empty()) {
        u=q.front();
        q.pop();
        for (i=0; i<adj2[u].size(); i++) {
            v=adj2[u][i];
            if (dis[v]) continue;
            q.push(v);
            dis[v]=min(dis[u], cost2[u][i]);
            if (v==dst) return dis[v];
        }
    }
}

void mst_prims()
{
    int i;
    priority_queue <pair <int, pair <int, int>>> pq;
    for (i=0; i<adj1[1].size(); i++) pq.push({cost1[1][i], {1, adj1[1][i]}});
    vis[1]=true;

    while (!pq.empty()) {
        w=pq.top().first;
        u=pq.top().second.first;
        v=pq.top().second.second;
        pq.pop();

        if (vis[v]) continue;
        vis[v]=true;

        adj2[u].push_back(v);
        adj2[v].push_back(u);
        cost2[u].push_back(w);
        cost2[v].push_back(w);

        for (i=0; i<adj1[v].size(); i++) {
            if (vis[adj1[v][i]]) continue;
            pq.push({cost1[v][i], {v, adj1[v][i]}});
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int cnt, T=1;
    while (cin >> nodes >> edges and nodes and edges) {
        init();
        cnt=0;
        while (edges--) {
            cin >> s1 >> s2 >> w;
            u=mp[s1];
            if (!u) u=mp[s1]=++cnt;
            v=mp[s2];
            if (!v) v=mp[s2]=++cnt;

            adj1[u].push_back(v);
            adj1[v].push_back(u);
            cost1[u].push_back(w);
            cost1[v].push_back(w);
        }
        cin >> s1 >> s2;
        mst_prims();
        cout << "Scenario #" << T++ << endl << bfs(mp[s1], mp[s2]) << " tons" << endl << endl;
    }
    return 0;
}
