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

ListNode* middleNode(ListNode* head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    ListNode* node6 = new ListNode(6);
    ListNode* node5 = new ListNode(5, node6);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    auto head = middleNode(node1);
    cout << head->val << endl;

    // Print the list to verify
    // ListNode* current = node1;
    // while (current != nullptr) {
    //     std::cout << current->val << " ";
    //     current = current->next;
    // }

    // // Clean up the memory (if necessary)
    // current = node1;
    // ListNode* next;
    // while (current != nullptr) {
    //     next = current->next;
    //     delete current;
    //     current = next;
    // }

    return 0;
}