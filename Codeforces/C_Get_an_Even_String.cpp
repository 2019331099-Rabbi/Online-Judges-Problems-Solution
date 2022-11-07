#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

string s;
int letter[sz], nxt[200010], memo[200010];

int dp(int cur)
{
    if (cur == s.size()) return 0;
    if (cur > s.size()) return inf;
    if (memo[cur] != -1) return memo[cur];
    int cnt, ans;
    cnt = nxt[cur] - cur - 1;
    return memo[cur] = min(1 + dp(cur + 1), cnt + dp(nxt[cur] + 1));
}

void init()
{
    int len = s.size();
    for (int i = 0; i < sz; i++) letter[i] = len;

    for (int i = len - 1; i >= 0; i--) {
        nxt[i] = letter[s[i] - 'a'];
        letter[s[i] - 'a'] = i;
    }
    memset(memo, -1, sizeof(memo));
}

void solve()
{
    cin >> s;
    init();
    cout << dp(0) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}