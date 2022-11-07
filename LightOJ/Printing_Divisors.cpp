#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 50000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int64_t T)
{
    int n;
    cin >> n;

    vector <int> divisors;

    for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    for (auto xx: divisors) cout << xx << ' ';
    cout << endl;
    
    
    
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}