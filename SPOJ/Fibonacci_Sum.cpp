#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000000010
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t a, b, memo[sz];

int64_t fibo(int64_t n)
{
    if (n < 2) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = (fibo(n - 1) % mod + fibo(n -2) % mod) % mod;
}


void init()
{
    memset(memo, -1, sizeof memo);
}

void solve()
{
    cin >> a >> b;
    int64_t sum = 0;
    for (int64_t i = a; i <= b; i++) sum = (sum + fibo(i)) % mod;
    cout << sum << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}