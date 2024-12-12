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

int shortestPathAllKeys(vector <string>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int allKeys = 0;
    pair <int, int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '@') start = {i, j};
            else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                allKeys |= (1 << (grid[i][j] - 'a'));
            }
        }
    }

    queue <tuple <int, int, int, int>> q;
    unordered_set <string> visited;
    q.push({start.first, start.second, 0, 0});
    visited.insert(to_string(start.first) + ',' + to_string(start.second) + ",0");

    while (!q.empty()) {
        int xi, yi, moves, keys;
        tie(xi, yi, moves, keys) = q.front();
        q.pop();

        if (keys == allKeys) return moves;
        
        for (int i = 0; i < 4; i++) {
            int newKeys = keys;
            int xf = xi + row[i];
            int yf = yi + col[i];
            if (xf < 0 || xf >= n || yf < 0 || yf >= m || grid[xf][yf] == '#') continue;

            char ch = grid[xf][yf];
            if (ch >= 'a' && ch <= 'z') newKeys |= (1 << (ch - 'a'));
            else if (ch >= 'A' && ch <= 'Z' && !(keys & (1 << (ch - 'A')))) continue;

            string state = to_string(xf) + ',' + to_string(yf) + ',' + to_string(newKeys);
            if (visited.find(state) != visited.end()) continue;
            q.push({xf, yf, moves + 1, newKeys});
            visited.insert(state);
        }
    }
    return -1;
}


/*
  0 1 2 3 4
0 . . . # .
1 a . . @ .
2 # . . # .
3 b . # B .
4 . # # . A

*/

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector <string> grid = {"...#.","a..@.","#..#.","b.#B.",".##.A"};

    cout << shortestPathAllKeys(grid) << endl;

    return 0;

}