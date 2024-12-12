#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 10000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    reverse(matrix.begin(), matrix.end());
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j <= i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }

    for (auto xx: matrix) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }

    rotate(matrix);
    cout << endl;

    for (auto xx: matrix) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }

    


}