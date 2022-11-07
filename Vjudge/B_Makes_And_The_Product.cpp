#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000001
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t vis[sz];

void solve()
{
    int64_t n;

    cin >> n;
    vector <int64_t> v(n);
    for (auto &xx: v) cin >> xx;
    sort(v.begin(), v.end());

    int64_t a = v[0], b = v[1], c = v[2];
    //cout << a << ' ' << b << ' ' << c << endl;

    if (a == b && b == c) {
        int64_t cnt = 0;
        for (auto xx: v) if (xx == a) cnt++;
        int64_t ans = (cnt * (cnt - 1) * (cnt - 2)) / 6;
        cout << ans << endl;
    }
    else if (a == b) {
        int64_t cnta = 0, cntc = 0;
        for (auto xx: v) {
            if (xx == a) cnta++;
            else if (xx == c) cntc++;
        }
        int64_t ans = (cnta * (cnta - 1)) / 2;
        ans *= cntc;
        cout << ans << endl;
    }
    else if (b == c) {
        int64_t cnta = 0, cntc = 0;
        for (auto xx: v) {
            if (xx == a) cnta++;
            else if (xx == c) cntc++;
        }
        int64_t ans = cnta;
        ans *= (cntc * (cntc - 1)) / 2;
        cout << ans << endl;
    }
    else {

        int64_t cnta = 0, cntb = 0, cntc = 0;
        for (auto xx: v) {
            if (xx == a) cnta++;
            else if (xx == b) cntb++;
            else if (xx == c) cntc++;
            
        }

        int64_t ans = cnta * cntb * cntc;
        cout << ans << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    solve();
}