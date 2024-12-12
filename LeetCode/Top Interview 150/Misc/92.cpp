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


// Method 1: O(N) space
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         int cnt = 1;
//         ListNode *currNode = head;
//         stack <int> stk;
//         while (currNode) {
//             if (cnt >= left && cnt <= right) stk.push(currNode->val);
//             cnt++;
//             currNode = currNode->next;
//         }
//         currNode = head;
//         cnt = 1;
//         while (currNode) {
//             if (cnt >= left && cnt <= right) {
//                 currNode->val = stk.top();
//                 stk.pop();
//             }
//             currNode = currNode->next;
//             cnt++;
//         }
//         return head;
//     }
// };

// Method 2: Constant space
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         int cnt = 1;
//         ListNode *currNode = head;
//         ListNode *a = nullptr, *b = nullptr;
//         while (currNode) {
//             if (cnt == left) a = currNode;
//             if (cnt == right + 1) {
//                 b = currNode;
//                 break;
//             }
//             currNode = currNode->next;
//             cnt++;
//         }
//         cnt = left;
//         while (cnt <= right) {
//             currNode = a->next;
//             a->next = b;
//             b = a;
//             a = currNode;
//             cnt++;
//         }
//         if (left == 1) return b;
//         cnt = 1;
//         currNode = head;
//         while (cnt < left) {
//             if (cnt == left - 1) currNode->next = b;
//             currNode = currNode->next;
//             cnt++;
//         }
//         return head;
//     }
// };

// Method 3: Constant space
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         int cnt = 1;
//         ListNode *newNext = nullptr, *currNode = head, *tmp, *a, *b, *c, *d;
//         a = b = c = d = nullptr;
//         while (currNode) {
//             tmp = currNode->next;
//             if (cnt >= left && cnt <= right) {
//                 currNode->next = newNext;
//                 if (cnt == left) c = currNode;
//                 if (cnt == right) d = currNode;
//                 newNext = currNode;
//             }
//             else if (cnt == left - 1) a = currNode;
//             else if (cnt == right + 1) {
//                 b = currNode;
//                 break;
//             }
//             currNode = tmp;
//             cnt++;
//         }
//         if (a) a->next = d;
//         if (c) c->next = b;
//         return (left == 1)?d:head;
//     }
// };

// Method 4: Constant space
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *currNode = head;
        ListNode *leftPre = dummyHead;

        for (int i = 1; i < left; i++) currNode = currNode->next, leftPre = leftPre->next;
        ListNode *preNode = nullptr;
        ListNode *subListHead = currNode;
        while (left <= right) {
            ListNode *nextNode = currNode->next;
            currNode->next = preNode;
            preNode = currNode;
            currNode = nextNode;
            left++;
        }
        leftPre->next = preNode;
        subListHead->next = currNode;
        return dummyHead->next;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);

    ListNode *node0 = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    int left = 2, right = 4;
    
    Solution *soln = new Solution();
    ListNode *res = soln->reverseBetween(node0, left, right);
    while (res) {
        cout << res->val << ' ';
        res = res->next;
    }
    cout << endl;
    return 0;
}