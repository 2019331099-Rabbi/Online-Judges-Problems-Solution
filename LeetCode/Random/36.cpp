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
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            int checker = 0;
            for (int j = 0; j < 9; j++) {
                if (isalnum(board[i][j])) {
                    int x = 1 << (board[i][j] - '0');
                    if (checker & x) return false;
                    checker |= x;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            int checker = 0;
            for (int j = 0; j < 9; j++) {
                if (isalnum(board[j][i])) {
                    int x = 1 << (board[j][i] - '0');
                    if (checker & x) return false;
                    checker |= x;
                }
            }
        }
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                int checker = 0;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (isalnum(board[i + k][j + l])) {
                            int x = 1 << (board[i + k][j + l] - '0');
                            if (checker & x) return false;
                            checker |= x;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<char>> board = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};

    cout << soln->isValidSudoku(board) << endl;
}