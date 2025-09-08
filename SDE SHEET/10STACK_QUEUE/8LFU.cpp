class Node {
public:
    pair<int,int> val;
    int freq;
    Node(pair<int,int> v) {
        val = v;
        freq = 1;
    }
};

class LFUCache {
private:
    int cap;
    int minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, list<Node*>> freqList;
    unordered_map<int, list<Node*>::iterator> keyIter; //iterator give use O(1)

    void updateFreq(Node* node) {
        int freq = node->freq;
        freqList[freq].erase(keyIter[node->val.first]);
        
        node->freq++;
        freqList[node->freq].push_front(node);
        keyIter[node->val.first] = freqList[node->freq].begin();

        if(freqList[freq].empty() && freq == minFreq){
            minFreq++;
        }
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if(!keyNode.count(key)) return -1;
        Node* node = keyNode[key];
        updateFreq(node);
        return node->val.second;
    }

    void put(int key, int value) {
        if(cap == 0) return;

        if(keyNode.count(key)) { //keynode me key present to just update it's val and freq
            Node* node = keyNode[key];
            node->val.second = value;
            updateFreq(node);
        } else { //nhi present h keynode map me to insert krni hogi
            if(keyNode.size() == cap){ //agar max capacity full hogyi
                Node* lru = freqList[minFreq].back(); //tie ho gya isliye ab minfreq me back wale ko remove karo
                freqList[minFreq].pop_back();
                keyIter.erase(lru->val.first);
                keyNode.erase(lru->val.first);
                delete lru;
            }

            //if maxcap full nhi hui to add krdo front me
            Node* node = new Node({key, value});
            keyNode[key] = node;
            freqList[1].push_front(node);
            keyIter[key] = freqList[1].begin();
            minFreq = 1;
        }
    }
};
