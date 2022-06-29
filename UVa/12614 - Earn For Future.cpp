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
    int T, i=1, val, mx, n;
    cin >> T;
    while (T--) {
        cin >> n;
        mx=0;
        while (n--) {
            cin >> val;
            mx=max(mx, val);
        }
        cout << "Case " << i++ << ": " << mx << endl;
    }
    return 0;
}
