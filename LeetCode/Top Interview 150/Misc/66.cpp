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
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int i = len - 1;
        while (i >= 0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }
        if (i < 0) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        digits[i] += 1;
        return digits;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> digits = {9, 9, 9};
    vector <int> nums = soln->plusOne(digits);
    for (auto xx: nums) cout << xx << ' ';
    cout << endl;
}