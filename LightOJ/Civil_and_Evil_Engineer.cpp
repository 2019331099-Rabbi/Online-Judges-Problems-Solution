#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 105
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
https://lightoj.com/problem/civil-and-evil-engineer
*/

vector <int> adj[sz], cost[sz];
bool vis[sz];

void init()
{
    for (int i = 0; i < sz; i++) adj[i].clear(), cost[i].clear(), vis[i] = false;
}

int mstPrims()
{
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

    for (int i = 0; i < adj[0].size(); i++) pq.push({cost[0][i], adj[0][i]});
    vis[0] = true;

    int sum1 = 0;
    while (!pq.empty()) {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (vis[v]) continue;
        sum1 += w;
        vis[v] = true;

        for (int i = 0; i < adj[v].size(); i++) {
            if (vis[adj[v][i]]) continue;
            pq.push({cost[v][i], adj[v][i]});
        }
    }

    priority_queue <pair <int, int>, vector <pair <int, int>>> pq1;

    for (int i = 0; i < adj[0].size(); i++) pq1.push({cost[0][i], adj[0][i]});
    memset(vis, false, sizeof(vis));
    vis[0] = true;

    int sum2 = 0;
    while (!pq1.empty()) {
        int w = pq1.top().first;
        int v = pq1.top().second;
        pq1.pop();

        if (vis[v]) continue;
        sum2 += w;
        vis[v] = true;

        for (int i = 0; i < adj[v].size(); i++) {
            if (vis[adj[v][i]]) continue;
            pq1.push({cost[v][i], adj[v][i]});
        }
    }
    return sum1 + sum2;
}

void solve(int i)
{
    init();

    int nodes;
    cin >> nodes;

    int u, v, w;
    while (cin >> u >> v >> w && (u or v or w)) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int ans = mstPrims();
    cout << "Case " << i << ": ";
    if (ans & 1) cout << ans << "/2" << endl;
    else cout << ans / 2 << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}