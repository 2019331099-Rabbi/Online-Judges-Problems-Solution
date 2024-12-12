#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1010
#define inf 1e15
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int64_t> adj[sz], cost[sz];
int64_t dis[sz], parent[sz];
int64_t ans;

void init(int64_t nodes)
{
    for (int64_t i = 0; i <= nodes; i++) dis[i] = inf;
}

bool bellmanford(int64_t strt, int64_t nodes)
{
    int64_t u;
    init(nodes);
    dis[strt] = 0;

    for (int64_t k = 1; k < nodes; k++) {
        for (int64_t i = 1; i <= nodes; i++) {
            for (int64_t j = 0; j < adj[i].size(); j++) {
                u = adj[i][j];
                if (dis[u] > dis[i] + cost[i][j]) dis[u] = dis[i] + cost[i][j];
            }
        }
    }
    ans = dis[nodes];


    for (int64_t k = 1; k < nodes; k++) {
        for (int64_t i = 1; i <= nodes; i++) {
            for (int64_t j = 0; j < adj[i].size(); j++) {
                u = adj[i][j];
                if (dis[u] > dis[i] + cost[i][j]) dis[u] = dis[i] + cost[i][j];
            }
        }
    }
    if (dis[nodes] != ans) return true;
    return false;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t nodes, edges, u, v, w;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        cost[u].push_back(-w);
    }

    // for (int64_t i = 1; i <= nodes; i++) {
    //     cout << i << ": ";
    //     for (int64_t j = 0; j < adj[i].size(); j++) cout << adj[i][j] << ' ';
    //     cout << endl;
    // }
    // for (int64_t i = 1; i <= nodes; i++) {
    //     cout << i << ": ";
    //     for (int64_t j = 0; j < adj[i].size(); j++) cout << cost[i][j] << ' ';
    //     cout << endl;
    // }

    if (bellmanford(1, nodes)) cout << "inf" << endl;
    else cout << -ans << endl;
    return 0;
}
/**
6 10
0 1 3
0 2 -2
0 4 8
2 3 6
1 2 1
1 5 4
1 4 6
4 5 -5
3 5 -5
3 1 9
0 5
 */