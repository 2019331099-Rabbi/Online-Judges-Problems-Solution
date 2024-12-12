#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

int longestPalindrome(string s)
{
    int occ[60] = {0};
    for (auto xx: s) occ[xx-'A']++;

    int res = 0;
    for (int i = 0; i < 60; i++) res += occ[i] & ~1;
    if (res < s.size()) res++;
    return res;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    string s = "abccccdd";

    cout << longestPalindrome(s) << endl;

    return 0;
}