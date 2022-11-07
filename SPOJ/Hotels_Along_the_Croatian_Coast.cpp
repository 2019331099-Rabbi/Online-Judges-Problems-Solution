#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, k;

    cin >> n >> k;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int left = 1, right = 1, sum = 0, mx = INT_MIN;
    while (right <= n) {
        sum += arr[right];
        while (sum > k && left <= n) {
            sum -= arr[left];
            left++;
        }
        mx = max(mx, sum);
        right++;
    }
    cout << mx << endl;
    return 0;
}