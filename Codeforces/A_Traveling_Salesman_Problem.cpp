#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n, xl, xr, yu, yd;
    xl = yd = inf;
    xr = yu = -inf;
    
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x) {
            if (x >= 0) xr = max(xr, x);
            else xl = min(xl, x);
        }
        else {
            if (y >= 0) yu = max(yu, y);
            else yd = min(yd, y);
        }
    }
    int ans = 0;
    if (xl != inf) ans += (-xl * 2);
    if (xr != -inf) ans += xr * 2;

    if (yd != inf) ans += (-yd * 2);
    if (yu != -inf) ans += yu * 2;
    
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