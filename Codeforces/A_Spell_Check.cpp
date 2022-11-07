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
    int n;

    cin >> n >> s;

    sort(s.begin(), s.end());
    if (s == "Timru") cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}