#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 25
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};
//int col[]={1, -1, 0, 0};

int main ()
{
    RUN_FAST; cin.tie(nullptr);
    int i, arr[9], ansi[6], mn;
    vector <string> anss;
    anss.push_back("BCG");
    anss.push_back("BGC");
    anss.push_back("CBG");
    anss.push_back("CGB");
    anss.push_back("GBC");
    anss.push_back("GCB");
    while (cin >> i) {
        arr[0]=i;
        for (i=1; i<9; i++) cin >> arr[i];
        ansi[0]=arr[3]+arr[6]+arr[2]+arr[8]+arr[1]+arr[4];
        ansi[1]=arr[3]+arr[6]+arr[1]+arr[7]+arr[2]+arr[5];
        ansi[2]=arr[5]+arr[8]+arr[0]+arr[6]+arr[1]+arr[4];
        ansi[3]=arr[5]+arr[8]+arr[1]+arr[7]+arr[0]+arr[3];
        ansi[4]=arr[4]+arr[7]+arr[0]+arr[6]+arr[2]+arr[5];
        ansi[5]=arr[4]+arr[7]+arr[2]+arr[8]+arr[0]+arr[3];
        mn=1000000000;
        for (i=0; i<6; i++) mn=min(mn, ansi[i]);
        for (i=0; i<6; i++)
            if (ansi[i]==mn) {
                cout << anss[i] << ' ' << mn << endl;
                break;
            }
    }
    return 0;
}
