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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        int reqN = total / 2;
        int partition;

        int left = 0, right = reqN - 1;
        int mid1, mid2;
        int l1, l2, r1, r2;
        while (left <= right) {
            mid1 = (left + right) / 2;
            mid2 = reqN - mid1;

            if (mid1 > n) right = mid1 - 1;
            else if (mid2 > m) left = mid1 + 1;
            else {
                l1 = (mid1 >= 1 && mid1 <= n)?nums1[mid1 - 1]:INT32_MIN;
                l2 = (mid2 >= 1 && mid2 <= m)?nums2[mid2 - 1]:INT32_MIN;
                r1 = (mid1 < n)?nums1[mid1]:INT32_MAX;
                r2 = (mid2 < m)?nums2[mid2]:INT32_MAX;
                if (l1 > r2) right = mid1 - 1;
                else if (l2 > r1) left = mid1 + 1;
                else {
                    left = mid1;
                    break;
                }
            }
            
        }

        mid1 = left, mid2 = reqN - mid1;
        r1 = (mid1 < n)?nums1[mid1]:INT32_MAX;
        r2 = (mid2 < m)?nums2[mid2]:INT32_MAX;
        if (total % 2 == 0) {
            l1 = (mid1 >= 1 && mid1 <= n)?nums1[mid1 - 1]:INT32_MIN;
            l2 = (mid2 >= 1 && mid2 <= m)?nums2[mid2 - 1]:INT32_MIN;
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else {
            r1 = (mid1 < n)?nums1[mid1]:INT32_MAX;
            r2 = (mid2 < m)?nums2[mid2]:INT32_MAX;
            return min(r1, r2);
        }
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    int n, m;
    cin >> n >> m;
    vector <int> nums1(n);
    vector <int> nums2(m);

    for (auto &num: nums1) cin >> num;
    for (auto &num: nums2) cin >> num;
    
    cout << soln->findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}