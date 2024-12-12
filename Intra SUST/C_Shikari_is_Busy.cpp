#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int64_t n, x;

    cin >> n >> x;
    
    
    int64_t sum = 0;
    if (x > n) {
        sum = n * (n + 1) / 2;
        cout << sum << endl;
    }
    else {
        int64_t tmp = n / x;
        int64_t tmps = x * (x - 1) / 2;
        sum += tmps * tmp;
        tmp = n % x;
        sum += tmp * (tmp + 1) / 2;

        cout << sum << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}