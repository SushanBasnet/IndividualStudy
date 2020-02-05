
#include <unordered_map>

class Node {
public:
    
    int data;
    Node* next;
    Node* prev;
    Node(int _data): data(_data),prev(NULL), next(NULL) {}
};

class LinkedList {
public:
    
    Node* head;
    Node* tail;
    int length = 0;
    int capacity;
    
    LinkedList() {
        head=NULL;
        tail=NULL;
    }
    
    /* creates a new Node, prepends to linkedList and returns the address */
    Node* prepend(int num) {
        Node* newNode = new Node(num);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
        return newNode; 
    }
    
    //LRU is the last element, pops and returns the key so we can delete from map
    Node* popLRU() {
        if (length < capacity || tail==NULL) return NULL;
        // remove last element
        Node* tmp = tail;
        tail = tail->prev; //tail might be null

        if (tail) tail->next = NULL;
        length--;
        return tmp;
    }
    
    void bringFront(Node* n) {
        Node* pred = n->prev;
        if (pred==NULL) return; //already at front
        Node* succ = n->next;
        pred->next = succ;
        if (succ) {
            succ->prev = pred;
        } else {
            //no successor, was the last node
            tail = pred;
        }
        n->prev = NULL;
        n->next = head;
        head->prev = n;
        head = n;
    }
    
};

class LRUCache {
    LinkedList cache;
    unordered_map<int, Node*> addressMap;
    unordered_map<Node*, int> addressKey;

    
public:
    LRUCache(int capacity) {
        cache.capacity = capacity;
    }
    
    int get(int key) {
        auto it = addressMap.find(key);
        if (it != addressMap.end()) {
            cache.bringFront(it->second);
            return it->second->data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        //if already contain, update and bring to front
        auto it = addressMap.find(key);
        if (it != addressMap.end()) {
            it->second->data = value;
            cache.bringFront(it->second);
            return;
        }
        
        Node* tmp = cache.popLRU();
        if (tmp) {
            addressMap.erase(addressKey[tmp]);
        }
        // always puts - never runs out of capacity because LRU
        Node* newNode = cache.prepend(value);
        addressMap[key] = newNode;
        addressKey[newNode] = key;   //node address maps to key
        

    }  
};

/**
 */