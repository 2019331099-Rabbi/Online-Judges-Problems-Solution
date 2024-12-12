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

vector <vector <int>> threeSum(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    vector <vector <int>> res;

    int len = arr.size();
    for (int i = 0; i < len; i++) {
        int val = arr[i];
        if (i > 0 && val == arr[i - 1]) continue;

        int left = i + 1, right = len - 1;
        while (left < right) {
            int sum = val + arr[left] + arr[right];
            if (sum > 0) right--;
            else if (sum < 0) left++;
            else {
                res.push_back({val, arr[left], arr[right]});
                left++;
                while (left < right && arr[left] == arr[left-1]) left++;
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector <int> v;

    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    auto result = threeSum(v);
    for (auto xx: result) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }
}