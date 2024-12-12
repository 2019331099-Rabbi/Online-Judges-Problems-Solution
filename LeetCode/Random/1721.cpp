#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertNode(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    } else {
        ListNode *curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Function to print the linked list
void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

int listLength(ListNode *head)
{
    if (!head) return 0;

    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

ListNode* swapNodes(ListNode* head, int k)
{
    int len = listLength(head);
    if (!len) return head;

    ListNode *node1 = nullptr, *node2 = nullptr, *curr = head;
    int n = len - k + 1, cnt = 0;
    while (curr) {
        cout << head << ' ' << curr << endl;
        cnt++;
        if (cnt == n) node1 = curr;
        if (cnt == k) node2 = curr;
        curr = curr->next;
    }
    swap(node1->val, node2->val);
    return head;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    ListNode *l1 = nullptr;

    // Insert values into l1
    insertNode(l1, 1);
    insertNode(l1, 2);
    insertNode(l1, 3);
    insertNode(l1, 4);
    // insertNode(l1, 5);


    ListNode *result = swapNodes(l1, 3);
    printList(result);

    return 0;
    
}