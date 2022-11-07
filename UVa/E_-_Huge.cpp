#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz  22
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row4[]={0, 0, -1, 1};
int col4[]={1, -1, 0, 0};

vector <string> grid;
int n, m;
bool vis[sz][sz];
char lnd;

int floodfill(int x, int y)
{
    if (x < 0 || x >= n) return 0;
    if (y < 0) y = m - 1;
    else if (y >= m) y = 0;
    if (vis[x][y] || grid[x][y] != lnd) return 0;

    vis[x][y] = true;
    int ret = 1;
    for (int i = 0; i < 4; i++) ret += floodfill(x + row4[i], y + col4[i]);
    return ret;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string s;

    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> s;
            grid.push_back(s);
        }
        int x, y;
        cin >> x >> y;
        lnd = grid[x][y];

        floodfill(x, y);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == lnd) ans = max(ans, floodfill(i, j));
            }
        }
        cout << ans << endl;
        grid.clear();
        memset(vis, false, sizeof(vis));
    }
    return 0;
}