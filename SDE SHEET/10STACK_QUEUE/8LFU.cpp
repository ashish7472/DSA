#include <bits/stdc++.h>
using namespace std;

// Node class represents a cache entry
class Node {
public:
    pair<int,int> val; // {key, value} pair
    int freq;          // Frequency of access (how many times this key was accessed)

    // Constructor to initialize node
    Node(pair<int,int> v) {
        val = v;
        freq = 1; // new node has frequency 1 initially
    }
};

// LFUCache class implementing Least Frequently Used Cache
class LFUCache {
private:
    int cap;            // Maximum capacity of the cache
    int minFreq;        // Minimum frequency of any key currently in cache
    unordered_map<int, Node*> keyNode;               // Map from key -> node (for O(1) access)
    unordered_map<int, list<Node*>> freqList;       // Map from frequency -> list of nodes with that frequency
    unordered_map<int, list<Node*>::iterator> keyIter; // Map from key -> iterator pointing to node in freqList (for O(1) removal)

    // Function to update frequency of a node when accessed or updated
    void updateFreq(Node* node) {
        int freq = node->freq;                     // Current frequency
        freqList[freq].erase(keyIter[node->val.first]); // Remove node from its current frequency list
        
        node->freq++;                              // Increment frequency
        freqList[node->freq].push_front(node);     // Add node to front of new frequency list (most recently used among same freq)
        keyIter[node->val.first] = freqList[node->freq].begin(); // Update iterator in keyIter map

        // If old frequency list becomes empty and was the minimum frequency, increment minFreq
        if(freqList[freq].empty() && freq == minFreq){
            minFreq++;
        }
    }

public:
    // Constructor: initializes LFU cache with given capacity
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0; // Initially, there is no key in cache
    }

    // Get the value for a key if present, otherwise return -1
    int get(int key) {
        if(!keyNode.count(key)) return -1; // Key not found
        Node* node = keyNode[key];         // Get node from keyNode map
        updateFreq(node);                  // Update its frequency
        return node->val.second;           // Return value
    }

    // Add or update key-value in cache
    void put(int key, int value) {
        if(cap == 0) return; // If cache capacity is 0, do nothing

        if(keyNode.count(key)) { // Key already exists
            Node* node = keyNode[key];
            node->val.second = value; // Update value
            updateFreq(node);         // Update frequency
        } else { // Key does not exist
            if(keyNode.size() == cap){ // Cache is full
                Node* lru = freqList[minFreq].back(); // Least frequently used & least recently used node
                freqList[minFreq].pop_back();        // Remove it from freq list
                keyIter.erase(lru->val.first);       // Remove from iterator map
                keyNode.erase(lru->val.first);       // Remove from key-node map
                delete lru;                          // Free memory
            }

            // Insert new node with frequency 1
            Node* node = new Node({key, value});
            keyNode[key] = node;                 // Add to key-node map
            freqList[1].push_front(node);        // Add to frequency list 1
            keyIter[key] = freqList[1].begin();  // Store iterator for O(1) removal
            minFreq = 1;                          // Reset minFreq to 1 for new node
        }
    }
};