#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

char nextGreatestLetter(vector<char>& letters, char target)
{
    auto it = upper_bound(letters.begin(), letters.end(), target);

    return (it == letters.end())?letters[0]:*it;
}

char upperBound(vector<char>& letters, char target)
{
    int l = 0, r = letters.size() - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (target >= letters[mid]) l = mid + 1;
        else r = mid - 1;
    }
    if (l == letters.size()) return letters[0];
    else return letters[l];
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<char> nums = {'x', 'x', 'y', 'y'};
    char target = 'z';

    cout << nextGreatestLetter(nums, target) << endl;
    cout << upperBound(nums, target) << endl;
}