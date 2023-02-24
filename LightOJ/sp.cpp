#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 50000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <pair <int, int>> pr;
vector <vector <int>> tree(3 * sz);

struct comp {
    int operator()(const pair<int,int>&mypair,const int& n) 
    {
        if(mypair.first < n) return 1;
        return 0;
    }
    int operator()(const int& n,const pair<int,int>& mypair) 
    {
        if(n < mypair.first) return 1;
        return 0;
    }
};

void merge(int node, int l, int r)
{
    int i, j, lft = l, rgt = r;
    int m = (l + r) >> 1;
    int ls=m-l+1, rs=r-m;
    int larr[ls], rarr[rs];

    for (i=0; i<ls; i++) larr[i]=pr[l+i].second;
    for (i=0; i<rs; i++) rarr[i]=pr[m+1+i].second;

    i=j=0;
    while (i<ls && j<rs) {
        if (larr[i]<=rarr[j]) pr[l++].second=larr[i++];
        else pr[l++].second=rarr[j++];
    }
    while (i<ls) pr[l++].second=larr[i++];
    while (j<rs) pr[l++].second=rarr[j++];

    for (i = lft; i <= rgt; i++) tree[node].push_back(pr[i].second);
}

void mergesort(int node, int l, int r)
{
    if (l >= r) {
        if (l == r) tree[node].push_back(pr[l].second);
        return;
    }

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) >> 1;

    mergesort(a, l, m);
    mergesort(b, m + 1, r);
    merge(node, l, r);
}

void solve(int T)
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int val1, val2;
        cin >> val1 >> val2;
        pr.push_back({val1, val2});
    }

    sort(pr.begin(), pr.end());
    for (auto xx: pr) cout << xx.second << ' ';
    cout << endl;

    mergesort(1, 0, n - 1);
    for (auto xx: pr) cout << xx.second << ' ';
    cout << endl;

    for (int i = 1; i <= 17; i++) {
        cout << i << ": ";
        for (auto xx: tree[i]) cout << xx << ' ';
        cout << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}