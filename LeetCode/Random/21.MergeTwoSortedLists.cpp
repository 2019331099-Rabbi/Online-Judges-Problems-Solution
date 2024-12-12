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
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode *head1, *head2, *curr;
    if (list1->val <= list2->val) {
        head1 = list1->next;
        head2 = list2;
        curr = list1;
    }
    else {
        head2 = list2->next;
        head1 = list1;
        curr = list2;
    }
    
    while (head1 || head2) {
        if (head1 == nullptr || head2 == nullptr) {
            if (head1) curr->next = head1, head1 = head1->next;
            else curr->next = head2, head2 = head2->next;
        }
        else if (head1->val <= head2->val) {
            curr->next = head1;
            head1 = head1->next;
        }
        else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    return (list1->val <= list2->val)?list1:list2;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;

    // Insert values into l1
    // insertNode(l1, 2);
    // insertNode(l1, 3);
    // insertNode(l1, 4);
    // insertNode(l1, 6);
    // insertNode(l1, 5);
    
    

    // Insert values into l2
    // insertNode(l2, 5);
    // insertNode(l2, 8);
    insertNode(l2, 9);

    ListNode *result = mergeTwoLists(l1, l2);
    // printList(l1);
    // printList(l2);
    printList(result);

    return 0;
    
}