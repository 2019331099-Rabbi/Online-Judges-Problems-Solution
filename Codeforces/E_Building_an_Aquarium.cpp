#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


void solve(int T)
{
    int64_t n, w;
    cin >> n >> w;
    
    vector <int64_t> v(n);
    for (auto &xx: v) cin >> xx;

    int64_t i = 1, j = inf, ans = 0;
    while (i <= j) {
        int64_t h = (i + j) >> 1, sum = 0;
        for (auto xx: v) if (xx <= h) sum += h - xx;
        if (sum > w) j = h - 1;
        else if (sum < w) i = h + 1, ans = h;
        else {
            ans = h;
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}