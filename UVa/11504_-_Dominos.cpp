#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz];
int indeg[sz];

void topo(int nodes)
{
    priority_queue <int, vector <int>, greater <int>> q;
    for (int i = 1; i <= nodes; i++) if (!indeg[i]) q.push(i);

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        cout << u << ' ';

        for (auto xx: adj[u]) {
            indeg[xx]--;
            if (!indeg[xx]) q.push(xx);
        }
    }
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges;

    cin >> nodes >> edges;
    while (edges--) {
        int u, v, k;
        cin >> u >> k;
        indeg[u] += k;
        while (k--) {
            cin >> v;
            adj[v].push_back(u);
        }
    }
    topo(nodes);
    return 0;
}