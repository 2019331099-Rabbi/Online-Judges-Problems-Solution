#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

set <int> st;
map <int, int> mp;


void solve()
{
    int n, m;

    cin >> n >> m;
    

    while (n--) {
        int val;
        cin >> val;
        st.insert(val);
        mp[val]++;
    }

    while (m--) {
        int val;
        cin >> val;
        if (!st.size()) {
            cout << -1 << endl;
            continue;
        }

        auto it = --st.end();
        if (val >= *it) {
            cout << *it << endl;
            mp[*it]--;
            if (!mp[*it]) st.erase(*it);
        }
        else {
            it = st.lower_bound(val);
            if (*it <= val) {
                cout << *it << endl;
                mp[*it]--;
                if (!mp[*it]) st.erase(it);
            }
            else if (it == st.begin()) cout << -1 << endl;
            else {
                it--;
                cout << *it << endl;
                mp[*it]--;
                if (!mp[*it]) st.erase(it);
            }
        }
    }
    // for (auto xx: st) cout << xx << ' ';
    // cout << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}