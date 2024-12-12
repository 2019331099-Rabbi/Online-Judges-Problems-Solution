#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 10000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

string letters[10];
vector <string> results;

void init()
{
    letters[2] = "abc";
    letters[3] = "def";
    letters[4] = "ghi";
    letters[5] = "jkl";
    letters[6] = "mno";
    letters[7] = "pqrs";
    letters[8] = "tuv";
    letters[9] = "wxyz";
}

void backtracing(int pos, string str, string digits)
{
    if (pos == digits.size()) {
        results.push_back(str);
        return;
    }

    int digit = digits[pos] - '0';

    for (int i = 0; i < letters[digit].size(); i++) {
        str.push_back(letters[digit][i]);
        backtracing(pos + 1, str, digits);
        str.pop_back();
    }
}

vector <string> letterCombinations(string digits)
{
    if (digits.size()) backtracing(0, "", digits);
    return results;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    init();

    string s;
    cin >> s;
    letterCombinations(s);

    return 0;
}