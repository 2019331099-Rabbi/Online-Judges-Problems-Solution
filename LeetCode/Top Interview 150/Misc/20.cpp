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
    bool isValid(string s) {
        if (s.size() & 1) return false;

        stack <char> stk;
        for (auto &ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else {
                if (stk.empty()) return false;
                else if (ch == ')' && stk.top() != '(') return false;
                else if (ch == '}' && stk.top() != '{') return false;
                else if (ch == ']' && stk.top() != '[') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();
    string s = "()[]{}";
    cout << soln->isValid(s) << endl;
    
    return 0;
}