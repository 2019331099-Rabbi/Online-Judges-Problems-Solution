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

void solve()
{
    int64_t n, k;

    cin >> n >> k;
    vector <int64_t> v(n);

    int64_t sum = 0;
    for (auto &xx: v) {
        cin >> xx;
        sum += xx / k;
        xx %= k;
    }
    sort(v.begin(), v.end());
    int64_t i = 0, j = n - 1;
    
    while (i < j) {
        int64_t val = v[i] + v[j];
        if (val < k) i++;
        else {
            sum += val / k;
            i++, j--;
        }
    }
    cout << sum << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}