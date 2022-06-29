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

int bfs(int nodes, vector <int> adj[])
{
    bool vis[nodes]={false};
    queue <int> q;
    int x, i, tmp, j, ans=0;
    for (i=0; i<nodes; i++) {
        if (vis[i]) continue;
        q.push(i);
        vis[i]=true;
        ans++;
        while (!q.empty()) {
            x=q.front();
            q.pop();
            for (j=0; j<adj[x].size(); j++) {
                tmp=adj[x][j];
                if (vis[tmp]) continue;
                q.push(tmp);
                vis[tmp]=true;
            }
        }
    }
    return ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, nodes, ans;
    bool flag=false;
    char ch;
    string s;
    cin >> T;
    while (T--) {
        if (flag) cout << endl;
        flag=true;
        cin >> ch;
        nodes=ch-'A'+1;
        vector <int> adj[nodes];
        cin.ignore();
        while (getline(cin, s)) {
            if (!s.size()) break;
            adj[s[0]-'A'].push_back(s[1]-'A');
            adj[s[1]-'A'].push_back(s[0]-'A');
        }
        ans=bfs(nodes, adj);
        cout << ans << endl;
    }
    return 0;
}
