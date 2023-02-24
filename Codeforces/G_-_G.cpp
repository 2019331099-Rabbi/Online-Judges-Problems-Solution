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

bool isvalid1(double len, double width)
{
    return ((6.0 * len) / 10.0) == width;
}

bool isvalid2(double len, double r)
{
    return r * 5.0 == len;
}

bool isvalid3(int cxlen, int cylen, int len, int width)
{
    return (cylen * 2.0 == width) && (((4.5 * len) / 10.0) == cxlen);
}

void solve()
{
    double x0, y0, x1, y1, cx, cy, r;

    cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;

    int len = x1 - x0;
    int width = y1 - y0;

    int cxlen = cx - x0, cylen = cy - y0;

    if (isvalid1(len, width) && isvalid2(len, r) && isvalid3(cxlen, cylen, len, width)) cout << "YES" << endl;
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