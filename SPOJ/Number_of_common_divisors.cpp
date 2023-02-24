#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 50000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int numOfDiv(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (n / i != i) cnt++;
        }
    }
    return cnt;
}

void solve(int T)
{
    int a, b;

    cin >> a >> b;
    cout << numOfDiv(__gcd(a, b)) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}