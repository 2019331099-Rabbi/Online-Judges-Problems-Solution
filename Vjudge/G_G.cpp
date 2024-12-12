#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    int n, m;
    string s;

    cin >> n >> m >> s;

    int mapping1[sz];

    for (int i = 0; i <200; i++) mapping1[i] = i;

    while (m--) {
        char ch1, ch2;

        cin >> ch1 >> ch2;

        for(int i=0; i<200; i++)
        {
            if(mapping1[i]==ch1)
            {
                mapping1[i] = ch2;
            }
            else if(mapping1[i]==ch2)
            {
                mapping1[i] = ch1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<char(mapping1[s[i]]);
    }
    cout<<endl;
    
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}