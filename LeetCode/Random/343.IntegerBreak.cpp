#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int integerBreak(int n)
{
    int len = n, mx = -1;

    for (int i = 2; i <= len; i++) {
        
        int val = n / i;
        int cnt1 = n % i;
        int cnt2 = (i - cnt1);

        int res = 1;
        while (cnt2--) res *= val;
        while (cnt1--) res *= (val + 1);

        mx = max(mx, res);
    }
    return mx;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cout << integerBreak(n) << endl;

    return 0;
}