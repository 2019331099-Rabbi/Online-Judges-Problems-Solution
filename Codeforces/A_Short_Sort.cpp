#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    string s;

    cin >> s;
    if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c') cout << "YES" << endl;
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