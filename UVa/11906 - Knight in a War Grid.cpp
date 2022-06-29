#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int r, c, m, n, xi, yi, x, y, grid[sz][sz], k=1;
vector <pair <int, int>> points;

void init()
{
    for (x=0; x<r; x++)
        for (y=0; y<c; y++) grid[x][y]=0;
}

void bfs()
{
    int row[]={m, m, -m, -m, n, n, -n, -n}, col[]={n, -n, n, -n, m, -m, m, -m}, i, cnt, ans=0, tot=0;
    bool flag;
    queue <pair <int, int>> q;
    q.push({0, 0});
    grid[0][0]=2;
    while (!q.empty()) {
        xi=q.front().first;
        yi=q.front().second;
        tot++;
        q.pop();
        cnt=0;
        for (i=0; i<8; i++) {
            x=xi+row[i];
            y=yi+col[i];
            if (x<0 || x>=r || y<0 || y>=c) continue;
            if (grid[x][y]==1) continue;
            flag=false;
            for (auto xx: points) {
                if (xx.first==x && xx.second==y) {
                    flag=true;
                    break;
                }
            }
            if (flag) continue;
            points.push_back({x, y});
            cnt++;
            if (grid[x][y]==2) continue;
            grid[x][y]=2;
            q.push({x, y});
        }
        points.clear();
        if (cnt%2) ans++;
    }
    cout << "Case " << k++ << ": " << tot-ans << ' ' << ans << endl;
}

int main()
{
    RUN_FAST; //cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> r >> c >> m >> n;
        init();
        cin >> x;
        while (x--) {
            cin >> xi >> yi;
            grid[xi][yi]=1;
        }
        bfs();
    }
    return 0;
}
