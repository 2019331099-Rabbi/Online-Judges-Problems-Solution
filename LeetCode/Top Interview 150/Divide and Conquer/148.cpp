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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* findMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                curr = curr->next;
                left = left->next;
            }
            else {
                curr->next = right;
                curr = curr->next;
                right = right->next;
            }
        }
        if (left) curr->next = left;
        else curr->next = right;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);
        head = merge(left, right);
        return head;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    // Create the first list: 1 -> 3 -> 6
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(6);

    

    return 0;
}