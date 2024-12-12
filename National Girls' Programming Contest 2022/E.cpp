#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    char grid[n][m];
    memset(grid, '#', sizeof(grid));

    bool dir = true;
    int x = 0, y = 0;

    k--;
    for (int i = 0; i < k; i++) {
        grid[x][y] = '.';

        if (dir) x++;
        else x--;

        if (x >= n) {
            x = n - 1, y++;
            if (i + 1 < k) grid[x][y] = '.', y++;
            dir = !dir;
            i++;
        }
        else if (x < 0) {
            x = 0, y++;
            if (i + 1 < k) grid[x][y] = '.', y++;
            dir = !dir;
            i++;
        }
    }
    grid[0][0] = 's', grid[x][y] = 'e';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << grid[i][j];
        cout << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}