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

    cin >> n;
    map <int, int> mp1, mp2;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        mp1[val]++;
    }
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (mp1[val]) mp1[val]--;
        else mp2[val]++;
    }
    vector <int> v1, v2;
    for (auto xx: mp1) {
        int len = xx.second;
        int val = xx.first;
        for (int i = 0; i < len; i++) v1.push_back(val);
    }
    for (auto xx: mp2) {
        int len = xx.second;
        int val = xx.first;
        for (int i = 0; i < len; i++) v2.push_back(val);
    }
    // cout << "---------" << endl;
    // for (auto xx: v1) cout << xx << ' ';
    // cout << endl;
    // for (auto xx: v2) cout << xx << ' ';
    // cout << endl;
    // cout << "---------" << endl;

    mp1.clear();
    mp2.clear();

    for (auto xx: v1) mp1[xx]++;
    for (auto xx: v2) mp2[xx]++;

    // cout << "map------" << endl;
    // for (auto xx: mp1) cout << xx.first << ' ' << xx.second << endl;
    // cout << endl;
    // for (auto xx: mp2) cout << xx.first << ' ' << xx.second << endl;
    // cout << "-----------" << endl;

    int cnt = 0;

    for (auto xx: mp1) {
        int val = xx.first;
        if (val < 10) continue;
        int occ1 = xx.second;

        int len = to_string(val).size();
        int occ2 = mp2[len];
        
        mp1[len] = mp1[len] + occ1;
        mp1[val] = 0;
        if (occ2) {
            if (occ1 > occ2) mp1[len] -= occ2, mp2[len] = 0;
            else mp1[len] = 0, mp2[len] = occ2 - occ1;
        }
        cnt += occ1;
    }

    for (auto xx: mp2) {
        int val = xx.first;
        int occ2 = xx.second;
        if (!occ2) continue;
        int occ1 = mp1[val];

        if (occ1) {
            if (occ2 > occ1) mp2[val] -= occ1, mp1[val] = 0;
            else mp2[val] = 0, mp1[val] = occ1 - occ2;
        }
        else if (val > 1) {
            int len = to_string(val).size();
            mp2[len] = mp2[len] + occ2;
            mp2[val] = 0;
            occ1 = mp1[len];
            if (occ1) {
                if (occ2 > occ1) mp2[len] -= occ1, mp1[len] = 0;
                else mp2[len] = 0, mp1[len] = occ1 - occ2;
            }
            cnt += occ2;
        }
    }
    v1.clear(), v2.clear();
    for (auto xx: mp1) {
        int len = xx.second;
        int val = xx.first;

        if (val > 1) for (int i = 0; i < len; i++) v1.push_back(val);
    }
    for (auto xx: mp2) {
        int len = xx.second;
        int val = xx.first;
        if (val > 1) for (int i = 0; i < len; i++) v2.push_back(val);
    }
    // cout << "---------" << endl;
    // for (auto xx: v1) cout << xx << ' ';
    // cout << endl;
    // for (auto xx: v2) cout << xx << ' ';
    // cout << endl;
    // cout << "---------" << endl;

    cnt += v1.size();
    cnt += v2.size();
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}