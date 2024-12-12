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

/*
Tutorial: www.youtube.com/watch?v=HwDXH35lr0o
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        // swap(word1, word2);
        int len1 = word1.size();
        int len2 = word2.size();

        int memo[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) memo[i][0] = i;
        for (int i = 1; i <= len2; i++) memo[0][i] = i;
        memo[0][0] = 0;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1]) memo[i][j] = memo[i - 1][j - 1];
                else memo[i][j] = 1 + min({memo[i - 1][j - 1], memo[i - 1][j], memo[i][j - 1]});
            }
        }
        // for (int i = 0; i <= len1; i++) {
        //     for (int j = 0; j <= len2; j++) cout << memo[i][j] << ' ';
        //     cout << endl;
        // }
        return memo[len1][len2];
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    // string word1 = "eat", word2 = "sea";
    string word1 = "horse", word2 = "ros";
    cout << soln->minDistance(word1, word2) << endl;

    return 0;
}