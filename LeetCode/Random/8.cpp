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
    int myAtoi(string s) 
    {
        int i = 0;
        int sign = 1;
        
        while (i < s.size() && s[i] == ' ') i++;
        if (s[i] == '-') sign = -1, i++;
        else if (s[i] == '+') sign = 1, i++;

        int64_t ans = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT32_MAX && sign == 1) return INT32_MAX;
                else if (ans > INT32_MAX && sign == -1) return INT32_MIN;
                i++;
            }
            else return ans * sign;
        }
        return ans * sign;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    Solution *soln = new Solution();

    string s = "42";
    cout << soln->myAtoi(s) << endl;
    // cout << stoi(s) << endl;
    return 0;
}