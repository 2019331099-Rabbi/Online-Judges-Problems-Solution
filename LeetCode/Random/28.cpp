#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> generateLPS(string pattern)
{
    int len = pattern.size(), i = 0, j = 1;
    vector <int> lps(len);

    lps[0] = 0;
    while (j < len) {
        if (pattern[i] == pattern[j]) {
            lps[j] = i + 1;
            i++, j++;
        }
        else {
            if (!i) lps[j] = 0, j++;
            else i = lps[i - 1];
        }
    }
    return lps;
}

int strStr(string text, string pattern)
{
    vector <int> lps = generateLPS(pattern);
    
    int i = 0, j = 0, tlen = text.size(), pLen = pattern.size();
    vector <int> indxPos;

    while (i < tlen) {
        if (text[i] == pattern[j]) i++, j++;
        else {
            if (!j) i++;
            else j = lps[j - 1];
        }
        if (j == pLen) return i - pLen;
    }
    return -1;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    string text, pattern;

    cin >> text, pattern;
}