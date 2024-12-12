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
    int value;
    Node *left;
    Node *right;
    Node() : key(-1), value(-1), left(nullptr), right(nullptr) {}
    Node(int key, int x) : key(key), value(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : value(x), left(left), right(right) {}
};

class LRUCache {
public:
    int cap;
    Node *head, *tail;
    unordered_map <int, Node*> ump;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->right = tail;
        tail->left = head;
    }

    int get(int key) {
        auto it = ump.find(key);
        if (it != ump.end()) {
            Node *tmp = it->second;
            ump.erase(key);
            deleteNode(tmp);
            addNode(tmp);

            ump[key] = head->right;
            return tmp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = ump.find(key);

        if (it != ump.end()) {
            Node *tmp = it->second;
            ump.erase(key);
            deleteNode(tmp);
        }
        if (cap == ump.size()) {
            ump.erase(tail->left->key);
            deleteNode(tail->left);
        }

        addNode(new Node(key, value));
        ump[key] = head->right;
    }

    void addNode(Node *node) {
        node->right = head->right;
        node->left = head;

        head->right->left = node;
        head->right = node;
    }

    void deleteNode(Node *node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    LRUCache *lru = new LRUCache(2);

    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1) << endl;
    lru->put(3, 3);
    cout << lru->get(2) << endl;
    lru->put(4, 4);
    cout << lru->get(1) << endl;
    cout << lru->get(3) << endl;
    cout << lru->get(4) << endl;
    
    




}