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

int row[]={1, 0, 0, -1};
int col[]={0, 1, -1, 0};

void bfs(int n, int m, vector <string> adj)
{
    int xi, yi, xd, yd, i, x, y;
    char ch;
    xi=n-1, xd=0;
    for (i=0; i<m; i++)
        if (adj[xi][i]=='@') {yi=i; break;}
    for (i=0; i<m; i++)
        if (adj[xd][i]=='#') {yd=i; break;}
    queue <pair <int, int>> q;
    vector <vector <int>> path(n, vector <int>(m, 0));
    q.push({xi, yi});
    path[xi][yi]=-1;

    while (!q.empty()) {
        xi=q.front().first;
        yi=q.front().second;
        q.pop();
        for (i=1; i<=3; i++) {
            x=row[i]+xi, y=col[i]+yi;
            if (x<0 || x>=n || y<0 || y>=m || path[x][y]) continue;
            ch=adj[x][y];
            if (ch=='I' || ch=='E' || ch=='H' || ch=='O' || ch=='V' || ch=='A' || ch=='#') {
                q.push({x, y});
                path[x][y]=i;
            }
        }
        if (path[xd][yd]) break;
    }
    vector <string> ans;
    while (~path[xd][yd]) {
        x=path[xd][yd];
        if (x==3) xd++, ans.push_back("forth");
        else if (x==2) yd++, ans.push_back("left");
        else if (x==1) yd--, ans.push_back("right");
    }
    for (i=ans.size()-1; i>=0; i--) cout << ans[i] << " \n"[!i];
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, n, m;
    vector <string> adj;
    string s;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        while (n--) {
            cin >> s;
            adj.push_back(s);
        }
        n=adj.size();
        bfs(n, m, adj);
        adj.clear();
    }
    return 0;
}
