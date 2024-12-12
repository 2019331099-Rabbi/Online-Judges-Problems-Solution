#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


vector<int> bfs(int strt, int n, vector <set<int>> &adj, vector <vector <vector <int>>> &color)
{
    vector <int> dis(n, inf);
    queue <pair <int, pair <int, int>>> pq;
    pq.push({0, {-1, 0}});
    dis[strt] = 0;

    while (!pq.empty()) {
        int u = pq.front().first;
        int prevColor = pq.front().second.first;
        int cnt = pq.front().second.second;
        pq.pop();

        for (auto v: adj[u]) {
            if (!color[u][v][0] && !color[u][v][1]) continue;
            if (prevColor == -1) {
                if (color[u][v][0]) {
                    pq.push({v, {1, cnt + 1}});
                    color[u][v][0] = 0;
                    dis[v] = min(dis[v], cnt + 1);
                }
                if (color[u][v][1]) {
                    pq.push({v, {0, cnt + 1}});
                    color[u][v][1] = 0;
                    dis[v] = min(dis[v], cnt + 1);
                }
            }
            else if (color[u][v][prevColor]) {
                pq.push({v, {!prevColor, cnt + 1}});
                color[u][v][prevColor] = 0;
                dis[v] = min(dis[v], cnt + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) if (dis[i] == inf) dis[i] = -1;
    return dis;
}

vector <int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)
{
    vector <set <int>> adj(n);
    vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for (int i = 0; i < redEdges.size(); i++) {
        int u = redEdges[i][0], v = redEdges[i][1];
        adj[u].insert(v);
        color[u][v][0] = true;
    }
    for (int i = 0; i < blueEdges.size(); i++) {
        int u = blueEdges [i][0], v = blueEdges[i][1];
        adj[u].insert(v);
        color[u][v][1] = true;
    }
    return bfs(0, n, adj, color);
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int nodes, red, blue;
    cin >> nodes >> red >> blue;


    vector <vector <int>> redEdges, blueEdges;
    while (red--) {
        vector <int> redVector(2);
        cin >> redVector[0] >> redVector[1];
        redEdges.push_back(redVector);
    }

    while (blue--) {
        vector <int> blueVector(2);
        cin >> blueVector[0] >> blueVector[1];
        blueEdges.push_back(blueVector);
    }
    auto ans = shortestAlternatingPaths(nodes, redEdges, blueEdges);
    for (int i = 0; i < nodes; i++) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}

// 118.179.223.10
// 202.4.96.6