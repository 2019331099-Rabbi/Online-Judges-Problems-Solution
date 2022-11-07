#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 20001
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
https://lightoj.com/problem/drunk
*/

vector <int> adj[sz];
int indeg[sz];

void init()
{
    for (int i = 0; i < sz; i++) adj[i].clear(), indeg[i] = 0;
}

bool bfs(int nodes)
{
    queue <int> q;
    for (int i = 1; i <= nodes; i++) if (!indeg[i]) q.push(i);

    int cnt = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;

        for (auto xx: adj[u]) {
            indeg[xx]--;
            if (indeg[xx] == 0) q.push(xx);
        }
    }
    return cnt == nodes;
}

void solve(int i)
{
    init();
    map <string, int> mp;
    string s1, s2;

    int n;
    cin >> n;

    int cnt = 1;
    while (n--) {
        cin >> s1 >> s2;
        int u, v;
        if (mp[s1]) u = mp[s1];
        else u = mp[s1] = cnt++;

        if (mp[s2]) v = mp[s2];
        else v = mp[s2] = cnt++;
        adj[u].push_back(v);
        indeg[v]++;
    }
    cout << "Case " << i << ": " << (bfs(mp.size())?"Yes":"No") << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}