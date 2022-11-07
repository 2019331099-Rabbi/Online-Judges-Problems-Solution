#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

string s;

pair <bool, int> check()
{
    stack <char> stk;
    int len = s.size(), cnt = 1;

    for (int i = 0; i < len; i++) {
        cnt++;
        if (s[i] == '[' || s[i] == '{' || s[i] == '<') stk.push(s[i]);
        else if (s[i] == '(') {
            if (i + 1 == len) return {false, cnt};
            if (s[i + 1] == '*') {
                stk.push('s');
                i++;
            }
            else stk.push('(');
        }
        else if (s[i] == ']') {
            if (stk.empty() || stk.top() != '[') return {false, cnt - 1};
            stk.pop();
        }
        else if (s[i] == '}') {
            if (stk.empty() || stk.top() != '{') return {false, cnt - 1};
            stk.pop();
        }
        else if (s[i] == '>') {
            if (stk.empty() || stk.top() != '<') return {false, cnt - 1};
            stk.pop();
        }
        else if (s[i] == '*') {
            if (i + 1 < len && s[i + 1] == ')') {
                if (stk.empty() || stk.top() != 's') return {false, cnt - 1};
                i++;
                stk.pop();
            }
        }
        else if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(') return {false, cnt - 1};
            stk.pop();
        }
        //cout << i << ' ' << cnt << endl;
    }
    return {stk.empty(), cnt};
}

void solve()
{
    pair <bool, int> ans = check();
    if (ans.first) cout << "YES" << endl;
    else cout << "NO " << ans.second << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);

    while (getline(cin, s)) solve();
    return 0;
}