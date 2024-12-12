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

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
{
    int n = maze.size(), m = maze[0].size();
    int sx = entrance[0], sy = entrance[1];

    int dis[n][m];
    memset(dis, 0, sizeof(dis));

    queue <pair <int, int>> q;
    q.push({sx, sy});
    dis[sx][sy] = 1;

    int ans = inf;

    while (!q.empty()) {
        int xi = q.front().first;
        int yi = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xf = xi + row[i], yf = yi + col[i];
            if (xf < 0 || xf >= n || yf < 0 || yf >= m || maze[xf][yf] == '#' || dis[xf][yf]) continue;
            q.push({xf, yf});
            dis[xf][yf] = dis[xi][yi] + 1;
            if (xf == 0 || xf == n-1 || yf == 0 || yf == m-1) ans = min(ans, dis[xf][yf]);
        }
    }

    return ans;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr); 

    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };
    vector <int> entrance = {1, 2};
    int ans = nearestExit(maze, entrance);
    cout << ans << endl;


    return 0;
}