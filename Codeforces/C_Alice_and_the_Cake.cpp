                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

map <int64_t, int64_t> mp;

bool isPossible(int64_t sum, int n)
{
    if (n == 1) return true;
    queue <int64_t> q;
    q.push(sum);

    while (!q.empty()) {
        int64_t val = q.front();
        q.pop();

        int64_t x = val / 2;
        int64_t y = val - x;

        if (mp[x] > 0) mp[x]--;
        else if (x > 1) q.push(x);

        if (mp[y] > 0) mp[y]--;
        else if (y > 1) q.push(y);

        if (q.size() > n + 2) return false;
    }
    for (auto xx: mp) if (xx.second > 0) return false;
    return true;
}

void solve()
{
    int n;

    cin >> n;
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        mp[val]++;
        sum += val;
    }

    if (isPossible(sum, n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    mp.clear();
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}