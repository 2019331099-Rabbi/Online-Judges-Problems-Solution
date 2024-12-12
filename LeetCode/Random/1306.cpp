#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

bool canReach(vector<int>& arr, int start)
{
    int n = arr.size();
    queue <int> q;
    bool vis[n] = {false};

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!arr[u]) return true;

        int newPos = u + arr[u];
        if (newPos < n && newPos >= 0 && !vis[newPos]) q.push(newPos), vis[newPos] = true;
        newPos = u - arr[u];
        if (newPos < n && newPos >= 0 && !vis[newPos]) q.push(newPos), vis[newPos] = true;
    }
    return false;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int strt = 5;

    cout << canReach(arr, strt) << endl;


}