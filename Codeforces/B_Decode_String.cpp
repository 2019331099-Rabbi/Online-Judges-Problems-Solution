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
    int i = n - 1;

    string ans = "";
    while (i >= 0) {
        if (s[i] == '0') {
            int tmp = s[i - 1] - '0' + (s[i - 2] - '0') * 10;
            ans += ('a' + (tmp - 1));
            i -= 3;
        }
        else ans += ('a' + (s[i] - '0' - 1)), i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}