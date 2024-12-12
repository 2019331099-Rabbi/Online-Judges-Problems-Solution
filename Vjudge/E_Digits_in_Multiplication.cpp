#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 100000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int nodigits(int64_t n)
{
    int cnt = 0;
    while (n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t n;

    cin >> n;

    int mn = 10000;

    for (int64_t i = 1; i*i <= n; i++) {
        if (n % i) continue;
        int d1 = nodigits(i);
        int d2 = nodigits(n / i);

        mn = min(mn, max(d1, d2));
    }

    cout << mn << endl;
}