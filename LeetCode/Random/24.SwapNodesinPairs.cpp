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

ListNode* swapPairs(ListNode* head)
{
    ListNode *curr = head, *prev = curr;
    
    int cnt = 0;
    while (true) {
        if (!curr || !curr->next) break;
        
        curr = curr->next;
        if (!curr) break;
        swap(curr->val, prev->val);
        
        curr = curr->next;
        prev = curr;
    }
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
    // insertNode(l1, 4);
    

    ListNode *result = swapPairs(l1);
    printList(result);

    return 0;
    
}