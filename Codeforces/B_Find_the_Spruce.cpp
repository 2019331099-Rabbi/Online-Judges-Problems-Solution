                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


void solve()
{
    int n, m;
    string s;
    vector <string> v;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }

    int spruce[n + 1][m + 1];
    memset(spruce, 0, sizeof(spruce));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (v[i][j] == '*') spruce[i][j] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 1; j--) {
            if (spruce[i][j])
                spruce[i][j] = 1 + min({spruce[i + 1][j - 1], spruce[i + 1][j], spruce[i + 1][j + 1]});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans += spruce[i][j];
    }
    cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}