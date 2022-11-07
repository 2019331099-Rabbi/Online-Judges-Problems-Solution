#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 100000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

vector <pair <int, pair <int, int>>> pr;
int cnt = 0;

void merge(int arr[], int left, int right, int mid)
{
    int i, j;
    int ls=mid-left+1, rs=right-mid;
    int larr[ls], rarr[rs];

    for (i=0; i<ls; i++) larr[i]=arr[left+i];
    for (i=0; i<rs; i++) rarr[i]=arr[mid+1+i];

    i=j=0;
    while (i<ls && j<rs) {
        if (larr[i]<=rarr[j]) arr[left++]=larr[i++];
        else arr[left++]=rarr[j++];
    }
    if (j) cnt++;

    while (i<ls) arr[left++]=larr[i++];
    while (j<rs) arr[left++]=rarr[j++];
}

void mergesort(int arr[], int left, int right)
{
    if (left>=right) return;
    int mid=((left+right)>>1);
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);

    int mx = -inf, mn = inf;
    for (int i = left; i <= right; i++) mx = max(mx, arr[i]), mn = min(mn, arr[i]);
    pr.push_back({right - left + 1, {mn, mx}});
    


    merge(arr, left, right, mid);
}

void solve()
{
    int n;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    mergesort(arr, 0, n - 1);

    map <int, vector <pair <int, int>>> mp;
    for (auto xx: pr) mp[xx.first].push_back({xx.second.first, xx.second.second});

    bool flag = true;
    for (auto xx: mp) {
        // cout << xx.first << endl;
        vector <pair <int, int>> tmpr = xx.second;
        sort(tmpr.begin(), tmpr.end());
        // for (auto xx: tmpr) cout << xx.first << ' ' << xx.second << endl;

        for (int i = 1; i < tmpr.size(); i++) {
            if (tmpr[i].first < tmpr[i - 1].second) {
                flag = false;
                break;
            }
        }
    }
    pr.clear();
    if (n == 1) {
        cout << 0 << endl;
        cnt = 0;
        return;
    }
    if (!flag) cout << -1 << endl;
    else cout << cnt << endl;
    cnt = 0;

}




int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}