#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n;
string s;

bool check()
{
    vector <int> pos[sz];

    for (int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
    

    for (int i = 0; i < sz; i++) {
        if (pos[i].size()) {
            int cnt = 0;
            for (auto xx: pos[i]) if (xx & 1) cnt++;
            if (cnt == 0 || cnt == pos[i].size()) continue;
            return false;
        }
    }
    return true;
}

void solve(int T)
{
    cin >> n >> s;
    if (check()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}