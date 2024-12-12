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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
Method 1: Using hasinng
O(N) extra memory
*/
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map <Node*, Node*> nodeMap;
//         Node *newHead = new Node(0);
//         Node *prevNode = newHead;

//         while (head) {
//             Node *currNode;
//             if (nodeMap.find(head) != nodeMap.end()) currNode = nodeMap[head];
//             else {
//                 currNode = new Node(head->val);
//                 nodeMap[head] = currNode;
//             }

//             prevNode->next = currNode;
            
//             if (head->random) {
//                 Node *random;
//                 if (nodeMap.find(head->random) != nodeMap.end()) random = nodeMap[head->random];
//                 else random = new Node(head->random->val);
//                 currNode->random = random;
//                 nodeMap[head->random] = random;
//             }
//             nodeMap[head] = currNode;
//             head = head->next;
//             prevNode = prevNode->next;
//         }
        
//         return newHead->next;
//     }
// };


/*
Method 2: Using hashing, a simplified approach:
O(N) extra memory
*/
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node *newHead = new Node(-1);
//         Node *currNode = newHead;

//         unordered_map <Node*, Node*> nodeMap;
//         Node *curr = head;
//         while (curr) {
//             currNode->next = new Node(curr->val);
//             currNode = currNode->next;
//             nodeMap[curr] = currNode;
//             curr = curr->next;
//         }

//         curr = head;
//         while (curr) {
//             if (curr->random) {
//                 currNode = nodeMap[curr];
//                 currNode->random = nodeMap[curr->random];
//                 nodeMap[curr] = currNode;
//             }
//             curr = curr->next;
//         }
//         return newHead->next;
//     }
// };

/*
Method 3: Constant space
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        
        Node *curr = head;
        while (curr) {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node *newHead = head->next;
        Node *newCurr = newHead;
        while (curr) {
            curr->next = newCurr->next;
            curr = curr->next;
            if (curr) newCurr->next = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);

    Node *node0 = new Node(7);
    Node *node1 = new Node(13);
    Node *node2 = new Node(11);
    Node *node3 = new Node(10);
    Node *node4 = new Node(1);
    node0->next = node1;
    node1->next = node2, node1->random = node0;
    node2->next = node3, node2->random = node4;
    node3->next = node4, node3->random = node2;
    node4->random = node0;
    

    Solution *soln = new Solution();
    Node *res = soln->copyRandomList(node0);
    while (res) {
        cout << res->val << ' ';
        if (res->random) cout << res->random->val;
        cout << endl;
        res = res->next;
    }
    return 0;
}