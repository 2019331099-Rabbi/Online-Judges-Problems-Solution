#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[] = {0, 0, -1, 1};
int col[] = {1, -1, 0, 0};

void bfs(int xi, int yi, vector<vector<int>>& grid, int fillValue)
{
    int n = grid.size();
    queue <pair <int, int>> pq;
    pq.push({xi, yi});
    grid[xi][yi] = -1;

    while (!pq.empty()) {
        xi = pq.front().first;
        yi = pq.front().second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int xf = xi + row[i], yf = yi + col[i];
            if (xf < 0 || xf >= n || yf < 0 || yf >= n || grid[xf][yf] <= 0) continue;
            pq.push({xf, yf});
            grid[xf][yf] = fillValue;
        }
    }
}

int bfs2(vector<vector<int>>& grid)
{
    int n = grid.size();
    queue <pair <int, int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (grid[i][j] == 1) pq.push({i, j});
    }

    int ans = inf;
    while (!pq.empty()) {
        int xi = pq.front().first;
        int yi = pq.front().second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int xf = xi + row[i], yf = yi + col[i];
            if (xf < 0 || xf >= n || yf < 0 || yf >= n) continue;
            if (grid[xf][yf] == -1) {
                ans = min(ans, grid[xi][yi] - 1);
            }

            int cur = grid[xi][yi] + 1;
            if (grid[xf][yf] > cur) {
                grid[xf][yf] = cur;
                pq.push({xf, yf});
            }
        }
    }
    return ans;
}

int shortestBridge(vector<vector<int>>& grid)
{
    int n = grid.size();

    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                bfs(i, j, grid, -1);
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (grid[i][j] == 0) grid[i][j] = inf;
    }
    return bfs2(grid);
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    int ans = shortestBridge(grid);
    cout << ans << endl;

    return 0;
}