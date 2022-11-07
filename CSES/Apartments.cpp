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
    int n, m, k;

    cin >> n >> m >> k;
    vector <int> len(n), des(m);

    for (int i = 0; i < n; i++) cin >> len[i];
    for (int i = 0; i < m; i++) cin >> des[i];
    sort(des.begin(), des.end());

    int cnt = 0;

    if (!k) {
        for (auto xx: len) if (binary_search(des.begin(), des.end(), xx)) cnt++;
    }
    else {
        for (auto xx: len) {
            int lower = lower_bound(des.begin(), des.end(), xx - k + 1) - des.begin();
            int upper = upper_bound(des.begin(), des.end(), xx + k - 1) - des.begin();
            if (lower < upper) cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    solve();
    return 0;
}