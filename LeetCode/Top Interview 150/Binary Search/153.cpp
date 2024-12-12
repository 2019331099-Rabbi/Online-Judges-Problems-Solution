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
In this approach, first we find the peak.
4, 5, 6, 7, 0, 1, 2
Here 7 is the peak element. Becuse it the largest. Since the array is rotated, the next element of the largest
element must be the minimum element. Steps:
1. if (nums[left] > nums[mid]) right = mid - 1;
    In binary search, we split the array in two parts. For example
    4, 5, 6, 7, 0, 1, 2: Here mid is 7. 
    1st part 4, 5, 6, 7
    2nd part 7, 0, 1, 2

    First part is already sorted. We don't get the min element here. So we select the 2nd part
    Why?
    4, 5, 6, 7.......increasing. May be at some point 4, 5, 6, 7................0, 1, 2...
    So we will select the 2nd part.
*/

// class Solution {
// public:
//     int findPeak(vector <int> &nums) {
//         int n = nums.size();
//         if (n == 1) return 0;

//         int left = 0, right = n - 2;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (nums[left] > nums[mid]) right = mid - 1;
//             else {
//                 if (nums[mid] > nums[mid + 1]) return mid;
//                 else left = mid + 1;
//             }
//         }
//         return n - 1;
//     }

//     int findMin(vector<int>& nums) {
//         int peak = findPeak(nums);
//         return (peak + 1 == nums.size())?nums[0]:nums[peak + 1];
//     }
// };

// Alternative approach
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) left = mid + 1; // right part is unsorted
            else right = mid; // Take the left part including the mid. May be mid the smallest. So include it
        }
        return nums[left];
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {3, 1, 2};
    cout << soln->findMin(nums) << endl;
    return 0;
}