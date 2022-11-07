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
    string s;

    cin >> s;
    int ans =  abs(s[0] - s[s.size() - 1]);

    char c1 = s[0], c2 = s[s.size() - 1];

    if (c1 > c2) swap(c1, c2);
    map <int, vector <int>> mp;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        int tmp = s[i] - 'a';
        if (s[i] >= c1 && s[i] <= c2) mp[tmp].push_back(i + 1), cnt++;
    }
    cout << ans << ' ' << cnt << endl;
    if (s[0] < s[s.size() - 1]) {
        for (auto xx: mp[s[0] - 'a']) cout << xx << ' ';

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->first == s[0] - 'a' || it->first == s[s.size() - 1] - 'a') continue;
            for (auto xx: it->second) cout << xx << ' ';
        }
        if (s[0] != s[s.size() - 1]) for (auto xx: mp[s[s.size() - 1] - 'a']) cout << xx << ' ';
        cout << endl;
    }
    else {
        for (auto xx: mp[s[0] - 'a']) cout << xx << ' ';
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            if (it->first == s[0] - 'a' || it->first == s[s.size() - 1] - 'a') continue;
            for (auto xx: it->second) cout << xx << ' ';
        }
        if (s[0] != s[s.size() - 1]) for (auto xx: mp[s[s.size() - 1] - 'a']) cout << xx << ' ';
        cout << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}