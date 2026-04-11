class Node{
public:
    int val;
    int key;              // ✅ add key
    Node* next;
    Node* prev;

    Node(){
        val = 0;
        key = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {

private:
    int cap;
    unordered_map<int,Node*> um;
    Node* l;
    Node* r;

    // insert at end (before r)
    void i(int k, Node* node){
        node->key = k;

        node->prev = r->prev;
        node->next = r;

        r->prev->next = node;
        r->prev = node;

        um[k] = node;
    }

    // delete node
    void d(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        um.erase(node->key);
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        l = new Node();
        r = new Node();
        l->next = r;
        r->prev = l;
    }
    
    int get(int key) {
        if(um.find(key)==um.end()) return -1;

        Node* node = um[key];
        int v = node->val;

        d(node);        // remove
        i(key,node);    // move to MRU

        return v;
    }
    
    void put(int key, int value) {

        if(um.find(key)!=um.end()){
            Node* node = um[key];
            d(node);
            node->val = value;
            i(key,node);
            return;
        }

        if(um.size() >= cap){
            Node* lru = l->next;   // ✅ correct LRU
            d(lru);
            delete lru;
        }

        Node* node = new Node();
        node->val = value;
        i(key,node);
    }
};
