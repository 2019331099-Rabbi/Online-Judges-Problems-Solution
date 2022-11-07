#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 105
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
https://lightoj.com/problem/hit-the-light-switches
*/

void solve(int i)
{
    int nodes, edges;

    cin >> nodes >> edges;
    int indeg[nodes + 1] = {0};

    while (edges--) {
        int u, v;
        cin >> u >> v;
        indeg[v]++;
    }
    int cnt = 0;
    for (int i = 1; i <= nodes; i++) if (!indeg[i]) cnt++;
    cout << "Case " << i << ": " << max(1, cnt) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}