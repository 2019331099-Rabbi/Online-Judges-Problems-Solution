                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n, q, maxPos;

    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == n) maxPos = i;
    }

    int i = 0, j = 1, round = 1;
    map <int, pair <int, int>> mp;

    while (j < n) {
        if (arr[j] > arr[i]) {
            i = j;
            mp[j].first++;
            mp[j].second = round;
        }
        else {
            mp[i].first++;
            mp[i].second = round;
        }
        j++;
        round++;
    }

    while (q--) {
        int p, r;
        cin >> p >> r;
        p--;
        if (mp[p].first == 0) cout << 0 << endl;
        else {
            int reqRound = mp[p].second;
            if (r >= reqRound) {
                int add = (p == maxPos)?(r - reqRound):0;
                cout << mp[p].first + add << endl;
            }
            else {
                int diff = reqRound - r;
                cout << max(0, mp[p].first - diff) << endl;
            }
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}