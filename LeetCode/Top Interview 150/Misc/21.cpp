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

auto init = []() -> int {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                dummy->next = list1;
                list1 = list1->next;
            }
            else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = (list1)?list1:list2;
        return head->next;
    }

    void printList(ListNode *root) {
        while (root) {
            cout << root->val << ' ';
            root = root->next;
        }
        cout << endl;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution *soln = new Solution();
    ListNode *res = soln->mergeTwoLists(l1, l2);
    soln->printList(res);

    return 0;
}