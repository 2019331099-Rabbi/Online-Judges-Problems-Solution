#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void eventualSafeNodes(vector<vector<int>>& rooms)
{
    int nodes = rooms.size();

    queue <int> q;
    vector <bool> open(nodes);

    open[0] = true;
    q.push(0);
    while (!q.empty()) {
        nodes--;
        int u = q.front();
        q.pop();
        for (auto xx: rooms[u]) {
            if (!open[xx]) {
                q.push(xx);
                open[xx] = true;
            }
        }
    }
    
    cout << nodes << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    // vector <vector <int>> adj = {
    //     {1, 2},
    //     {2, 3},
    //     {5},
    //     {0},
    //     {5},
    //     {},
    //     {}
    // };
    vector <vector <int>> adj = {
        {1},
        {1}
    };
    

    eventualSafeNodes(adj);
    return 0;
}