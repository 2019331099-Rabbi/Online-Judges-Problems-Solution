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
    string simplifyPath(string path) {
        path += '/';
        vector <string> stk;
        int len = path.size(), pos = 1;
        string s = "";

        while (pos < len) {
            if (path[pos] == '/') {
                int tmpLen = s.size();
                if (!tmpLen);
                else if (tmpLen == 1 && s[0] == '.' || s[0] == '/');
                else if (tmpLen == 2 && s[0] == '.' && s[1] == '.') {
                    if (stk.size()) stk.pop_back();
                }
                else stk.push_back(s);
                s = "";
            }
            else s += path[pos];
            pos++;
        }
        path = "";
        for (auto &xx: stk) path += '/' + xx;
        return (path.size())?path:"/";
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    string path;
    // path = "/home/user/Documents/../Pictures";
    path = "/.../a/../b/c/../d/./";
    path = "/../";
    // path = "/home//foo/";
    cout << soln->simplifyPath(path) << endl;

    return 0;
}