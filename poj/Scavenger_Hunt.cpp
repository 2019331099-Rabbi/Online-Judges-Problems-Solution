#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define endl '\n'
#define PI acos(-1)
#define sz 350
#define inf 1000000009
#define mod 100000000
using namespace std;

int indeg[sz];
vector <int> adj[sz];

void init()
{
    int i;
    for (i = 0; i < sz; i++) adj[i].clear(), indeg[i] = 0;
}

vector <int> topo(int nodes)
{
    queue <int> q;
    int i, u, v;
    for (i = 1; i <= nodes; i++) if (!indeg[i]) q.push(i);

    vector <int> ans;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        ans.push_back(u);
        for (i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];
            indeg[v]--;
            if (!indeg[v]) q.push(v);
        }
    }
    return ans;
}

void solve(int T)
{
    init();

    int nodes, cnt = 1, i, u, v;
    string s1, s2;
    map <string, int> mp1;
    map <int, string> mp2;

    cin >> nodes;
    for (i = 1; i < nodes; i++) {
        cin >> s1 >> s2;
        u = mp1[s1];
        if (!u) {
            u = cnt;
            mp2[u] = s1;
            mp1[s1] = cnt++;
        }
        v = mp1[s2];
        if (!v) {
            v = cnt;
            mp2[v] = s2; 
            mp1[s2] = cnt++;
        }
        indeg[v]++;
        adj[u].push_back(v);
    }
    if (T > 1) cout << endl;
    cout << "Scenario #" << T << ':' << endl;
    vector <int> ans = topo(nodes);
    for (i = 0; i < ans.size(); i++) cout << mp2[ans[i]] << endl;
}

int main()
{
    int T, i;
    cin >> T;
    for (i = 1; i <= T; i++) solve(i);
    return 0;
}