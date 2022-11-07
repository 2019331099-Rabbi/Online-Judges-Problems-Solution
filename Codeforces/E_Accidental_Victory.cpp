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
    int64_t n;

    cin >> n;
    vector <int64_t> v(n), v1(n), v2(n);

    for (int64_t i = 0; i < n; i++) {
        cin >> v[i];
        v1[i] = v[i];
    }
    sort(v1.begin(), v1.end());
    for (int64_t i = 0; i < n; i++) v2[i] = v1[i];
    for (int64_t i = 1; i < n; i++) v1[i] += v1[i - 1];

    int64_t val = -1;
    for (int64_t i = n - 2; i >= 0; i--) {
        if (v1[i] < v2[i + 1]) break;
        val = v2[i];
    }
    if (val == -1) val = v2[n - 1];
    v1.clear();
    for (int64_t i = 0; i < n; i++) if (v[i] >= val) v1.push_back(i + 1);

    cout << v1.size() << endl;
    for (auto xx: v1) cout << xx << ' ';
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