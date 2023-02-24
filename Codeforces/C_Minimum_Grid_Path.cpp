#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
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
    int n;
    
    cin >> n;
    int64_t arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int64_t mn0, mn1, sum0, sum1, ans;
    mn0 = sum0 = arr[0], mn1 = sum1 = arr[1];
    ans = n * (mn0 + mn1);

    for (int i = 2; i < n; i++) {
        if (i & 1) sum1 += arr[i], mn1 = min(mn1, arr[i]);
        else sum0 += arr[i], mn0 = min(mn0, arr[i]);

        // cout << i << endl;
        // cout << sum0 << ' ' << mn0 << ' ' << sum1 << ' ' << mn1 << endl;

        int64_t cnt0 = (i + 2) / 2;
        int64_t cnt1 = (i + 1) - cnt0;
        //cout << cnt0 << ' ' << cnt1 << endl;

        int64_t tmp = (sum0 - mn0) + mn0 * (n - cnt0 + 1) + (sum1 - mn1) + mn1 * (n - cnt1 + 1);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}