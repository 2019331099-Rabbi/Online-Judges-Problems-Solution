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
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        vector <int> mappings1(150, 0), mappings2(150, 0);

        for (int i = 0; i < len; i++) {
            if (mappings1[s[i]] != mappings2[t[i]]) return false;
            mappings1[s[i]] = mappings2[t[i]] = i + 1;
        }
        return true;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    string s = "foo", t = "bar";
    cout << soln->isIsomorphic(s, t) << endl;


}