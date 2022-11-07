#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n;
map <string, int> mp;
vector <string> v;

void solve()
{
    string s1, s2;
    int len;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s1;
        v.push_back(s1);
        mp[s1] = 1;
    }

    int ans[n] = {0};

    for (int i = 0; i < n; i++) {
        len = v[i].size();
        s1 = "";
        for (int j = 0; j < len - 1; j++) {
            s1 += v[i][j];
            s2 = v[i].substr(j + 1, len - j - 1);
            if (mp[s1] && mp[s2]) ans[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i];
    cout << endl;

    v.clear();
    mp.clear();
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}