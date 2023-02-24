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
    int64_t l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (a == b) cout << 0 << endl;
    else if (abs(a - b) >= x) cout << 1 << endl;
    else {
        if (b > a && (b + x <= r || a - x >= l)) cout << 2 << endl;
        else if (b < a && (b - x >= l || a + x <= r)) cout << 2 << endl;
        else {
            if ((abs(l - b) < x) && (abs(r - b) < x) || (a + x > r && a - x < l)) cout << -1 << endl;
            else cout << 3 << endl;
        }
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