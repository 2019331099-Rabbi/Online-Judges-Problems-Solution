#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int steps(int n)
{
    int tmp = n / 2;
    if (n & 1) tmp++;
    tmp++;
    if (n & 1) return tmp * (tmp - 1) * 2;
    return tmp * tmp;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    cin >> n;
    cout << steps(n) << endl;
    return 0;
}