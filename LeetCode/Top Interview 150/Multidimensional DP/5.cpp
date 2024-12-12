#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int len = s.size();
//         vector <vector <bool>> memo(len + 1, vector <bool>(len + 1, false));
//         /*
//         What does every element in memo mean here?
//         memo[i][j] = true or false
//         A substring starts at index i and ends at index j. If this substring is a palindrome then
//                   memo[i][j] is true;
//         otherwise memo[i][j] = false;

//         Here the substring will be a palindrome, if the following two condition meet.
//         1. s[i] = s[j] and
//         2. The substring s[i+1 : j-1] is a palindrome.
//         For example, let s = "abba"
//         now "abba" is palindrome, because s[0] = s[3] = a and "bb" is palindrome. For checking the second condition we
//         use DP. We save the results in memo.
//         */

//         int left = 0, right = 0;
//         int lps = 1;
//         for (int i = 0; i < len; i++) {
//             memo[i][i] = true;
//             if (s[i] == s[i + 1]) memo[i][i + 1] = true, left = i, right = i + 1;
//         }
//         /*
//         Here we initialize the memo as
//         1. All the one length string is palindrome.
//         2. We check all the two length substring manually, it is palindrome or not.
//         */
//         lps = right - left + 1;

//         for (int step = 2; step < len; step++) {
//             for (int i = 0; i + step < len; i++) {
//                 int xi = i, yi = i + step;
//                 if (memo[xi + 1][yi - 1] && s[xi] == s[yi]) {
//                     memo[xi][yi] = true;
//                     if ((yi - xi + 1) > lps) lps = yi - xi + 1, left = xi, right = yi;
//                 }
//             }
//         }
//         return s.substr(left, right - left + 1);
//     }
// };

// Manachers Algorithm
class Solution {
public:
    string preprocess(string &s) {
        if (s.empty()) return "$@";
        string tmps = "$";
        for (auto &ch: s) tmps += '#', tmps += ch;
        tmps += "#@";
        return tmps;
    }

    string longestPalindrome(string s) {
        string T = preprocess(s);
        int len = T.size();
        vector <int> lps(len, 0);

        int C = 0, R = 0;
        for (int i = 1; i < len - 1; i++) {
            int iMirror = 2*C - i; // C - (i - C)
            if (i < R) {
                lps[i] = min(lps[iMirror], R - i);
            }
            else lps[i] = 0;

            while (T[i + 1 + lps[i]] == T[i - 1 - lps[i]]) lps[i]++;
            if (i + lps[i] > R) R = i + lps[i], C = i;
        }
        int cnt = 0;
        for (int i = 1; i < len - 1; i++) {
            if (lps[i] > cnt) cnt = lps[i], C = i;
        }
        int start = (C - cnt - 1) / 2;
        return s.substr(start, cnt);
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    string s = "cbbd";
    cout << soln->longestPalindrome(s) << endl;
}