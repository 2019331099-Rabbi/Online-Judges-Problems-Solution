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
    bool isSubsequence(string s, string t) {
        int len1 = s.size(), len2 = t.size();

        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == len1;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    string s = "abc", t = "ahbgdc";
    cout << soln->isSubsequence(s, t) << endl;


}