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
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1 || numRows >= len) return s;

        string result = "";
        int jmp1 = numRows * 2 - 2, jmp2 = 0;
        for (int i = 0; i < numRows; i++) {
            result += s[i];
            int j = i;
            cout << i << endl;
            while (j < len) {
                if (jmp1) {
                    j += jmp1;
                    if (j < len) {
                        // cout << j << ' ';
                        result += s[j];
                    }
                }
                if (jmp2) {
                    j += jmp2;
                    if (j < len) {
                        // cout << j << ' ';
                        result += s[j];
                    }
                }
            }
            cout << endl;
            jmp1 -= 2;
            jmp2 += 2;
        }
        return result;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE";
    int numRows = 7;
    s = "ABC", numRows = 4;

    cout << ':' << soln->convert(s, numRows) << ':' << endl;

}