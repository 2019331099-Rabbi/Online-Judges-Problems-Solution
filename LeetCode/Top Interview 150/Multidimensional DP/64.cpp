#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

// class Solution {
// public:
//     int memo[201][201];
//     Solution() {
//         memset(memo, -1, sizeof(memo));
//     }
//     int dp(int xi, int yi, vector <vector <int>> &grid) {
//         if (xi == grid.size() - 1 && yi == grid[0].size() - 1) return grid[xi][yi];
//         if (xi >= grid.size() || yi >= grid[0].size()) return inf;
//         if (memo[xi][yi] != -1) return memo[xi][yi];

//         int cost1 = dp(xi, yi + 1, grid);
//         int cost2 = dp(xi + 1, yi, grid);
//         return memo[xi][yi] = grid[xi][yi] + min(cost1, cost2);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         return dp(0, 0, grid);
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <int>> memo(n, vector <int>(m, INT32_MAX));

        memo[0][0] = grid[0][0];
        int xi = 0, yi = 0;

        while (!(xi == n - 1 && yi == m - 1)) {
            int i = xi, j = yi;
            while (i >= 0 && j < m) {
                if (i + 1 < n) memo[i + 1][j] = min(memo[i + 1][j], memo[i][j] + grid[i + 1][j]);
                if (j + 1 < m) memo[i][j + 1] = min(memo[i][j + 1], memo[i][j] + grid[i][j + 1]);
                i--, j++;
            }
            if (xi == n - 1) yi++;
            else xi++;
            
        }
        return memo[n - 1][m - 1];
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << soln->minPathSum(grid) << endl;
    return 0;
}