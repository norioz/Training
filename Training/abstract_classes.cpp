#include <iostream>
#include <map>
#include "abstract_classes.h"

using namespace std;

// START HACKERRANK LOCKED CODE
struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};
// END HACKERRANK LOCKED CODE

class LRUCache : public Cache {
public:
    void set (int k, int v) override
    {
        
    }
    
    int get (int k) override
    {

    }
};

int hackerrank::abstract_classes ()
{
    // START HACKERRANK LOCKED CODE
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0;i < n;i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
    // END HACKERRANK LOCKED CODE
}
