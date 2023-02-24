#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    vector <int> v(3);
    int k;

    cin >> v[0] >> v[1] >> v[2] >> k;
    sort(v.begin(), v.end());

    int sum = v[0] + v[1] + v[2];
    

    cout << "Case " << T << ": ";
    if (sum % 3) cout << "Fight" << endl;
    else if ((v[0] + v[2]) / 2 == v[1] && v[2] - k == v[1] && v[0] + k == v[1]) cout << "Peaceful" << endl;
    else cout << "Fight" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}