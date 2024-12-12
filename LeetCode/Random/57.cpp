#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    int len = intervals.size();
    vector <vector <int>> finalIntervals;

    for (int i = 0; i < len; i++) {
        if (newInterval[1] < intervals[i][0]) {
            finalIntervals.push_back(newInterval);
            while (i < len) finalIntervals.push_back(intervals[i]), i++;
            return finalIntervals;
        }
        else if (newInterval[0] > intervals[i][1]) finalIntervals.push_back(intervals[i]);
        else newInterval[0] = min(newInterval[0], intervals[i][0]), newInterval[1] = max(newInterval[1], intervals[i][1]);
    }
    finalIntervals.push_back(newInterval);
    return finalIntervals;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <vector <int>> intervals = {{1, 3}, {6, 9}, {10, 12}};
    vector <int> newInterval = {2, 7};


    auto finalIntervals = insert(intervals, newInterval);
    for (auto xx: finalIntervals) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }

    return 0;
}