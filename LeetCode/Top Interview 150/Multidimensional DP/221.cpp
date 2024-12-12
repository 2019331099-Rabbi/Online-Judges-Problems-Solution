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

/*
Tutorial: www.youtube.com/watch?v=RElcqtFYTm0
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int memo[n + 1][m + 1];
        /*
        Each entry defines the size of square to the upword and left direction from this point.
        */

        int mxSq = 0;

        for (int i = 0; i <= n; i++) memo[i][0] = 0;
        for (int i = 0; i <= m; i++) memo[0][i] = 0;
        // first row and first column are filled with zeroes. They are out of bounds. We do this for our convenience.

        for (int i = 1; i < n; i++) {
            for (int j= 1; j < m; j++) {
                if (matrix[i - 1][j - 1] == '1') memo[i][j] = 1 + min({memo[i][j - 1], memo[i - 1][j - 1], memo[i - 1][j]});
                else memo[i][j] = 0;
                mxSq = max(mxSq, memo[i][j]);
            }
        }
        mxSq *= mxSq;
        return mxSq;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << soln->maximalSquare(matrix) << endl;

    return 0;
}