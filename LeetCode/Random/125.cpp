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

bool isPalindrome(string s)
{
    int left = 0, right = s.size() - 1;
    while (left < right) {
        
        if (isalnum(s[left]) && isalnum(s[right])) {
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++, right--;

        }
        else if (isalnum(s[left])) right--;
        else left++;
        
    }
    return true;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    string s = "A man, a plan, a canal: Panama";

    cout << isPalindrome(s) << endl;
    return 0;
    
}