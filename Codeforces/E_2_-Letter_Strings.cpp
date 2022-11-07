                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

map <string, int> occ;
map <char, int> focc, socc;
vector <string> v;

int64_t numberOfPair()
{
    int64_t ans = 0;
    for (auto xx: v) {
        int64_t x = focc[xx[0]] - occ[xx];
        ans += x;

        x = socc[xx[1]] - occ[xx];
        ans += x;

        occ[xx]--, focc[xx[0]]--, socc[xx[1]]--;
    }
    return ans;
}

void solve()
{
    
    string s;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
        occ[s]++;
        focc[s[0]]++;
        socc[s[1]]++;
    }
    int64_t ans = numberOfPair();
    cout << ans << endl;

    occ.clear(), focc.clear(), socc.clear(), v.clear();
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}