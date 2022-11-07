#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 20000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int indeg[sz];
vector <int> adj[sz];

void topo(int nodes)
{
    priority_queue <int, vector <int>, greater <int>> q;
    for (int i = 1; i <= nodes; i++) if (!indeg[i]) q.push(i);

    vector <int> ans;

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ans.push_back(u);
        for (auto xx: adj[u]) {
            indeg[xx]--;
            if (!indeg[xx]) q.push(xx);
        }
    }
    if (ans.size() != nodes) cout << "Sandro fails." << endl;
    else {
        for (auto xx: ans) cout << xx << ' ';
        cout << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges;

    cin >> nodes >> edges;

    while (edges--) {
        int u, v;
        cin >> u >> v;
        indeg[v]++;
        adj[u].push_back(v);
    }
    topo(nodes);
    return 0;
}