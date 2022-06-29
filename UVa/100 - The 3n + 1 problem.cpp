#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 125001
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main ()
{
    RUN_FAST; cin.tie(nullptr);
    int a, b, i, tmp, cnt, ans, mx, mn;
    while (cin >> a >> b) {
        mn=a, mx=b;
        if (mn>mx) swap(mx, mn);
        ans=0;
        for (i=mn; i<=mx; i++) {
            cnt=0;
            tmp=i;
            while (1) {
                cnt++;
                if (tmp==1) break;
                if (tmp%2) tmp=tmp*3+1;
                else tmp/=2;
            }
            ans=max(ans, cnt);
        }
        cout << a << ' ' << b << ' ' << ans << endl;
    }
    return 0;
}
