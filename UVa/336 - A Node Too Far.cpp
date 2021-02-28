#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 30
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};
//int col[]={1, -1, 0, 0};

map <string, int> mp;

int bfs(int ttl, int start, int nodes, vector <int> adj[])
{
    int x, i, len, tmp, rable=0;
    int ttlv[nodes];
    bool color[nodes]={false};
    queue <int> q;
    q.push(start);
    color[start]=true;
    ttlv[start]=ttl;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        rable++;
        if (!ttlv[x]) continue;
        len=adj[x].size();
        for (i=0; i<len; i++) {
            tmp=adj[x][i];
            if (color[tmp]) continue;
            q.push(tmp);
            color[tmp]=true;
            ttlv[tmp]=ttlv[x]-1;
        }
    }
    return nodes-rable;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int edges, i, u, v, nodes, start, ttl, nrable, cnt=1;
    string s1, s2, s3=" nodes not reachable from node ", s4=" with TTL = ";
    while (cin >> edges) {
        if (!edges) break;
        vector <int> adj[sz];
        nodes=0;
        for (i=0; i<edges; i++) {
            cin >> s1 >> s2;
            if (!mp.count(s1)) mp[s1]=nodes++;
            if (!mp.count(s2)) mp[s2]=nodes++;
            u=mp[s1], v=mp[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while (cin >> s1 >> ttl) {
            if (s1=="0" && !ttl) break;
            if (!mp.count(s1)) nrable=nodes;
            else {
                start=mp[s1];
                nrable=bfs(ttl, start, nodes, adj);
            }
            cout << "Case " << cnt++ << ": " << nrable << s3 << s1 << s4 << ttl << '.' << endl;
        }
        mp.clear();
    }
    return 0;
}
