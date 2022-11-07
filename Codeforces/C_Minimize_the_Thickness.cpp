#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 200000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board


int64_t thickness(vector <int64_t> v, int64_t n, int64_t sum)
{
    int64_t tmp = 0, cnt = 0, ans = -inf;
    for (int64_t i = 0; i < n; i++) {
        tmp += v[i];
        cnt++;
        if (tmp > sum) return inf;
        if (tmp == sum) {
            ans = max(cnt, ans);
            tmp = 0;
            cnt = 0;
        }
    }
    return ans;
}


void solve()
{
    int64_t n;

    cin >> n;
    vector <int64_t> v(n);

    int64_t sum = 0;
    for (auto &xx: v) {
        cin >> xx;
        sum += xx;
    }

    int64_t ans = inf;
    for (int64_t i = n; i >= 1; i--) {
        if (sum % i) continue;
        ans = min(ans, thickness(v, n, sum / i));
    }
    cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0; 
}