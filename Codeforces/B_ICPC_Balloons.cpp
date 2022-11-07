#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int len;
    string s;
    cin >> len >> s;
    bool vis[sz] = {false};
    
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (vis[s[i] - 'A']) cnt++;
        else {
            cnt += 2;
            vis[s[i] - 'A'] = true;
        }
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}