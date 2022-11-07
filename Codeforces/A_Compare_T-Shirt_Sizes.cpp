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
    string s1, s2;

    cin >> s1 >> s2;

    int len1 = s1.size(), len2 = s2.size();

    if (s1[len1 - 1] == s2[len2 - 1]) {
        if (len1 == len2) cout << '=' << endl;

        else if (s1[len1 - 1] == 'S') {
            if (len1 > len2) cout << '<' << endl;
            else cout << '>' << endl;
        }
        else {
            if (len1 > len2) cout << '>' << endl;
            else cout << '<' << endl;
        }
    }
    else {
        if (s1[len1 - 1] == 'S' && s2[len2 - 1] == 'L') cout << '<' << endl;
        else if (s1[len1 - 1] == 'S' && s2[len2 - 1] == 'M') cout << '<' << endl;
        else if (s1[len1 - 1] == 'L' && s2[len2 - 1] == 'S') cout << '>' << endl;
        else if (s1[len1 - 1] == 'M' && s2[len2 - 1] == 'S') cout << '>' << endl;
        else if (s1[len1 - 1] == 'L' && s2[len2 - 1] == 'M') cout << '>' << endl;
        else cout << '<' << endl;
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