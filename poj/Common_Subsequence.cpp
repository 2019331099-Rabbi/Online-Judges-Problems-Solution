#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#define endl '\n'
#define PI acos(-1)
#define sz 350
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

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
    while (cin >> s1 >> s2) {
        init();
        cout << LCS(0, 0) << endl;
    }
    return 0;
}