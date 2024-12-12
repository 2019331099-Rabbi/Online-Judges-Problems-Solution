#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e8 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int len = board.size();
        int totSq = len * len;

        queue <pair <int, int>> q;
        vector <int> vis(totSq + 1, INT32_MAX);
        
        q.push({1, 1});
        vis[1] = 1;

        while (!q.empty()) {
            int u = q.front().first;
            int cnt = q.front().second;
            q.pop();

            for (int i = 1; i <= 6; i++) {
                int v = u + i;
                if (v > totSq) continue;

                int r = (v - 1) / len;
                int c = (v - 1) % len;
                if (r & 1) c = len - c - 1;
                r = len - r - 1;
                v = (board[r][c] == -1)?v:board[r][c];

                if (vis[v] > cnt + 1) {
                    vis[v] = cnt + 1;
                    q.push({v, cnt + 1});
                }
            }
        }
        if (vis[totSq] == INT32_MAX) return -1;
        return vis[totSq] - 1;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };

    cout << soln->snakesAndLadders(board) << endl;

}