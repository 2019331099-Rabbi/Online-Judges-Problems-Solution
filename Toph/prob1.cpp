#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int N)
{
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (val >= 10 && val <= 20) cnt++;
    }
    cout << cnt << " in" << endl << N - cnt << " out" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int N;

    cin >> N;
    solve(N);
    return 0;
}