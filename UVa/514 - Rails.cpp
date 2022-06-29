#include <bits/stdc++.h>
#define endl '\n'
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n;

bool check(int coach[])
{
    stack <int> stk;
    int i=1, incoming=1;

    while (incoming<=n) {
        if (incoming!=coach[i]) {
            stk.push(incoming++);
            continue;
        }
        i++, incoming++;
        while (!stk.empty() && stk.top()==coach[i]) stk.pop(), i++;
    }
    return i>=n;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    while (cin >> n && n) {
        int coach[n+1];
        while (cin >> coach[1] and coach[1]) {
            for (int i=2; i<=n; i++) cin >> coach[i];
            if (check(coach)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}
