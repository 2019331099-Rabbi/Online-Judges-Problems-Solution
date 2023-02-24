#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;
 
int n, w, arr[101], memo[100][1000001];
 
void init()
{
    memset(memo, -1, sizeof(memo));
}
 
int coinChange(int pos, int amount)
{
    if (amount < 0) return inf;
    if (pos == n) {
        if (amount == 0) return 0;
        else return inf;
    }
    if (memo[pos][amount] != -1) return memo[pos][amount];
 
    int val1 = 1 + coinChange(pos, amount - arr[pos]);
    int val2 = coinChange(pos + 1, amount);
    return memo[pos][amount] = min(val1, val2);
}
 
int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = coinChange(0, w);
    if (ans >= inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}