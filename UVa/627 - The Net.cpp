#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void bfs(vector <int> adj[], int src, int dst, int nodes)
{
    int i, x, tmp, parent[nodes+1]={0};
    queue <int> q;
    q.push(src);
    parent[src]=-1;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (parent[tmp]) continue;
            parent[tmp]=x;
            q.push(tmp);
        }
        if (parent[dst]) break;
    }
    if (!parent[dst]) {
        cout << "connection impossible" << endl;
        return;
    }
    vector <int> route;
    while (~dst) route.push_back(dst), dst=parent[dst];
    x=route.size();
    cout << route[x-1];
    for (i=x-2; i>=0; i--) cout << ' ' << route[i];
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, i, j, val, len;
    vector <int> v;
    char ch1='-', ch2=',';
    string s;
    while (cin >> nodes) {
        vector <int> adj[nodes+1];
        for (i=0; i<nodes; i++) {
            cin >> s;
            len=s.size();
            for (j=0; j<len; j++) if (s[j]==ch1 || s[j]==ch2) s[j]=' ';
            stringstream ss(s);
            while (ss >> val) v.push_back(val);

            len=v.size();
            val=v[0];
            for (j=1; j<len; j++) adj[val].push_back(v[j]);
            v.clear();
        }
        cout << "-----" << endl;
        cin >> val;
        while (val--) {
            cin >> i >> j;
            bfs(adj, i, j, nodes);
        }
    }
    return 0;
}
