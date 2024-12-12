#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int64_t T)
{
    int64_t n, mx = -1;
    vector <pair <int64_t, int64_t>> vpr;

    cin >> n;
    for (int64_t i = 0; i < n; i++) {
        int64_t h, t;
        cin >> h >> t;
        mx = max(mx, t);

        vpr.push_back({h, t});

    }

    sort(vpr.rbegin(), vpr.rend());
    vector <int64_t> order(n);

    bool flag = true;

    if (mx <= n - 1) {
        for (int64_t i = 0; i < n; i++) {
            if (vpr[i].second < i) {
                flag = false;
                break;
            }
            order[vpr[i].second] = vpr[i].first;
        }
    }
    
    cout << "Case " << T << ":";
    if (flag && mx <= n - 1) {
        for (int64_t i = 0; i < n; i++) cout << ' ' << order[i];

        cout << endl;
    }
    else cout << " No ordering possible!" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    for (int64_t i = 1; i <= T; i++) solve(i);
    return 0;
}

