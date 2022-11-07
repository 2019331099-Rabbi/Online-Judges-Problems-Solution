#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n, k, r, c;

    cin >> n >> k >> r >> c;
    
    char ch[n + 1][n + 1];
    memset(ch, '.', sizeof(ch));
    ch[r][c] = 'X';

    while (r > 1 && c < n) r--, c++;
    int tmpr = r, tmpc = c;
    while (tmpr <= n && tmpc >= 1) {
        ch[tmpr][tmpc] = 'X';
        tmpr++, tmpc--;
    }
    tmpr = r, tmpc = c;
    while (tmpc > 1) {
        if (tmpr - k < 1) {
            tmpc += tmpr - 1;
            tmpc -= k;
            tmpr = 1;
        }
        else tmpr -= k;

        int x = tmpr, y = tmpc;
        while (x <= n && y >= 1) {
            ch[x][y] = 'X';
            x++, y--;
        }
    }

    tmpr = r, tmpc = c;
    while (tmpr < n) {
        if (tmpc + k > n) {
            tmpr += tmpc + k - n;
            tmpc = n;
        }
        else tmpc += k;

        int x = tmpr, y = tmpc;
        while (x <= n && y >= 1) {
            ch[x][y] = 'X';
            x++, y--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << ch[i][j];
        cout << endl;
    }
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}