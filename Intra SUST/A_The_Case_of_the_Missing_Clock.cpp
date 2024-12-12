#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

map <double, pair <int, int>> mp;

void init()
{
    for (int i = 1; i <= 12; i++) {
        for (int j = 0; j < 60; j++)
    }
}

void solve()
{
    string s;

    cin >> s;

    string tmp1 = "", tmp2 = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') break;
        tmp1 += s[i];
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '.') break;
        tmp2 += s[i];
    }
    reverse(tmp2.begin(), tmp2.end());

    int deg1 = stoi(tmp1), deg2 = stoi(tmp2);
    double ans = deg1 + deg2 / 10.0;
    
    
    auto pr = mp[ans];

    string hr, min;
    if (pr.first < 10) cout << 0;
    cout << pr.first;
    cout << ':';

    if (pr.second < 10) cout << 0;
    cout << pr.second << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    for (auto xx: mp) cout << xx.first << ' ' << xx.second.first << ' ' << xx.second.second << endl;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}