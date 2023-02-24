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

void solve()
{
    int64_t n, m;

    cin >> n >> m;
    multiset <int64_t> st;
    for (int64_t i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        st.insert(val);
    }
    vector <int64_t> brr(m);
    for (auto &xx: brr) cin >> xx;

    for (int64_t i = 0; i < m; i++) {
        auto it = st.begin();
        int64_t val = *it;
        st.erase(it);
        st.insert(brr[i]);
    }
    int64_t sum = 0;
    for (auto xx: st) sum += xx;
    cout << sum << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}

/*
25 5 1 106.8
64 8 1 177.2
144 12 1 279.2
*/