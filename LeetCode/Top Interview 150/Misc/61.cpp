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

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (head == nullptr || head->next == nullptr) return head;
//         int len = 0;
//         ListNode *currNode = head, *tail = nullptr;
//         while (currNode) {
//             len++;
//             tail = currNode;
//             currNode = currNode->next;
//         }
        
//         k %= len;
//         k = len - k;
//         while (k--) {
//             cout << head->val << ' ' << tail->val << endl;
//             currNode = head->next;
//             tail->next = head;
//             tail = tail->next;
//             tail->next = nullptr;
//             head = currNode;
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        int len = 0;
        ListNode *currNode = head, *tail = nullptr;
        while (currNode) {
            len++;
            tail = currNode;
            currNode = currNode->next;
        }
        tail->next = head;
        
        k %= len;
        k = len - k;
        ListNode *prevNode = nullptr;
        while (k--) {
            prevNode = head;
            head = head->next;
        }
        prevNode->next = nullptr;
        return head;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);

    // Creating each node separately
    ListNode* node1 = new ListNode(1);
    // ListNode* node2 = new ListNode(2);
    // ListNode* node3 = new ListNode(3);
    // ListNode* node4 = new ListNode(4);
    // ListNode* node5 = new ListNode(5);
    // ListNode* node6 = new ListNode(2);
    // ListNode* node7 = new ListNode(3);

    // Linking the nodes together
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    // node5->next = node6;
    // node6->next = node7;
    // node7->next = nullptr;

    ListNode* head = node1;

    Solution *soln = new Solution();
    head = soln->rotateRight(head, 3);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;

    return 0;

}