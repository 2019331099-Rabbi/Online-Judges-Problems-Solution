#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int nodes, edges, u, w, dis[sz], res[sz];
map <string, int> mp;
vector <pair <int, int>> adj[sz];

void init()
{
    for (int i=0; i<sz; i++) adj[i].clear(), dis[i]=inf;
    mp.clear();
}

void bellmanford()
{
    int i, j, k, alt;
    dis[0]=0;

    for (k=1; k<nodes; k++) {
        for (i=nodes-1; i>=0; i--) {
            for (auto xx: adj[i]) {
                alt=dis[i]+xx.second;
                if (alt>=dis[xx.first]) continue;
                dis[xx.first]=alt;
            }
        }
        res[k-1]=dis[nodes-1];
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    bool flag=false;
    int T, i, q, t;
    string s1, s2;
    cin >> T;
    for (t=1; t<=T; t++) {
        init();
        if (flag) cout << endl;
        flag=true;
        cin >> nodes;
        for (i=0; i<nodes; i++) {
            cin >> s1;
            mp[s1]=i;
        }
        cin >> edges;
        while (edges--) {
            cin >> s1 >> s2 >> w;
            u=mp[s1];
            adj[u].push_back({mp[s2], w});
        }
        for (i=0; i<nodes; i++) sort(adj[i].begin(), adj[i].end(), greater <pair <int, int>>());
        bellmanford();

        cout << "Scenario #" << t << endl;
        cin >> q;
        while (q--) {
            cin >> u;
            u=min(u, nodes-2);
            if (res[u]==inf) cout << "No satisfactory flights" << endl;
            else cout << "Total cost of flight(s) is $" << res[u] << endl;
        }
    }
    return 0;
}
