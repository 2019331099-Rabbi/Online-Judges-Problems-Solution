#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    bool vis1[sz] = {false}, vis2[sz] = {false};
    int pref[n] = {0}, suff[n] = {0};

    for (int i = 0; i < n; i++) {
        int ch = s[i] - 'a';
        if (!vis1[ch]) pref[i] = 1, vis1[ch] = true;

        ch = s[n - i - 1] - 'a';
        if (!vis2[ch]) suff[n - i - 1] = 1, vis2[ch] = true;

        if (i) pref[i] += pref[i - 1], suff[n - i - 1] += suff[n - i];
    }

    // for (int i = 0; i < n; i++) cout << pref[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << suff[i] << ' ';
    // cout << endl;

    int mx = max(suff[0], pref[n - 1]);

    for (int i = 0; i < n - 1; i++) mx = max(mx, pref[i] + suff[i + 1]);
    cout << mx << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}