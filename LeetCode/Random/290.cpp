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

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char, int> mappings1;
        unordered_map <string, int> mappings2;

        int lenP = pattern.size(), lenS = s.size();
        int i = 0, j = 0;
        while (i < lenP && j < lenS) {
            string tmp = "";
            while (j < lenS && s[j] != ' ') tmp += s[j], j++;

            if (mappings1[pattern[i]] != mappings2[tmp]) return false;
            mappings1[pattern[i]] = mappings2[tmp] = i + 1;
            tmp = "";
            i++, j++;
        }
        return (i >= lenP && j >= lenS);
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    string pattern = "abb", s = "dog cat cat dog";
    cout << soln->wordPattern(pattern, s) << endl;


}