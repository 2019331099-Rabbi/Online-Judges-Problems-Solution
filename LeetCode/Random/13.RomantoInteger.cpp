#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int arr[26];

void init()
{
    arr['I' - 'A'] = 1;
    arr['V' - 'A'] = 5;
    arr['X' - 'A'] = 10;
    arr['L' - 'A'] = 50;
    arr['C' - 'A'] = 100;
    arr['D' - 'A'] = 500;
    arr['M' - 'A'] = 1000;
}

int romanToInt(string s)
{
    s += 'I';
    int sum = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        int num1 = arr[s[i] - 'A'];
        int num2 = arr[s[i + 1] - 'A'];
        if (num1 >= num2) sum += num1;
        else sum -= num1;
    }
    return sum;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    string s;
    
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}