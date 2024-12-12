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

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set <int> rows, cols;
        int r = matrix.size(), c = matrix[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) if (!matrix[i][j]) {
                rows.insert(i);
                cols.insert(j);
            }
        }
        for (int row: rows) {
            for (int i = 0; i < c; i++) matrix[row][i] = 0;
        }

        for (int col: cols) {
            for (int i = 0; i < r; i++) matrix[i][col] = 0;
        }
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<int>> matrix = {
    {0, 1, 2, 0},
    {3, 4, 5, 2},
    {1, 3, 1, 5}
};

    soln->setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (auto xx: matrix[i]) cout << xx << ' ';
        cout << endl;
    }
}