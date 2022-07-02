#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Longest Common Subsequence-------------------

abcabcaa

      a  c  b  a  c  b  a
   a  5 -1 -1 -1 -1 -1 -1 
   b -1  4  4 -1 -1 -1 -1 
   c -1  4 -1  3  3 -1 -1 
   a -1 -1  3  3 -1  2  1 
   b -1 -1  3 -1  2  2 -1 
   c -1 -1 -1  2  2 -1  1 
   a -1 -1 -1  2 -1  1  1 
   a -1 -1 -1 -1  1  1  1 
*/

string s1, s2;
int memo[sz][sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int LCS(int pos1, int pos2)
{
    if (pos1 == s1.size() || pos2 == s2.size()) return 0;
    if (memo[pos1][pos2] != -1) return memo[pos1][pos2];

    if (s1[pos1] == s2[pos2]) return memo[pos1][pos2] = 1 + LCS(pos1 + 1, pos2 + 1);
    else return memo[pos1][pos2] = max(LCS(pos1, pos2 + 1), LCS(pos1 + 1, pos2));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> s1 >> s2;
    cout << LCS(0, 0) << endl;

    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) cout << memo[i][j] << ' ';
        cout << endl;
    }
    return 0;
}