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
    int64_t sum = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') sum += i;
        else sum += (n - i - 1);
    }
    vector <int64_t> ans;
    if (n & 1) {
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == 'L') {
                int64_t tmp = - i + (n - i - 1);
                ans.push_back(tmp);
            }
        }
        for (int i = n / 2 + 1; i < n; i++) {
            if (s[i] == 'R') {
                int64_t tmp = -n + 1 + 2 * i;
                ans.push_back(tmp);
            }
        }
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == 'L') {
                int64_t tmp = - i + (n - i - 1);
                ans.push_back(tmp);
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (s[i] == 'R') {
                int64_t tmp = -n + 1 + 2 * i;
                ans.push_back(tmp);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());

    for (int i = 0; i < n; i++) {
        if (i < ans.size()) {
            sum += ans[i];
            cout << sum << ' ';
        }
        else cout << sum << ' ';
    }
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