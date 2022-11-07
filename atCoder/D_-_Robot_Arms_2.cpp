#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 20010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int x, y;
vector <int> forx, fory;
const int adder = 10000;

int memo[1001][sz];

void init()
{
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) memo[i][j] = -inf;
    }
}

int coinChange1(int pos, int amount)
{
    if (pos == forx.size()) {
        if (amount == 0) return 0;
        else return inf;
    }
    if (memo[pos][amount + adder] != -inf) return memo[pos][amount + adder];

    int val1 = 1 + coinChange1(pos + 1, amount - forx[pos]);
    int val2 = coinChange1(pos + 1, amount);
    return memo[pos][amount + adder] = min(val1, val2);
}

int coinChange2(int pos, int amount)
{
    if (pos == fory.size()) {
        if (amount == 0) return 0;
        else return inf;
    }
    if (memo[pos][amount + adder] != -inf) return memo[pos][amount + adder];

    int val1 = 1 + coinChange2(pos + 1, amount - fory[pos]);
    int val2 = coinChange2(pos + 1, amount);
    return memo[pos][amount + adder] = min(val1, val2);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, x, y;

    cin >> n >> x  >> y;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (i & 1) fory.push_back(val), fory.push_back(-val);
        else forx.push_back(val), forx.push_back(-val);
    }

    for (auto xx: forx) cout << xx << ' ';
    cout << endl;
    for (auto xx: fory) cout << xx << ' ';
    cout << endl;

    init();
    int cnt1 = coinChange1(0, x);
    cout << cnt1 << endl;
    init();
    int cnt2 = coinChange2(0, y);
    cout << cnt2 << endl;
}