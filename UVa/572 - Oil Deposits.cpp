#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row8[]={0, 0, -1, 1, 1, -1, -1, 1};
int col8[]={1, -1, 0, 0, 1, 1, -1, -1};

int n, m;
vector <string> grid(sz);

void bfs()
{
    queue <pair <int, int>> q;
    int i, j, k, xi, yi, x, y, cnt=0;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (grid[i][j]=='@') {
                cnt++;
                q.push({i, j});
                while (!q.empty()) {
                    xi=q.front().first;
                    yi=q.front().second;
                    q.pop();
                    for (k=0; k<8; k++) {
                        x=xi+row8[k];
                        y=yi+col8[k];
                        if (x<0 || x>=n || y<0 || y>=m) continue;
                        if (grid[x][y]=='*') continue;
                        q.push({x, y});
                        grid[x][y]='*';
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i;
    while (cin >> n >> m and n) {
        for (i=0; i<n; i++) cin >> grid[i];
        bfs();
    }
    return 0;
}
