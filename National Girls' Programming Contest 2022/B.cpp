#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

map <int64_t, int64_t> mp1;

void solve()
{
    int n, q;

    cin >> n >> q;
    while (q--) {
        int64_t type, a, b, val;
        cin >> type >> a >> b >> val;
        if (type == 2) val = -val;
        mp1[a] += val;
        mp1[b + 1] -= val;
    }
    auto it1 = mp1.begin(), it2 = mp1.begin();
    it2++;
    while (it2 != mp1.end()) {
        it2->second += it1->second;
        it1++, it2++;
    }
    
    // for (auto xx: mp1) cout << xx.first << ' ' << xx.second << endl;
    // cout << endl;

    map <int64_t, int64_t> mp2;
    it1 = mp1.begin(), it2 = mp1.begin();
    it2++;
    mp2[it1->first] = 0;
    auto it3 = mp2.begin();
    

    while (it2 != mp1.end()) {
    
        mp2[it2->first] = it3->second + (it2->first - it1->first) * it1->second;
        it1++, it2++, it3++;
    }
    // for (auto xx: mp2) cout << xx.first << ' ' << xx.second << endl;


    it1 = mp1.begin(), it2 = mp2.begin();
    int64_t mn = INT64_MAX;
    while (it1 != mp1.end()) {
        mn = min(mn, it1->second + it2->second);
        it1++, it2++;
    }
    if (mn <= 0) cout << abs(mn) + 1 << endl;
    else cout << 1 << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}