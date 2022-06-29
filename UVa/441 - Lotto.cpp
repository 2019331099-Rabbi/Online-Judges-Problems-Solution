#include <bits/stdc++.h>
#define endl '\n'
#define sz 26
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, a, b, c, d, e, f;
    bool flag=false;
    while (cin >> n && n) {
        if (flag) cout << endl;
        flag=true;
        int arr[n];
        for (a=0; a<n; a++) cin >> arr[a];
        for (a=0; a<n; a++) {
            for (b=a+1; b<n; b++) {
                for (c=b+1; c<n; c++) {
                    for (d=c+1; d<n; d++) {
                        for (e=d+1; e<n; e++) {
                            for (f=e+1; f<n; f++)
                                cout << arr[a] << ' ' << arr[b] << ' ' << arr[c] << ' ' << arr[d] << ' ' << arr[e] << ' ' << arr[f] << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
