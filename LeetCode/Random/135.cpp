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

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector <int> arr(len, 1);

        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) arr[i] = arr[i - 1] + 1;
        }
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) arr[i] = max(arr[i], arr[i + 1] + 1);
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> ratings  = {29,51,87,87,72,12};
    ratings  = {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};

    cout << soln->candy(ratings) << endl;

    return 0;
}