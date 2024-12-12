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
    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size(), m = board[0].size();

        function <bool (int, int, int)> dfs = [&](int xi, int yi, int pos)
        {
            if (pos == word.size()) return true;
            if (xi >= n || xi < 0 || yi >= m || yi < 0 || board[xi][yi] != word[pos]) return false;

            char tmp = board[xi][yi];
            board[xi][yi] = '@';
            if (dfs(xi, yi + 1, pos + 1) || dfs(xi, yi - 1, pos + 1) || dfs(xi + 1, yi, pos + 1) || dfs(xi - 1, yi, pos + 1)) return true;
            board[xi][yi] = tmp;

            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool flag = dfs(i, j, 0);
                if (flag) return true;
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'B', 'D', 'E', 'A'}
    };
    string word = "ABCESEEEFS";
    cout << soln->exist(board, word) << endl;

}