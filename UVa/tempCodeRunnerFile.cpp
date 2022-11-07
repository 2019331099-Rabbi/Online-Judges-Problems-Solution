#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main() {
    char s[4096];
    while(gets(s)) {
        stack<int> stk;
        // ( [ { < (* *) > } ] )
        // 0 1 2 3 4   5 6 7 8 9
        int i, j, k;
        int ch, err = 0, pos = 1;
        for(i = 0; s[i] && !err; i++) {
            ch = -1;
           // printf("---- %c\n", s[i]);
            if(s[i] == '(') {
                if(s[i+1] == '*') {
                    i++;
                    ch = 4;
                } else {
                    ch = 0;
                }
            } else if(s[i] == '*') {
                if(s[i+1] == ')') {
                    i++;
                    ch = 5;
                } else {
                    ch = -1;
                }
            } else if(s[i] == '[')
                ch = 1;
            else if(s[i] == '{')
                ch = 2;
            else if(s[i] == '<')
                ch = 3;
            else if(s[i] == '>')
                ch = 6;
            else if(s[i] == '}')
                ch = 7;
            else if(s[i] == ']')
                ch = 8;
            else if(s[i] == ')')
                ch = 9;
            if(ch == -1) {
                pos++;
                continue;
            }
            if(ch <= 4)
                stk.push(ch);
            else {
                if(stk.empty() || stk.top() != 9-ch) {
                    printf("NO %d\n", pos);
                    err = 1;
                    break;
                }
                stk.pop();
            }
            pos++;
            cout << i << ' ' << pos << endl;
        }
        if(err) continue;
        if(!stk.empty()) {
            printf("NO %d\n", pos);
            continue;
        }
        puts("YES");
    }
    return 0;
}