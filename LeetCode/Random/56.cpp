#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

vector <vector <int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());

    int left = intervals[0][0], right = intervals[0][1];
    vector <vector <int>> mergedIntervals;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] > right) {
            mergedIntervals.push_back({left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
        else right = max(intervals[i][1], right);
    }
    mergedIntervals.push_back({left, right});
    return mergedIntervals;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <vector <int>> intervals = {
        {1, 10},
        {5, 6},
        {15, 18},
    };
    auto result = merge(intervals);
    for (int i = 0; i < result.size(); i++)
        cout << result[i][0] << ' ' << result[i][1] << endl;
    return 0;
}