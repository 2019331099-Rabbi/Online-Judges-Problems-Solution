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
    int evalRPN(vector<string>& tokens) {
        stack <int> stk;
        for (auto s: tokens) {
            if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9') stk.push(stoi(s));
            else {
                int v2 = stk.top();
                stk.pop();
                int v1 = stk.top();
                stk.pop();

                if (s[0] == '+') v1 += v2;
                else if (s[0] == '*') v1 *= v2;
                else if (s[0] == '-') v1 -= v2;
                else v1 /= v2;
                stk.push(v1);
            }
        }
        return stk.top();
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <string> tokens = {"2", "1", "+", "3", "*"};
    cout << soln->evalRPN(tokens) << endl;

    return 0;
}