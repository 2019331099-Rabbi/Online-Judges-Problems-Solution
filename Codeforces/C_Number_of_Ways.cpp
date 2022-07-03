#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 110
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    int64_t sum = 0;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 3) cout << 0 << endl;
    else {
        sum /= 3;
        int64_t tmp = 0;
        int presum[n];
        for (int i = 0; i < n; i++) {
            tmp += arr[i];
            presum[i] = (tmp == sum)?1:0;
        }
        for (int i = 1; i < n; i++) presum[i] += presum[i - 1];
        sum *= 2;
        tmp = arr[0];
        int64_t ans = 0;
        for (int i = 1; i < n - 1; i++) {
            tmp += arr[i];
            if (tmp == sum) ans += presum[i - 1];
        }
        cout << ans << endl;
    }
    return 0;
}