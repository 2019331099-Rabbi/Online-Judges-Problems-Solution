#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};
//                1  2  3  4  5  6  7  8  9 10 11
bool arr[] = {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

bool isBadVersion(int version)
{
    return arr[version];
}

int firstBadVersion(int n)
{
    unsigned int left = 1, right = n;

    while (left <= right) {
        int mid = (left + right) >> 1;

        if (isBadVersion(mid)) right = mid - 1;
        else left = mid + 1;
    }
    cout << left << ' ' << right << endl;
    return left;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cout << firstBadVersion(11) << endl;

}