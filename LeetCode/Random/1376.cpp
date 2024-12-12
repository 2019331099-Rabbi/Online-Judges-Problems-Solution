#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
{
    vector <vector <pair <int, int>>> adj(n);
    for (int v = 0; v < n; v++) {
        int u = manager[v];
        if (u == -1) continue;
        adj[u].push_back({v, informTime[u]});
    }

    queue <pair <int, int>> q;
    vector <bool> vis(n, false);
    q.push({headID, 0});
    vis[headID] = true;

    int ans = -1;

    while (!q.empty()) {
        int u = q.front().first;
        int cnt = q.front().second;
        ans = max(ans, cnt);
        q.pop();

        for (auto xx: adj[u]) {
            int v = xx.first, cost = xx.second;
            if (vis[v]) continue;
            q.push({v, cnt + cost});
            vis[v] = true;
        }
    }
    return ans;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int nodes, headID;

    cin >> nodes >> headID;
    vector <int> manager(nodes), informTime(nodes);
    for (auto &xx: manager) cin >> xx;
    for (auto &xx: informTime) cin >> xx;

    int ans = numOfMinutes(nodes, headID, manager, informTime);
    cout << ans << endl;
    return 0;
    
    
}

// 118.179.223.10
// 202.4.96.6