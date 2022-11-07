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
    char ch;
    string s;

    cin >> n >> ch >> s;
    if (ch == 'g') {
        cout << 0 << endl;
        return;
    }


    int i = 0, j;
    while (s[i] != ch) i++;
    j = i;

    // cout << i << ' ' << j << endl;

    int ans = INT_MIN;
    while (j < n) {
        if (s[j] == 'g') {
            ans = max(ans, j - i);
            i = j;
            while (i < n && s[i] != ch) i++;
            j = i;
        }
        else j++;
        // cout << i << ' ' << j << ' ' << ans << endl;
    }
    // cout << endl;
    // cout << i << ' ' << j << ' ' << ans << endl;
    if (i < n) {
        int j = 0;
        while (s[j] != 'g') j++;
        ans = max(ans, j + n - i);
    }
    cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}