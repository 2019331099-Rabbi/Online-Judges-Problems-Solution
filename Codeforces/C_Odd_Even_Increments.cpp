                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n, cnt1o = 0, cnt1e = 0, cnt2o = 0, cnt2e = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (i & 1) {
            if (val & 1) cnt1o++;
            else cnt1e++;
        }
        else {
            if (val & 1) cnt2o++;
            else cnt2e++;
        }
    }
    if ((cnt1e == 0 || cnt1o ==0) && (cnt2e == 0 || cnt2o ==0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}