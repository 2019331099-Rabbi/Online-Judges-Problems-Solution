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

// int countNegatives(vector<vector<int>>& grid)
// {
//     int cnt = 0;
//     for (auto xx: grid) {
//         auto it = upper_bound(xx.begin(), xx.end(), 0, greater <int>());
//         cnt += xx.end() - it;
//     }
//     return cnt;
// }


int countNegatives(vector<vector<int>>& grid)
{
    int cnt = 0;
    for (auto xx: grid) {
        int l = 0, r = grid[0].size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (0 <= xx[mid]) l = mid + 1;
            else r = mid - 1;
        }
        cnt += (grid[0].size() - l);
    }
    return cnt;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {3, 2},
        {1, 0},
    };

    cout << countNegatives(grid);
    return 0;

}