#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t n, m, k;

    cin >> n >> m >> k;
    vector <int64_t> v(n);

    for (auto &xx: v) cin >> xx;
    sort(v.rbegin(), v.rend());

    int64_t tmp = m / (k + 1);
    int64_t sum = (v[0] * k + v[1]) * tmp;

    tmp = m % (k + 1);
    sum += v[0] * tmp;

    cout << sum << endl;

}