#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool isValid(string s)
{
    stack <char> stk;

    for (auto xx: s) {
        if (xx == '(' || xx == '{' || xx == '[') stk.push(xx);
        else {
            if (stk.empty() || !isMatching(stk.top(), xx)) return false;
            stk.pop();
        }
    }
    return stk.empty();
}



int main()
{
    RUN_FAST;
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}