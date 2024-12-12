#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

int bfs(vector<vector<int>>& grid, int xi, int yi)
{
    int n = grid.size(), m = grid[0].size();
    queue <pair <int, int>> q;

    bool flag = false;
    int cnt = 0;

    q.push({xi, yi});
    grid[xi][yi] = 0;
    while (!q.empty()) {
        xi = q.front().first;
        yi = q.front().second;
        cnt++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xf = xi + row[i];
            int yf = yi + col[i];
            if (xf < 0 || xf >= n || yf < 0 || yf >= m) {
                flag = true;
                continue;
            }
            if (grid[xf][yf] == 0) continue;
            q.push({xf, yf});
            grid[xf][yf] = 0;
        }
    }
    if (flag) cnt = 0;
    return cnt;
}

int numEnclaves(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) cnt += bfs(grid, i, j);
        }
    }
    return cnt;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << numEnclaves(grid) << endl;

    return 0;

}