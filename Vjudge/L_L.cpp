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
    int64_t n, k;
    vector <int64_t> v;

    cin >> n >> k;

    for (int64_t i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());
    // for (auto xx: v) cout << xx << ' ';
    // cout << endl;


    int64_t sum = 0;
    for (int64_t i = 0; i < k - 1; i++) sum += v[i];


    bool flag = false;

    for (int64_t i = k - 1; i < n; i++) {
        if (sum > v[i]) {
            flag = true;
            break;
        }
        sum -= v[i - k + 1];
        sum += v[i];
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T = 1;
    // cin >> T;
    for (int64_t i = 1; i <= T; i++) solve(i);
    return 0;
}