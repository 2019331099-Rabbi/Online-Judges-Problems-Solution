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
    int n;

    cin >> n;
    int cnta1, cntb1;
    cnta1 = cntb1 = 0;
    vector <int> v1(n), v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        if (v1[i]) cnta1++;
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
        if (v2[i]) cntb1++;
    }

    if (v1 == v2) cout << 0 << endl;
    else if (cnta1 == cntb1) cout << 1 << endl;
    else {
        int ans = abs(cnta1 - cntb1);
        if (cnta1 > cntb1) {
            cnta1 = ans;
            for (int i = 0; i < n && cnta1; i++) if (v1[i] && !v2[i]) v1[i] = 0, cnta1--;
        }
        else {
            cnta1 = ans;
            for (int i = 0; i < n && cnta1; i++) if (!v1[i] && v2[i]) v1[i] = 1, cnta1--;
        }
        if (v1 == v2) cout << ans << endl;
        else cout << ans + 1 << endl;
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