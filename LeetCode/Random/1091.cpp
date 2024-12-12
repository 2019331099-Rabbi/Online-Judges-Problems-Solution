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

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int n = grid.size();
    if ((grid[0][0] & 1) || (grid[n-1][n-1] & 1)) return -1;

    queue <pair <int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int xi = q.front().first, yi = q.front().second;
        if (xi == n-1 && yi == n-1) return grid[xi][yi] + 1;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xf = xi + row[i], yf = yi + col[i];
            if (xf < 0 || xf >= n || yf < 0 || yf >= n || grid[xf][yf]) continue;
            grid[xf][yf] = grid[xi][yi] + 1;
            q.push({xf, yf});
        } 
    }
    return -1;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    auto result = shortestPathBinaryMatrix(grid);
    cout << result << endl;


}