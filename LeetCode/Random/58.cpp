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
    int lengthOfLastWord(string s) {
        vector <int> ans;

        for (int i = s.size() - 1; i >= 0; i--) {
            int flag = isalpha(s[i]);
            if (ans.size() && !flag) {
                ans.push_back(i);
                break;
            }
            if (!ans.size() && flag) ans.push_back(i);
        }
        return (ans.size() == 1)?(ans[0] + 1):(ans[0]-ans[1]);
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    string s = "Moon  ";
    cout << soln->lengthOfLastWord(s) << endl;


}