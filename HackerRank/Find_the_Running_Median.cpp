#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

priority_queue <int> maxHeap;
priority_queue <int, vector <int>, greater <int>> minHeap;

void addElement(int val)
{
    if (!maxHeap.size()) {
        maxHeap.push(val);
        return;
    }
    if (val > maxHeap.top()) minHeap.push(val);
    else maxHeap.push(val);

    if (maxHeap.size() + 2 == minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    if (minHeap.size() + 2 == maxHeap.size()) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
}

double findMedian()
{
    int len = maxHeap.size() + minHeap.size();
    
    if (len & 1) return ((maxHeap.size() > minHeap.size())?maxHeap.top():minHeap.top());
    return (double)(maxHeap.top() + minHeap.top()) / 2.0;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        addElement(val);
        double ans = findMedian();
        cout << fixed << setprecision(1) << ans << endl;
    }
    return 0;
}