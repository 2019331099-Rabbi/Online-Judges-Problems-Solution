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
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};

    vector <int> goDirection(int xi, int yi, int xf, int yf, int direction, vector<vector<int>>& matrix)
    {
        vector <int> nodes;
        while (true) {
            nodes.push_back(matrix[xi][yi]);
            xi += row[direction];
            yi += col[direction];
            if (xi == xf && yi == yf) break;
        }
        return nodes;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> spriralValues;
        int n = matrix.size(), m = matrix[0].size();
        int cnt = min((n + 1) / 2, (m + 1) / 2);
        int xi = 0, yi = 0, xf, yf;
        int completed = 0;
        vector <int> nodes;

        while (cnt--) {
            xf = xi, yf = m - completed;
            if (yi < yf) {
                nodes = goDirection(xi, yi, xf, yf, 0, matrix);
                for (auto xx: nodes) spriralValues.push_back(xx);
            }
            else break;
            

            xi = xf + 1, yi = yf - 1;
            xf = n - completed, yf = yi;
            if (xi < xf) {
                nodes = goDirection(xi, yi, xf, yf, 1, matrix);
                for (auto xx: nodes) spriralValues.push_back(xx);
            }
            else break;
            

            xi = xf - 1, yi = yf - 1;
            xf = xi, yf = completed - 1;
            if (yi > yf) {
                nodes = goDirection(xi, yi, xf, yf, 2, matrix);
                for (auto xx: nodes) spriralValues.push_back(xx);
            }
            else break;
            
            

            xi = xf - 1, yi = yf + 1;
            xf = completed, yf = yi;
            if (xi > xf) {
                nodes = goDirection(xi, yi, xf, yf, 3, matrix);
                for (auto xx: nodes) spriralValues.push_back(xx);
            }
            else break;

            completed++;
            xi = yi = completed;
        }
        return spriralValues;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <vector <int>> matrix = {
        // {5, 6, 7, 11},
        // {9, 10, 11, 12},
        // {13, 14, 15, 13}
        {1}, {2}, {3}
        // // { 1,  2,  3,  4}
    };

    vector <int> spiralValues = soln->spiralOrder(matrix);
    for (auto xx: spiralValues) cout << xx << ' ';
    cout << endl;

    return 0;
}