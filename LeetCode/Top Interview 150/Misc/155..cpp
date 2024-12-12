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

// Method 1
// class MinStack {
// public:

//     stack <int> stk, mnstk;
//     MinStack() {}
    
//     void push(int val)
//     {
//         stk.push(val);
//         if (mnstk.empty()) mnstk.push(val);
//         else mnstk.push(min(val, mnstk.top()));
//     }
    
//     void pop()
//     {
//         stk.pop();
//         mnstk.pop();
//     }
    
//     int top()
//     {
//         return stk.top();
//     }
    
//     int getMin() {
//         return mnstk.top();
//     }
// };

// Method 2
class MinStack {
public:
    stack <pair <int, int>> stk;
    MinStack() {
        stk.push({-1, INT32_MAX});
    }
    
    void push(int val) {
        stk.push({val, min(stk.top().second, val)});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    MinStack *test = new MinStack();

    test->push(2147483646);
    test->push(2147483646);
    test->push(2147483647);

    cout << test->top() << endl;
    test->pop();
    cout << test->getMin() << endl;
    test->pop();
    cout << test->getMin() << endl;
    test->pop();

    test->push(2147483647);
    
    cout << test->top() << endl;
    cout << test->getMin() << endl;
    return 0;

}