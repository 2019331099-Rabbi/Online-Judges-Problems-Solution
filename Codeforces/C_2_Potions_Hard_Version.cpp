#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200000
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int main()
{
    RUN_FAST; cin.tie(nullptr);

    int n;
    priority_queue <int, vector <int>, greater <int>> pq;
    
    cin >> n;
    int64_t sum = 0, ans = 0;
    while (n--) {
        int64_t val;
        cin >> val;
        if (val < 0) pq.push(val);
        
        sum += val, ans++;
        while (sum < 0) {
            sum -= pq.top();
            pq.pop();
            ans--;
        }
    }
    cout << ans << endl;
}