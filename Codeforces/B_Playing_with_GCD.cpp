#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

bool check(vector <int> v, int n)
{
    vector <int> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        int tmp = __gcd(v[i], v[i - 1]);
        tmp = (v[i] * v[i - 1]) / tmp;
        ans.push_back(tmp);
    }
    ans.push_back(v[n - 1]);
    for (int i = 1; i < ans.size(); i++) if (__gcd(ans[i], ans[i - 1]) != v[i - 1]) return false;
    return true;
}

void solve()
{
    int n;

    cin >> n;
    vector <int> v(n);
    for (auto &xx: v) cin >> xx;
    if (check(v, n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}