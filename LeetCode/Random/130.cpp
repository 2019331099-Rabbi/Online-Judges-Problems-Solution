#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

int row[] = {0, 0, -1, 1};
int col[] = {1, -1, 0, 0};


class Solution {
public:
    void bfs(vector<vector<char>>& board, int xi, int yi)
    {
        int r = board.size(), c = board[0].size();
        queue <pair <int, int>> q;

        q.push({xi, yi});
        board[xi][yi] = 'H';
        while (!q.empty()) {
            xi = q.front().first;
            yi = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xf = xi + row[i];
                int yf = yi + col[i];
                if (xf < 0 || xf >= r || yf < 0 || yf >= c || board[xf][yf] == 'X' || board[xf][yf] == 'H') continue;
                q.push({xf, yf});
                board[xf][yf] = 'H';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();

        for (int i = 0; i < c; i++) {
            if (board[0][i] == 'O') bfs(board, 0, i);
        }
        for (int i = 1; i < r; i++) {
            if (board[i][c - 1] == 'O') bfs(board, i, c - 1);
        }
        for (int i = c - 2; i >= 0; i--) {
            if (board[r - 1][i] == 'O') bfs(board, r - 1, i);
        }
        for (int i = r - 2; i >= 1; i--) {
            if (board[i][0] == 'O') bfs(board, i, 0);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'H') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'O', 'X'}
    };

    soln->solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (auto xx: board[i]) cout << xx << ' ';
        cout << endl;
    }

    return 0;



}