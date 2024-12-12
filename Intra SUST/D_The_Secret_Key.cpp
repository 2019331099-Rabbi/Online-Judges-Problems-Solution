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
    int a, b, m1, m2;

    cin >> a >> b >> m1 >> m2;

    int val1 = a + m1;
    int val2 = b + m2;

    map <int, int> mp;

    for (int i = 1; i * i <= val1; i++) {
        if (val1 % i == 0) {
            mp[i]++;
            if (val1 / i != i) mp[val1 / i]++;
            
        }
    }
    for (auto xx: mp) {
        if (a % xx.first != m1) mp[xx.first]--;
    }
    for (int i = 1; i * i <= val2; i++) {
        if (val2 % i == 0) {
            mp[i]++;
            if(val2 / i != i) mp[val2 / i]++;
        }
    }
    for (auto xx: mp) {
        if (b % xx.first != m2) mp[xx.first]--;
    }

    if (m1 || m2) mp[1] = 0;
    int ans = -1;
    for (auto xx: mp) {
        if (xx.second == 2) {
            ans = xx.first;
            break;
        }
    }
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