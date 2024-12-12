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

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int len = height.size(), right, left;
//         vector <int> sum = height;
//         for (int i = 1; i < len; i++) sum[i] += sum[i - 1];

//         int water = 0;
//         stack <int> stk;
//         for (right = 0; right < len; right++) {
//             if (stk.empty() || height[stk.top()] >= height[right]) stk.push(right);
//             else {
//                 while (stk.size() > 1 && height[stk.top()] <= height[right]) stk.pop();
//                 if (height[stk.top()] <= height[right]) {
//                     left = stk.top();
//                     water += (right - left - 1) * height[left] - (sum[right - 1] - sum[left]);
//                     stk.pop();
//                 }
//                 stk.push(right);
//             }
//         }
//         while (stk.size() > 1) {
//             right = stk.top();
//             stk.pop();
//             left = stk.top();
//             water += (right - left - 1) * height[right] - (sum[right - 1] - sum[left]);
//         }
//         return water;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int mxLeft = height[0], mxRight = height[height.size() - 1];
        int left = 1, right = height.size() - 2;
        int totalWater = 0;

        while (left <= right) {
            if (mxLeft <= mxRight) {
                totalWater += max(0, mxLeft - height[left]);
                mxLeft = max(mxLeft, height[left]);
                left++;
            }
            else {
                totalWater += max(0, mxRight - height[right]);
                mxRight = max(mxRight, height[right]);
                right--;
            }
        }
        return totalWater;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> height = {4, 2, 0, 3, 2, 5, 2, 3, 0, 2};

    cout << soln->trap(height) << endl;


}