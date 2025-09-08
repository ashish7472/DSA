class Node{
public:
    pair<int,int> val;
    Node* next;
    Node* prev;
    Node(pair<int,int> v){
        val = v;
        next = prev = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    int cap;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node({-1,-1});
        tail = new Node({-1,-1});
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.count(key)){
            Node* node = mp[key];
            remove(node);
            insertAtHead(node);
            return node->val.second;
        }
        return -1;
    }

    void put(int key, int value) {
        if(mp.count(key)){ //key is present then just update it's value
            Node* node = mp[key];
            node->val.second = value;
            remove(node); //ab acc to lru this is least now delete it from here and add in head
            insertAtHead(node);
        } else { //key is not present 
            if(mp.size() == cap){ //if capacity is full then delete tail->prev and add new node in fornt
                Node* last = tail->prev;
                remove(last);
                mp.erase(last->val.first);//map se bhi remove kr
                delete last;
            }
            Node* node = new Node({key,value}); //add new node at front
            insertAtHead(node);
            mp[key] = node;
        }
    }
};