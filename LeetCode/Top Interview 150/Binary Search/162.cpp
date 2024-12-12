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
Lets an array {2, 3, 4}
mid = 1; Now which direction we will go to find out expected peak?
1. 2 3 4 -> mid 3 -> As numbers are increasing, we will go forward (left = mid + 1)
2. 2 4 3 -> mid 4 -> Here mid is our expected peak. 4 > 2 and 4 > 3
3. 3 2 4 -> mid 2 -> Here 2 is smallest. In this case we will go forward for expected peak.
4. 3 4 2 -> mid 4 -> Same as case 2
5. 4 2 3 -> Same as case 3
6. 4 3 2 -> Here numbers are decreasing. In this case, we will go backward for the the peak value.
*/

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         int left = 0, right = n - 1;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (mid == 0) {
//                 if (n == 1 || nums[0] > nums[1]) return 0;
//                 else left = 1;
//                 continue;
//             }
//             if (mid == n - 1) return mid;
//             if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
//             if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]) right = mid - 1;
//             else left = mid + 1;
//         }
//         return 0;
//     }
// };

/*
Lets an array {2, 3, 4}
mid = 1; Now which direction we will go to find out expected peak?
1. 2 3 4 -> mid 3 -> As numbers are increasing (3 > 2), we will go forward (left = mid + 1)
2. 2 4 3 -> mid 4 -> Here mid is our expected peak. 4 > 2 and 4 > 3
3. 3 2 4 -> mid 2 -> As numbers are decreasing (3 > 2), we will go backward (right = mid - 1)
4. 3 4 2 -> mid 4 -> Same as case 2
5. 4 2 3 -> Same as case 3
6. 4 3 2 -> Same as case 3
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int left = 1, right = n - 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == n - 1) return mid;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            if (nums[mid] > nums[mid - 1]) left = mid + 1;
            else right = mid - 1;
        }
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {1, 2};
    cout << soln->findPeakElement(nums) << endl;
    return 0;
}