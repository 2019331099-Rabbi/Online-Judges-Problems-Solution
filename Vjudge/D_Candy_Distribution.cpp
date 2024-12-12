#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

map <int64_t, int64_t> mp;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t n, m, sum = 0;

    cin >> n >> m;
    for (int64_t i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        sum += val;
        sum %= m;
        mp[sum]++;
    }
    int64_t cnt = mp[0];

    for (auto it = mp.begin(); it != mp.end(); it++) {
        int64_t val = it->second;
        cnt += val * (val - 1) / 2;
    }
    cout << cnt << endl;
    return  0;
}