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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *leftNode = dummyHead, *rightNode = head;

        int cnt = 0;
        while (rightNode) {
            cnt++;
            if (cnt == k) {
                ListNode *tmp = rightNode->next;
                rightNode->next = nullptr;
                pair <ListNode*, ListNode*> nodes = reverseList(leftNode->next);

                leftNode->next = nodes.first;
                nodes.second->next = tmp;
                
                leftNode = nodes.second;
                rightNode = tmp;

                cnt = 0;
            }
            else rightNode = rightNode->next;
        }
        return dummyHead->next;
    }

    pair <ListNode*, ListNode*> reverseList(ListNode *head) {
        ListNode *currNode = head;
        ListNode *prevNode = nullptr;
        while (currNode) {
            ListNode *tmp = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = tmp;
        }
        return {prevNode, head};
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    ListNode *node7 = new ListNode(7);
    ListNode *node8 = new ListNode(8);
    ListNode *node9 = new ListNode(9);
    ListNode *node10 = new ListNode(10);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    ListNode *newHead = soln->reverseKGroup(node1, 4);
    while (newHead) {
        cout << newHead->val << ' ';
        newHead = newHead->next;
    }
    cout << endl;
    
}