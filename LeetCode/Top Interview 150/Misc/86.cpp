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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Method 1
// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         ListNode *dummyHead = new ListNode(0, head);
//         ListNode *currNode = head, *prevNode = dummyHead;
//         ListNode *leftEnd = dummyHead;
//         while (currNode) {
//             if (currNode->val < x) {
//                 if (leftEnd->next != currNode) {
//                     prevNode->next = currNode->next;

//                     currNode->next = leftEnd->next;
//                     leftEnd->next = currNode;
//                     leftEnd = leftEnd->next;

//                     currNode = prevNode->next;
                    
//                 }
//                 else {
//                     prevNode = currNode;
//                     currNode = currNode->next;
//                     leftEnd = leftEnd->next;
//                 }
//             }
//             else {
//                 prevNode = currNode;
//                 currNode = currNode->next;
//             }
//         }
//         return dummyHead->next;
//     }
// };

// Method 2
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyHeadLeft = new ListNode();
        ListNode *dummyHeadRight = new ListNode();
        ListNode *tailLeft = dummyHeadLeft, *tailRight = dummyHeadRight;
        
        while (head) {
            if (head->val < x) tailLeft->next = head, tailLeft = tailLeft->next;
            else tailRight->next = head, tailRight = tailRight->next;
            head = head->next;
        }
        tailRight->next = nullptr;
        tailLeft->next = dummyHeadRight->next;
        return dummyHeadLeft->next;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);

    // Creating each node separately
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(0);
    ListNode* node5 = new ListNode(2);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(2);

    // Linking the nodes together
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = nullptr;

    ListNode* head = node1;

    Solution *soln = new Solution();
    head = soln->partition(head, 3);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;

    return 0;

}