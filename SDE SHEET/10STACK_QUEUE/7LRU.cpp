#include <bits/stdc++.h>
using namespace std;

// Node class represents a single element in the doubly linked list
class Node {
public:
    pair<int,int> val; // Stores {key, value} pair
    Node* next;        // Pointer to next node in the list
    Node* prev;        // Pointer to previous node in the list

    // Constructor to initialize node with value
    Node(pair<int,int> v) {
        val = v;
        next = prev = NULL;
    }
};

// LRUCache class implementing Least Recently Used Cache
class LRUCache {
private:
    unordered_map<int, Node*> mp; // Map from key -> node in DLL (for O(1) access)
    Node *head, *tail;            // Dummy head and tail nodes of DLL
    int cap;                       // Maximum capacity of the cache

    // Function to remove a node from the linked list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Function to insert a node right after head (most recently used position)
    void insertAtHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    // Constructor: initializes LRUCache with given capacity
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node({-1,-1}); // Dummy head node
        tail = new Node({-1,-1}); // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    //2. Get the value of the key if it exists in cache, otherwise return -1
    int get(int key) {
        if(mp.count(key)) {       // Key exists in cache
            Node* node = mp[key];
            remove(node);         // Remove node from its current position
            insertAtHead(node);   // Move it to front (most recently used)
            return node->val.second;
        }
        return -1;                // Key not found
    }

    //1. Add a key-value pair to the cache, or update if key exists
    void put(int key, int value) {
        if(mp.count(key)) { 
            // Key already exists: update value and move to front
            Node* node = mp[key];
            node->val.second = value; // Update value
            remove(node);             // Remove from current position
            insertAtHead(node);       // Insert at front (MRU)
        } else { 
            // Key does not exist
            if(mp.size() == cap) { 
                // Cache is full: remove least recently used node (tail->prev)
                Node* last = tail->prev;
                remove(last);               // Remove from DLL
                mp.erase(last->val.first);  // Remove from map by using its key
                delete last;                // Free memory
            }
            // Add new node to front of DLL
            Node* node = new Node({key,value});
            insertAtHead(node);
            mp[key] = node; // Add to map
        }
    }
};
