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

class MyQueue {
public:
    stack <int> stk1, stk2;
    MyQueue() {}
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int x = stk2.top();
        stk2.pop();
        return x;
    }
    
    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    MyQueue *myq = new MyQueue();

    myq->push(1);
    myq->push(2);
    cout << myq->peek() << endl;
    myq->push(3);
    cout << myq->pop() << endl;
    myq->push(4);

    cout << myq->pop() << endl;
    cout << myq->pop() << endl;

    
}