#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

bool isAnagram(string s, string t)
{
    int n = s.size(), m = t.size();
    if (n != m) return false;

    int counter[26] = {0};
    for (int i = 0; i < n; i++) counter[s[i]-'a']++, counter[t[i]-'a']--;
    for (auto xx: counter) if (xx) return false;
    return true;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    string s = "rat", t = "car";

    cout << isAnagram(s, t) << endl;
    return 0;

}