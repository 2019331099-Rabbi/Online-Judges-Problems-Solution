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
    vector<string> letters = {
        "", "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        vector<string> allCombs;
        if (digits.empty()) return allCombs;

        function<void(int, string)> generateCombinations = [&](int pos, string order) {
            if (pos == digits.size()) {
                allCombs.push_back(order);
                return;
            }

            int idx = digits[pos] - '0';
            for (auto ch : letters[idx]) {
                order.push_back(ch);
                generateCombinations(pos + 1, order);
                order.pop_back();
            }
        };

        generateCombinations(0, "");
        return allCombs;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    string digits = "23";
    auto result = soln->letterCombinations(digits);

    for (auto xx: result) cout << xx << endl;
    return 0;

}