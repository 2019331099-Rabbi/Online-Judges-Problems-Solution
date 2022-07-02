#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://l...content-available-to-author-only...j.com/problem/an-easy-lcs

Verdict: WA
*/

string s1, s2;
int memo[sz][sz], len1, len2;

int LCS(int pos1, int pos2)
{
    if (pos1 == len1 || pos2 == len2) return 0;
    if (memo[pos1][pos2] != -1) return memo[pos1][pos2];

    if (s1[pos1] == s2[pos2]) return memo[pos1][pos2] = 1 + LCS(pos1 + 1, pos2 + 1);
    else return memo[pos1][pos2] = max(LCS(pos1, pos2 + 1), LCS(pos1 + 1, pos2));
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

void solve(int k)
{
    cin >> s1 >> s2;
    len1 = s1.size(), len2 = s2.size();
    init();
    int len = LCS(0, 0);

    string ans = (len)?"":":(";

    if (len) {
        int i = 0, j = 0, tmp1, tmp2, tmp3;
        while (1) {
            tmp1 = memo[i][j];
            tmp2 = memo[i][j + 1];
            tmp3 = memo[i + 1][j];
            if (tmp1 == 0 || i == len1 - 1 || j == len2 - 1) break;

            if (s2[j] > s2[j + 1]) {
                if (tmp1 == tmp2) j++;
                else if (tmp1 == tmp3) i++;
                else ans += s2[j], i++, j++;
            }
            else {
                if (tmp1 == tmp3) i++;
                else if (tmp1 == tmp2) j++;
                else ans += s2[j], i++, j++;
            }
        }
        if (memo[i][j]) ans += s2[j];
    }
    cout << "Case " << k << ": " << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}