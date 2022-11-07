#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;

    cin >> n;
    vector <int> neg, nonneg;
    vector <pair <int, int>> pr(n);

    for (int i = 0; i < n; i++) cin >> pr[i].first;
    for (int i = 0; i < n; i++) cin >> pr[i].second;

    for (int i = 0; i < n; i++) {
        int val = pr[i].second - pr[i].first;
        if (val >= 0) nonneg.push_back(val);
        else neg.push_back(val);
    }
    sort(neg.rbegin(), neg.rend());
    sort(nonneg.begin(), nonneg.end());

    int len1 = neg.size(), len2 = nonneg.size();
    int i = 0, j = 0, cnt = 0;

    while (i < len1 && j < len2) {
        if (neg[i] + nonneg[j] >= 0) {
            i++, j++;
            cnt++;
        }
        else j++;
    }
    cnt += (len2 - cnt) / 2;
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}