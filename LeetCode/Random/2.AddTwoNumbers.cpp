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

void insertNode(ListNode *&head, int val) {
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *head1 = l1, *head2 = l2, *result = nullptr;

    int carry = 0;
    while (head1 || head2) {
        int sum;
        if (head1 && head2) sum = head1->val + head2->val;
        else sum = (head1)?head1->val:head2->val;

        sum += carry, carry = 0;
        if (sum >= 10) carry = 1, sum %= 10;
        insertNode(result, sum);

        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }
    if (carry) insertNode(result, carry);
    return result;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;

    // Insert values into l1
    insertNode(l1, 9);
    insertNode(l1, 9);
    insertNode(l1, 9);
    insertNode(l1, 9);
    

    // Insert values into l2
    insertNode(l2, 9);
    insertNode(l2, 9);
    insertNode(l2, 9);

    ListNode *result = addTwoNumbers(l1, l2);
    printList(l1);
    printList(l2);
    printList(result);

    return 0;
    
}