#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t64_t row4[]={0, 1, 0, -1};
// int64_t64_t col4[]={1, 0, -1, 0};
 
//int64_t64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int64_t x, k, q;
    string s;
    char mina = 'a', mxb = 'a';
    int64_t cntmina = 1, cntmxb = 1, lena = 1, lenb = 1;

    cin >> q;
    while (q--) {
        cin >> x >> k >> s;
        int64_t len = s.size();
        if (x == 2) {
            lenb += k * len;
            for (auto xx: s) mxb = max(mxb, xx);
            for (auto xx: s) if (xx == mxb) cntmxb += k;
        }
        else {
            lena += k * len;
            for (auto xx: s) if (xx == mina) cntmina += k;
        }
        if (mxb > mina) cout << "YES" << endl;
        else {
            if (cntmina >= cntmxb) cout << "NO" << endl;
            else {
                if (cntmina == lena) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}