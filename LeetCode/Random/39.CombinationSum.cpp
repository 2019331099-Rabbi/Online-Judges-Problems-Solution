#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 10000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <vector <int>> results;

void backtracking(int pos, int sum, vector<int>&result, int target, vector<int>& candidates)
{
    if (pos == candidates.size()) {
        if (sum == target) results.push_back(result);
        return;
    }
    if (sum + candidates[pos] <= target) {
        result.push_back(candidates[pos]);
        backtracking(pos, sum + candidates[pos], result, target, candidates);
        result.pop_back();
    }
    backtracking(pos + 1, sum, result, target, candidates);
}

vector <vector <int>> combinationSum(vector<int>& candidates, int target)
{
    vector <int> result;
    backtracking(0, 0, result, target, candidates);
    return results;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector <int> candidates;
    int target, n;

    cin >> n >> target;
    while (n--) {
        int val;
        cin >> val;
        candidates.push_back(val);
    }

    combinationSum(candidates, target);

    for (auto xx: results) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }

    return 0;
}