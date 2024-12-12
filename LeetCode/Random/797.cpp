#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <vector <int>> answers;

void dfs(int strt, vector <int> &ans, vector<vector<int>>& graph)
{
    if (strt == graph.size() - 1) {
        answers.push_back(ans);
        return;
    }
    for (auto xx: graph[strt]) {
        ans.push_back(xx);
        dfs(xx, ans, graph);
        ans.pop_back();
    }
}

vector <vector <int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    int nodes = graph.size();
    vector <int> v = {0};
    dfs(0, v, graph);
    return answers;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};

    auto result = allPathsSourceTarget(graph);

    for (auto xx: result) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }
}

// 118.179.223.10
// 202.4.96.6