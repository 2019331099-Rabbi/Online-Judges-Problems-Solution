#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;

    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.rbegin(), v.rend());

    deque <int> dq;
    bool flag = true;
    for (auto xx: v)
     {
        if (flag) dq.push_back(xx), flag = false;
        else dq.push_front(xx), flag = true;
    }
    for (auto xx: dq) cout << xx << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    solve();
    return 0;
}