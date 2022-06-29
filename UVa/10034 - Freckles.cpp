#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 102
#define inf 1e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz];
vector <double> cost[sz];
vector <pair <double, double>> v;
bool vis[sz];

void init()
{
    for (int i=0; i<sz; i++) cost[i].clear(), adj[i].clear(), vis[i]=false;
    v.clear();
}

void mst_prims()
{
    int i, u;
    double tot=0, w;
    priority_queue <pair <double, pair <int, int>>, vector <pair <double, pair <int, int>>>, greater <pair <double, pair <int, int>>>> pq;
    for (i=0; i<adj[0].size(); i++) pq.push({cost[0][i], {0, adj[0][i]}});
    vis[0]=true;

    while (!pq.empty()) {
        w=pq.top().first;
        u=pq.top().second.second;
        pq.pop();
        if (vis[u]) continue;

        tot+=w;
        vis[u]=true;
        for (i=0; i<adj[u].size(); i++) {
            if (vis[adj[u][i]]) continue;
            pq.push({cost[u][i], {u, adj[u][i]}});
        }
    }
    cout << setprecision(2) << tot << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    bool flag=false;
    double d1, d2, tmp, dis;
    int T, i, n, j;
    cin >> T;
    while (T--) {
        init();
        if (flag) cout << endl;
        flag=true;
        cin >> n;
        for (i=0; i<n; i++) {
            cin >> d1 >> d2;
            v.push_back({d1, d2});
        }
        cout << fixed;
        for (i=0; i<n; i++) {
            d1=v[i].first, d2=v[i].second;
            for (j=i+1; j<n; j++) {
                dis=d1-v[j].first;
                tmp=dis*dis;
                dis=d2-v[j].second;
                tmp+=(dis*dis);
                dis=sqrt(tmp);
                adj[i].push_back(j);
                adj[j].push_back(i);
                cost[i].push_back(dis);
                cost[j].push_back(dis);
            }
        }
        mst_prims();
    }
    return 0;
}
