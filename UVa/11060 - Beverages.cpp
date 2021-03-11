#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 700
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

map <string, int> mp;

void topo(int nodes, int indeg[], vector <int> adj[], vector <string> anss)
{
    int i, x;
    vector <int> ansn;
    bool vis[nodes]={false};
    priority_queue <int, vector <int>, greater <int>> q;
    for (i=0; i<nodes; i++)
        if (!indeg[i]) q.push(i), vis[i]=true;
    while (!q.empty()) {
        x=q.top();
        ansn.push_back(x);
        q.pop();
        for (int xx: adj[x]) {
            indeg[xx]--;
            if (!indeg[xx] && !vis[xx])
                q.push(xx), vis[xx]=true;
        }
    }
    for (int xx: ansn) cout << ' ' << anss[xx];
    cout << '.' << endl << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, i, tmp, T=1;
    string s1, s2, s3=": Dilbert should drink beverages in this order:";
    while (cin >> nodes) {
        vector <string> anss(nodes);
        for (i=0; i<nodes; i++) {
            cin >> s1;
            anss[i]=s1;
            mp[s1]=i;
        }
        vector <int> adj[nodes];
        int indeg[nodes]={0};
        cin >> edges;
        while (edges--) {
            cin >> s1 >> s2;
            tmp=mp[s2];
            indeg[tmp]++;
            adj[mp[s1]].push_back(tmp);
        }
        cout << "Case #" << T++ << s3;
        topo(nodes, indeg, adj, anss);
        mp.clear();
    }
    return 0;
}
