#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;
    
    cin >> n;
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) cin >> arr[i][j];
    }
    int fval = arr[0][0], lval = arr[0][n - 2];
    if (arr[1][0] == arr[2][0]) fval = arr[1][0];
    if (arr[1][n - 2] == arr[2][n - 2]) lval = arr[1][n - 2];

    int ans[n];
    ans[0] = fval, ans[n - 1] = lval;

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == fval && arr[i][n - 2] != lval) {
            for (int j = 1; j < n - 1; j++) ans[j] = arr[i][j];
            break;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}