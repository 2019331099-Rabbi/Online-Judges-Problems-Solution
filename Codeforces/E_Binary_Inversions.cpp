#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t64_t row4[]={0, 1, 0, -1};
// int64_t64_t col4[]={1, 0, -1, 0};
 
//int64_t64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int64_t n;

    cin >> n;
    int64_t arr[n], presum[n];
    for (int64_t i = 0; i < n; i++) {
        cin >> arr[i];
        presum[i] = !arr[i];
    }
    for (int64_t i = n - 2; i >= 0; i--) presum[i] += presum[i + 1];
    

    int64_t sum1 = 0;
    for (int64_t i = 0; i < n; i++) {
        if (arr[i]) sum1 += presum[i];
    }
    int64_t pos = -1;
    for (int64_t i = 0; i < n; i++) if (!arr[i]) {
        arr[i] = 1;
        pos = i;
        break;
    }

    memset(presum, 0, sizeof(presum));
    for (int64_t i = 0; i < n; i++) presum[i] = !arr[i];
    for (int64_t i = n - 2; i >= 0; i--) presum[i] += presum[i + 1];


    int64_t sum2 = 0;
    for (int64_t i = 0; i < n; i++) {
        if (arr[i]) sum2 += presum[i];
    }

    if (pos != -1) arr[pos] = 0;

    for (int64_t i = n - 1; i >= 0; i--) if (arr[i]) {
        arr[i] = 0;
        pos = i;
        break;
    }
    memset(presum, 0, sizeof(presum));
    for (int64_t i = 0; i < n; i++) presum[i] = !arr[i];
    for (int64_t i = n - 2; i >= 0; i--) presum[i] += presum[i + 1];

    int64_t sum3 = 0;
    for (int64_t i = 0; i < n; i++) {
        if (arr[i]) sum3 += presum[i];
    }
    cout << max({sum1, sum2, sum3}) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}