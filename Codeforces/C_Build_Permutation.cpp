#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int64_t n;

    cin >> n;
    n--;
    vector <int> ans(n + 1, 0);

    int val = 0;
    while (val * val < n) val++;
    
    int left = n + 1, tmpleft = n;
    int i = n;
    while (i >= 0) {
        int tmp = val * val - i;
        tmpleft = min(tmpleft, tmp);
        if (tmp <= n && tmp < left) ans[i] = tmp, i--;
        else {
            val--;
            left = tmpleft;
        }
    }
    for (auto xx: ans) cout << xx << ' ';
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