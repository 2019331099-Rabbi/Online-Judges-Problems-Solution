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
    string s;

    cin >> s;
    int64_t len = s.size();

    int64_t i = 0, j = 0;
    while (j < len && s[j] == '?') j++;
    if (j < len) {
        while (j > 0) {
            s[j - 1] = (s[j] == '0')?'1':'0';
            j--;
        }
        int64_t ans = 1;
        i = 0, j = 1;
        int64_t prev = 0;
        while (j < len) {
            ans++;
            if (s[j] == s[j - 1] && s[j] != '?') i = j, j++;
            else if (s[j - 1] == '?' && s[j] != '?') {
                if (s[j] == s[prev] && (j - prev) % 2 == 0) ans += j - i;
                else if (s[j] != s[prev] && (j - prev) % 2 == 1) ans += j - i;
                else i = prev + 1, ans += (j - i);
                j++;
            }
            else {
                ans += j - i;
                j++;
            }
            if (s[j - 1] != '?') prev = j - 1;
        }
        cout << ans << endl;
        
    }
    else cout << len * (len + 1) / 2 << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}