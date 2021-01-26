#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 25
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};
//int col[]={1, -1, 0, 0};

void printa(int blocks, vector <int> ans[])
{
    int i;
    for (i=0; i<blocks; i++) {
        cout << i << ':';
        for (int xx: ans[i]) cout << ' ' << xx;
        cout << endl;
    }
    cout << endl;
}

int main ()
{
    RUN_FAST; cin.tie(nullptr);
    int blocks, i, from, to, x1, y1, x2, y2, len, val;
    cin >> blocks;
    vector <pair <int, int>> pos(blocks);
    vector <int> ans[blocks];
    for (i=0; i<blocks; i++) pos[i]={i, 0}, ans[i].push_back(i);

    string s1, s2;
    while (cin >> s1) {
        if (s1=="quit") break;
        cin >> from >> s2 >> to;

        x1=pos[from].first; y1=pos[from].second;
        x2=pos[to].first; y2=pos[to].second;
        if (x1==x2) continue;
        if (s1=="move") {
            len=ans[x1].size();
            for (i=len-1; i>y1; i--) {
                val=ans[x1][i];
                pos[val]={val, 0};
                ans[val].push_back(val);
                ans[x1].pop_back();
            }
            if (s2=="onto") {
                len=ans[x2].size();
                for (i=len-1; i>y2; i--) {
                    val=ans[x2][i];
                    pos[val]={val, 0};
                    ans[val].push_back(val);
                    ans[x2].pop_back();
                }
            }
            val=ans[x1][y1];
            ans[x2].push_back(val);
            pos[val]={x2, ans[x2].size()-1};
            ans[x1].pop_back();
            continue;
        }
        if (s2=="onto") {
            len=ans[x2].size();
            for (i=len-1; i>y2; i--) {
                val=ans[x2][i];
                pos[val]={val, 0};
                ans[val].push_back(val);
                ans[x2].pop_back();
            }
        }
        len=ans[x1].size();
        for (i=y1; i<len; i++) {
            val=ans[x1][i];
            ans[x2].push_back(val);
            pos[val]={x2, ans[x2].size()-1};
        }
        for (i=y1; i<len; i++) ans[x1].pop_back();
    }
    for (i=0; i<blocks; i++) {
        cout << i << ':';
        for (int xx: ans[i]) cout << ' ' << xx;
        cout << endl;
    }
    return 0;
}
