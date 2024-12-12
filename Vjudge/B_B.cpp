#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define neg cout << -1 << endl;
#define ff first
#define ss second

const int mod = 1e9 + 7;
const int md = 998244353;
const int INF = 1e18;
const int N = 1e5;


int lcm(int i, int j)
{
    return i / __gcd(i, j) * j;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    vector<int> va, vb;
    for (int i = 1; i * i <= a[1]; ++i)
    {
        if (a[1] % i == 0) va.push_back(i), va.push_back(a[1] / i);
    }
    for (int i = 1; i * i <= b[1]; ++i)
    {
        if (b[1] % i == 0) vb.push_back(i), vb.push_back(b[1] / i);
    }

    int ans = 0;
    for (auto i : va)
    {
        for (auto j : vb)
        {
            bool flag = true;
            for (int k = 2; k <= n; ++k)
            {
                if (!((a[k] % i == 0 && b[k] % j == 0) || (a[k] % j == 0 && b[k] % i == 0)))
                {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = max(ans, lcm(i, j));
        }
    }

    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;

    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }

    return 0;
}
