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
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0) return 0;

        s += s[len - 1];
        len++;
        int charOcc[130] = {0};
        int left = 0, right = 0;
        int mxLen = 0;

        while (right < len) {
            char ch = s[right];
            charOcc[ch]++;
            if (charOcc[ch] > 1) {
                mxLen = max(mxLen, right - left);
                while (s[left] != ch) {
                    charOcc[s[left]]--;
                    left++;
                }
                charOcc[ch]--;
                left++;
            }
            right++;
        }
        return (mxLen)?mxLen:len;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    string s = "tmmzuxt";
    cout << soln->lengthOfLongestSubstring(s) << endl;
}