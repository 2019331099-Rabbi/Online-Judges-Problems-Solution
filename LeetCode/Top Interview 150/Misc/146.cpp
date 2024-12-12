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

struct Node {
    int key;
    int val;
    Node *next, *prev;
    Node() : key(-1), val(-1), next(nullptr), prev(nullptr) {}
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    Node(int key, int val, Node *next, Node *prev) : key(key), val(val), next(next), prev(prev) {}
};

class LRUCache {
public:
    int cap;
    unordered_map <int, Node*> ump;
    Node *dummyHead;
    Node *tail;

    LRUCache(int capacity) {
        cap = capacity;
        dummyHead = new Node();
        tail = dummyHead;
    }
    
    int get(int key) {
        int val = -1;
        if (ump.find(key) != ump.end()) {
            Node *node = ump[key];
            val = node->val;
            deleteNode(node);
            insertTail(key, val);
        }
        return val;
    }
    
    void put(int key, int value) {
        if (ump.find(key) != ump.end()) {
            Node *node = ump[key];
            deleteNode(node);
        }
        else if (ump.size() == cap) deleteNode(dummyHead->next);
        insertTail(key, value);
    }
    
    void deleteNode(Node *node) {
        if (node == tail) tail = node->prev;
        if (node->next) node->next->prev = node->prev;
        node->prev->next = node->next;
        ump.erase(node->key);
        delete(node);
    }

    void insertTail(int key, int value) {
        tail->next = new Node(key, value);
        tail->next->prev = tail;
        tail = tail->next;
        ump[key] = tail;
    }

    void printList() {
        Node *currNode = dummyHead->next;
        while (currNode) {
            cout << currNode->val << ' ';
            currNode = currNode->next;
        }
        cout << endl;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    LRUCache *lru = new LRUCache(2);

    cout << lru->get(2) << endl;
    lru->put(2, 6);
    cout << lru->get(2) << ' ' << lru->tail->val << endl;

    cout << lru->get(1) << endl;
    lru->put(1, 5);
    cout << lru->get(1) << ' ' << lru->tail->val << endl;

    lru->put(1, 2);
    cout << lru->get(1) << ' ' << lru->tail->val << endl;

    cout << lru->get(1) << ' ' << lru->tail->val << endl;
    cout << lru->get(2) << ' ' << lru->tail->val << endl;
    


    // cout << lru->get(1) << endl;
    // lru->put(3, 3);
    // cout << lru->get(2) << endl;
    // lru->put(4, 4);
    // cout << lru->get(1) << endl;
    // cout << lru->get(3) << endl;
    // cout << lru->get(4) << endl;
}