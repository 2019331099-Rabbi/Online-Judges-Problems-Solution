#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


bool isPalindrome(int x)
{
    if (x == 0) return true;
    if (x < 0) return false;

    vector <int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    
    int i = 0, j = v.size() - 1;
    while (i < j) {
        if (v[i] != v[j]) return false;
        i++, j--;
    }
    return true;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int x;
    cin >> x;
    cout << isPalindrome(x) << endl;
}