#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf -1e9
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int ternarySearch(int l, int r, int key, vector <int> &arr)
{
    if (l <= r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
 
        
        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;
 
        if (key < arr[mid1]) r = mid1 - 1;
        else if (key > arr[mid2]) l = mid2 + 1;
        else l = mid1 + 1, r = mid2 - 1;
    }
    return -1;
}

vector <vector <int>> threeSum(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    int prev = inf, len = arr.size();

    vector <vector <int>> res;
    for (int i = 0; i < len - 2; i++) {
        if (arr[i] == prev) continue;

        int l = i + 1, r = len - 1;
        int key = -arr[i];

        int prevl = inf, prevr = inf;
        while (l < r) {
            if (arr[l] == prevl && arr[r] == prevr) {
                l++, r--;
                continue;
            }
            if (arr[l] + arr[r] == key) {
                res.push_back({arr[i], arr[l], arr[r]});
                prevl = arr[l], prevr = arr[r];
                l++, r--;
            }
            else if (arr[l] + arr[r] < key) l++;
            else r--;

        }
        prev = arr[i];
    }
    return res;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int n;
    vector <int> v;

    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    threeSum(v);
}