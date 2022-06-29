#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10001
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int r, c, i, cnt, mx, val;
    while (cin >> r >> c) {
        if (!r && !c) break;
        cin >> val;
        cnt=r-val;
        mx=val;
        for (i=1; i<c; i++) {
            cin >> val;
            if (val>=mx) mx=val;
            else {
                cnt+=mx-val;
                mx=val;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
