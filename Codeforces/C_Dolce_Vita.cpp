                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t totalBuy(vector <int64_t> v, int64_t money)
{
    int64_t a, d, sum = 0, ans = 0;

    while (v.size() && v[v.size() - 1] > money) v.pop_back();

    for (int i = v.size() - 1; i >= 0; i--) {
        a = v[i];
        d = i + 1;
        //cout << i << ' ' << a << ' ' << d << endl;
        int64_t tmp = max(0ll, 1 + (money - a) / d);
        //cout << tmp << ' ' << sum << endl;

        ans += d * (tmp - sum);
        sum += (tmp - sum);
        //cout << ans << endl;
    }
    return ans;
}

void solve()
{
    int64_t n, money;

    cin >> n >> money;
    vector <int64_t> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) v[i] += v[i - 1];

    // for (auto xx: v) cout << xx << ' ';
    // cout << endl;

    cout << totalBuy(v, money) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}