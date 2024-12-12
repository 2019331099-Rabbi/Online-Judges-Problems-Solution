#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

bool isValid(string s)
{
    stack <char> stk;

    for (auto xx: s) {
        if (xx == '(' || xx == '{' || xx == '[') stk.push(xx);
        else if (stk.empty()) return false;
        else if (xx == ')' && stk.top() == '(') stk.pop();
        else if (xx == '}' && stk.top() == '{') stk.pop();
        else if (xx == ']' && stk.top() == '[') stk.pop();
        else return false;
    }
    return stk.empty();
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    string s = "(]";
    cout << isValid(s) << endl;

}