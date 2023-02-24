#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 50000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t findSum(int64_t n) {
    int64_t sum = 0;
    int64_t root = sqrt(n);
    for (int64_t i = 2; i <= root; i++) {
        int64_t j = n / i;
        sum += (j+i) * (j-i+1) / 2;
        sum += (j-i) * i;
    }
    return sum;
}

void solve(int T)
{
    int64_t n;
    cin >> n;
    cout << "Case " << T << ": " << findSum(n) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}