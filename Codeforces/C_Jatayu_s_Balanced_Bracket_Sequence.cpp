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
    int n;
    string s;

    cin >> n >> s;
    n += n;

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') cnt++;
        else {
            if (cnt) ans += (cnt - 1);
            cnt = 0;
        }
    }
    cout << ans + 1 << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}