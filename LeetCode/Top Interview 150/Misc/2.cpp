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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *prev = nullptr, *head = nullptr;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *newNode = new ListNode(sum % 10);
            carry = sum / 10;
            if (prev) prev->next = newNode, prev = newNode;
            else head = prev = newNode;
        }
        if (carry) {
            ListNode *newNode = new ListNode(carry);
            prev->next = newNode;
        }
        return head;
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

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution *soln = new Solution();
    ListNode *res = soln->addTwoNumbers(l1, l2);
    soln->printList(res);

    return 0;
}