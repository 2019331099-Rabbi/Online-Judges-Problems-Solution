#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    double a, b;

    cin >> a >> b;

    double theta1 = atan(b / a);
    double theta2 = atan(a / b);
    double len = sqrt(a * a + b * b);
    len /= 2.0;
    cout << fixed;
    double ans;

    if (theta1 <= theta2) {
        double r = sin(theta1) * len;
        ans = PI * r * r;
        ans /= 2.0;
    }
    else {
        double r = sin(theta2) * len;
        ans = PI * r * r;
        ans /= 2.0;
    }
    cout << setprecision(10) << ans << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}