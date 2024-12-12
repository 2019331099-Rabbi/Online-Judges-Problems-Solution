#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


void solve(int T)
{
    int n, k;
    string s;

    cin >> n >> k >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') i += k - 1, cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}