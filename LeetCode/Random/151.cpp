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
    string reverseWords(string s) {
        int left = 0;
        int len = s.size();
        bool flag = false;
        for (int right = 0; right < len; right++) {
            if (s[right] != ' ') {
                if (flag && s[right - 1] == ' ') s[left++] = ' ';
                s[left++] = s[right];
                flag = true;
            }
        }
        s.resize(left);
        reverse(s.begin(), s.end());
        s += ' ';
        len = s.size();
        left = 0;
        for (int right = 0; right < len; right++) {
            if (s[right] == ' ') {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
        }
        s.resize(len - 1);
        return s;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    string s = "the sky is blue";
    cout << ':' << soln->reverseWords(s) << ':' << endl;

}