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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Method 1: With two iteration
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *currNode = head;
//         int len = 0;
//         while (currNode) {
//             len++;
//             currNode = currNode->next;
//         }
//         len -= n;
//         ListNode *dummyHead = new ListNode(0, head);
//         currNode = dummyHead;
//         while (len--) currNode = currNode->next;
//         currNode->next = currNode->next->next;

//         return dummyHead->next;
//     }
// };

// Method 2: With one iteration
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *currNode = dummyHead, *prevNode = dummyHead;

        while (n--) currNode = currNode->next;
        while (currNode->next) currNode = currNode->next, prevNode = prevNode->next;
        prevNode->next = prevNode->next->next;
        return dummyHead->next;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    ListNode *node0 = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    // ListNode *node2 = new ListNode(3);
    // ListNode *node3 = new ListNode(4);
    // ListNode *node4 = new ListNode(5);
    node0->next = node1;
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;

    int n = 2;
    
    Solution *soln = new Solution();
    ListNode *res = soln->removeNthFromEnd(node0, n);
    while (res) {
        cout << res->val << ' ';
        res = res->next;
    }
    cout << endl;
    return 0;
}