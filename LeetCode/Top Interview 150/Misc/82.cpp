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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyHead = new ListNode(-200, head);
        ListNode *prev = dummyHead;

        while (head) {
            int val = head->val;
            while (head && head->val == val) head = head->next;
            if (prev->next->next == head) prev = prev->next;
            else prev->next = head;
        }
        return dummyHead->next;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);

    // Creating each node separately
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(1);
    ListNode* node6 = new ListNode(2);
    ListNode* node7 = new ListNode(3);

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
    head = soln->deleteDuplicates(head);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;

    return 0;

}