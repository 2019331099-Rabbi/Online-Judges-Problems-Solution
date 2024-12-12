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

bool canConstruct(string ransomNote, string magazine)
{
    int occ[26] = {0};

    for (auto xx: magazine) occ[xx-'a']++;
    for (auto xx: ransomNote) {
        occ[xx-'a']--;
        if (occ[xx-'a'] < 0) return false;
    }
    return true;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
}