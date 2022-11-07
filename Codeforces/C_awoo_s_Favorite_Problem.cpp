                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int len;
string s1, s2;

bool isEqual()
{
    int cnt[3] = {0};
    for (int i = 0; i < len; i++) cnt[s1[i] - 'a']++;
    for (int i = 0; i < len; i++) cnt[s2[i] - 'a']--;
    return cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0;
}

bool isPossible()
{
    vector <int> pos[3];
    for (int i = len - 1; i >= 0; i--) pos[s1[i] - 'a'].push_back(i);

    for (int i = 0; i < len; i++) {
        if (s2[i] < s1[i]) return false;
        if (s1[i] == s2[i]) {
            pos[s1[i] - 'a'].pop_back();
            continue;
        }

        if (s1[i] == 'b') {
            int tmpa, tmpc;
            tmpc = pos[2][pos[2].size() - 1];
            tmpa = (pos[0].size())?(pos[0][pos[0].size() - 1]):len;

            if (tmpa < tmpc) return false;
            pos[2].pop_back();
            pos[1][pos[1].size() - 1] = tmpc;
            swap(s1[i], s1[tmpc]);
        }
        else if (s1[i] == 'a') {
            if (s2[i] == 'c') return false;
            int tmpb, tmpc;
            tmpb = pos[1][pos[1].size() - 1];
            tmpc = (pos[2].size())?(pos[2][pos[2].size() - 1]):len;

            if (tmpc < tmpb) return false;
            pos[1].pop_back();
            pos[0][pos[0].size() - 1] = tmpb;
            swap(s1[i], s1[tmpb]);
        }
    }
    return true;
}

void solve()
{
    cin >> len >> s1 >> s2;
    if (isEqual() && isPossible()) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}