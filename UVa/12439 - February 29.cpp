#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 5
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, d1, d2, y1, y2, cnt4, i=1;
    string m1, m2, jan="January", feb="February";
    char ch;
    cin >> T;
    while (T--) {
        cin >> m1 >> d1 >> ch >> y1 >> m2 >> d2 >> ch >> y2;
        if (m1!=jan && m1!=feb) y1++;
        if (m2==jan || (m2==feb && d2<29)) y2--;
        y1--;
        cnt4=(y2/4)-(y1/4);
        cnt4-=(y2/100)-(y1/100);
        cnt4+=(y2/400)-(y1/400);
        cout << "Case " << i++ << ": " << cnt4 << endl;
    }
    return 0;
}
