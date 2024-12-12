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

/*
Tutorial: https://youtu.be/F9c7LpRZWVQ?si=C6bUVx_X4uyHkH7o
*/

class Solution {
public:
    int lowerBound(int target, vector <pair <int, int>> &nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target <= nums[mid].first) right = mid - 1;
            else left = mid + 1;
        }
        return (left == n)?nums.size():nums[left].second;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector <pair <int, int>> leftIntervals(n);
        for (int i = 0; i < n; i++) leftIntervals[i] = {intervals[i][0], i};
        sort(leftIntervals.begin(), leftIntervals.end());

        vector <int> answers;
        for (int i = 0; i < n; i++) {
            int indx = lowerBound(intervals[i][1], leftIntervals);
            if (indx == n) answers.push_back(-1);
            else answers.push_back(indx);
        }
        return answers;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <vector <int>> intervals = {
        {1, 4},
        {2, 3},
        {3, 4}
    };
    vector <int> rightIntervals = soln->findRightInterval(intervals);
    for (auto xx: rightIntervals) cout << xx << ' ';
    cout << endl;
    return 0;
}