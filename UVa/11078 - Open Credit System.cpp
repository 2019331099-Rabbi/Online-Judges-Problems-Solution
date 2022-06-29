#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100000
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, n, i, mx, ans2, ans1, tmp, val;
    cin >> T;
    while (T--) {
        cin >> n >> val;
        ans2=ans1=-1e9;
        mx=val;
        for (i=1; i<n; i++) {
            cin >> tmp;
            mx=max(mx, tmp);
            ans1=max(ans1, mx-tmp);
            ans2=max(ans2, val-tmp);
            val=tmp;
        }
        if (ans1) cout << ans1 << endl;
        else cout << ans2 << endl;
    }
    return 0;
}
