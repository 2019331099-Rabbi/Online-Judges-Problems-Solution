#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

string s;

bool check()
{
    int len = s.size();
    if (s[0] != 'Y' && s[0] != 'e' && s[0] != 's') return false;

    for (int i = 1; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'Y') return false;
        if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') return false;
        if (s[i] == 'Y' && s[i - 1] != 's') return false;
        if (s[i] == 'e' && s[i - 1] != 'Y') return false;
        if (s[i] == 's' && s[i - 1] != 'e') return false;
    }
    return true;
}

void solve()
{
    cin >> s;
    if (check()) cout << "YES" << endl;
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