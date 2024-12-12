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

vector<int> twoSum(vector<int>& numbers, int target)
{
    int left = 0, right = numbers.size();

    while (1) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) return {left+1, right+1};
        if (sum > target) right--;
        else left++;
    }
    return {-1, -1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector <int> result = twoSum(numbers, target);

    for (auto xx: result) cout << xx << ' ';
    cout << endl;
}