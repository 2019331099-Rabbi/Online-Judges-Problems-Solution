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
    int n;

    cin >> n;
    int64_t arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int64_t ans = LLONG_MAX, prev, tmp, cnt;
    for (int i = 0; i < n; i++) {
        prev = cnt = 0;
        for (int j = i + 1; j < n; j++) {
            tmp = prev + 1;
            tmp = (tmp % arr[j])?(tmp / arr[j] + 1):(tmp / arr[j]);
            prev = arr[j] * tmp;
            cnt += tmp;
        }
        prev = 0;
        for (int j = i - 1; j >= 0; j--) {
            tmp = prev + 1;
            tmp = (tmp % arr[j])?(tmp / arr[j] + 1):(tmp / arr[j]);
            prev = arr[j] * tmp;
            cnt += tmp;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    solve();
    return 0;
}