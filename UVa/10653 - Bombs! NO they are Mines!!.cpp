#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 21
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[]={0, 0, -1, 1};
int col[]={1, -1, 0, 0};

int bfs(int xi, int yi, int xd, int yd, int r, int c, vector <vector <bool>> adj)
{
    int i, x, y;
    vector <vector <int>> dis(r, vector <int>(c, 0));
    queue <pair <int, int>> q;
    q.push({xi, yi});
    dis[xi][yi]=1;

    while (!q.empty()) {
        xi=q.front().first;
        yi=q.front().second;
        q.pop();
        for (i=0; i<4; i++) {
            x=row[i]+xi;
            y=col[i]+yi;
            if (x<0 || x>=r || y<0 || y>=c || dis[x][y] || adj[x][y]) continue;
            q.push({x, y});
            dis[x][y]=dis[xi][yi]+1;
        }
        if (dis[xd][yd]) return dis[xd][yd];
    }
    return -1;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int r, c, br, xi, yi, xd, yd, n;
    while (cin >> r >> c) {
        if (!r && !c) break;
        vector <vector <bool>> adj(r, vector <bool>(c, false));
        cin >> br;
        while (br--) {
            cin >> xi >> n;
            while (n--) {
                cin >> yi;
                adj[xi][yi]=true;
            }
        }
        cin >> xi >> yi >> xd >> yd;
        n=bfs(xi, yi, xd, yd, r, c, adj);
        cout << n-1 << endl;
    }
    return 0;
}
