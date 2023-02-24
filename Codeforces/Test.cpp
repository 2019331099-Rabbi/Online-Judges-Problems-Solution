#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <string> board(3);

bool who_wins() {
    int n = board.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] == '0' && board[i][j + 1] == '0' && board[i + 1][j] == '0' && board[i + 1][j + 1] == '0') {
                board[i][j] = board[i][j + 1] = board[i + 1][j] = board[i + 1][j + 1] = '1';
                if (!who_wins()) {
                    return true;
                }
                board[i][j] = board[i][j + 1] = board[i + 1][j] = board[i + 1][j + 1] = '0';
            }
        }
    }
    return false;
}

void solve(int T)
{
    int n;

    cin >> n;
    ;
    for (int i = 0; i < 3; i++) cin >> board[i];

    if (who_wins()) cout << "Jhinuk" << endl;
    else cout << "Grandma" << endl;

    board.clear();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}