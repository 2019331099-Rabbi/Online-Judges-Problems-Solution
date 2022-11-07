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
    vector <string> v1, v2, v3;
	map<string, int>mp;

	for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v1.push_back(s);
        mp[s]++;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v2.push_back(s);
        mp[s]++;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v3.push_back(s);
        mp[s]++;
    }

	int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
	for (long long i = 0; i < n; i++)
	{
		if (mp[v1[i]] == 2) cnt1++;
		if (mp[v1[i]] == 1) cnt1 += 3;

		if (mp[v2[i]] == 2) cnt2++;
		if (mp[v2[i]] == 1) cnt2 += 3;

		if (mp[v3[i]] == 2) cnt3++;
		if (mp[v3[i]] == 1) cnt3 += 3;

	}

	cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}