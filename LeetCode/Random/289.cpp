#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector <vector <int>> newBoard = board;

        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int xf = i + row[k];
                    int yf = j + col[k];
                    if (xf >= 0 && xf < r && yf >= 0 && yf < c) {
                        if (board[xf][yf]) live++;
                    }
                }
                if (board[i][j] && (live < 2 || live > 3)) newBoard[i][j] = 0;
                else if (!board[i][j] && live == 3) newBoard[i][j] = 1;
            }
        }
        board = newBoard;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    soln->gameOfLife(board);

    for (auto xx: board) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }

}