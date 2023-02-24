#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    int n;

    cin >> n;
    vector <string> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];

    if (n < 2) {
        cout << "Grandma" << endl;
        return;
    }

    bool vis[n + 4];
    for (int i = 0; i < n; i++) vis[i] = true;

    vector <int> seq;
    int prev = 0, cnt = 0;
    for (int i = 1; i < n; i++) {
        if ((v[0][i] == 'O' && v[0][i - 1] == 'O' && v[1][i] == 'O' && v[1][i - 1] == 'O') ||
            (v[1][i] == 'O' && v[1][i - 1] == 'O' && v[2][i] == 'O' && v[2][i - 1] == 'O')) cnt += 2, i++;
        else {
            if (cnt > 1) seq.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt > 1) seq.push_back(cnt);

    // for (auto xx: seq) cout << xx << ' ';
    // cout << endl;

    bool winner = true;
    for (int i = 2; i <= n; i += 3) {
        vis[i] = vis[i + 1] = vis[i + 2] = winner;
        winner = !winner;
    }
    cout << "Case " << T << ": ";
    bool turn = true;

    for (auto xx: seq) {
         if (turn && vis[xx]) turn = false;
         else if (turn && !vis[xx]) turn = true;
         else if (!turn && vis[xx]) turn = true;
         else turn = false;
    }
    if (turn) cout << "Grandma" << endl;
    else cout << "Jhinuk" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}