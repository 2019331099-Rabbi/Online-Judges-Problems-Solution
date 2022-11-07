#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;

    cin >> n;
    int grid[n][n];
    memset(grid, 0, sizeof(grid));

    for (int i = 0; i < n; i++) cin >> grid[i][i];

    for (int i = 0; i < n; i++) {
        int val = grid[i][i];
        int cnt = val - 1;
        
        int x = i, y = i;
        while (cnt--) {

            if (y > 0 && !grid[x][y - 1]) y--;
            else x++;
            grid[x][y] = val;
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << grid[i][j] << ' ';
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