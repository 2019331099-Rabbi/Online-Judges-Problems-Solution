                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];    

    int deg[n + 1] = {0}, cost[n + 1] = {0};
    vector <pair <int, int>> pr;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        pr.push_back({u, v});
        deg[u]++, deg[v]++;
    }

    if (m % 2 == 0) cout << 0 << endl;
    else {
        int mn = inf;
        for (int i = 1; i <= n; i++) {
            if (deg[i] & 1) mn = min(mn, arr[i]);
        }
        for (auto xx: pr) {
            if (deg[xx.first] % 2 == 0 && deg[xx.second] % 2 == 0) mn = min(mn, arr[xx.first] + arr[xx.second]);
        }
        cout << mn << endl;
    }
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}