#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz  110
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz];

int bfs(int nodes, int strt)
{
    queue <int> q;
    int dis[nodes] = {0};
    q.push(strt), dis[strt] = 1;

    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += dis[u] - 1;
        for (auto xx: adj[u]) {
            if (dis[xx]) continue;
            q.push(xx);
            dis[xx] = dis[u] + 1;
        }
    }
    return ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int u, v, T = 1, cnt = 0, nodes = 1;

    int mp[sz] = {0};

    while (cin >> u >> v) {
        if (!u && !v) {
            if (cnt == 0) break;

            int ans = 0;
            for (int i = 1; i < nodes; i++) ans += bfs(nodes, i);
            nodes--;
            double avg = (double)ans / (double)(nodes * (nodes - 1));
            cout << "Case " << T << ": average length between pages = " << fixed << setprecision(3) << avg << " clicks" << endl;

            for (int i = 1; i < sz; i++) adj[i].clear(), mp[i] = 0;
            cnt = 0, nodes = 1;
            T++;
            continue;
        }
        u = (mp[u])?(mp[u]):(mp[u] = nodes++);
        v = (mp[v])?(mp[v]):(mp[v] = nodes++);
        adj[u].push_back(v);
        cnt++;
    }
    return 0;
}