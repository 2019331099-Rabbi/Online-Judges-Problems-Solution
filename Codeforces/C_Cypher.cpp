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
    int n, moves;
    string s;

    cin >> n;
    int digits[n];
    for (int i = 0; i < n; i++) cin >> digits[i];

    for (int i = 0; i < n; i++) {
        cin >> moves >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'U') {
                digits[i]--;
                if (digits[i] < 0) digits[i] = 9;
            }
            else {
                digits[i]++;
                if (digits[i] > 9) digits[i] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << digits[i] << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}