#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector<pair<int, string>> romanSymbols = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

string intToRoman(int num)
{
    string ans = "";
    for (auto xx: romanSymbols) {
        if (num / xx.first) {
            int cnt = num / xx.first;
            while (cnt--) ans += xx.second;
            num %= xx.first;
        }
    }
    return ans;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cout << intToRoman(n) << endl;

    return 0;
}