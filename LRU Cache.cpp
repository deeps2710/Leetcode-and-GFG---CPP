class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
    };
    int capacity;
    unordered_map<int, Node*> mp;
    Node head;
    Node tail;
    //unlink a real node
    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    //insert immediately after dummy head
    void addFront(Node* node){
        node->next=head.next;
        node->prev=&head;
        head.next->prev=node;
        head.next=node;
    }
    //mark a node as MRU
    void moveToFront(Node* node){
        removeNode(node);
        addFront(node);
    }
public:
    LRUCache(int capacity):capacity(capacity),head(0,0),tail(0,0){
        head.next=&tail;
        tail.prev=&head;
    }
    
    int get(int key) {
        auto it=mp.find(key);
        if(it==mp.end()){
            return -1;
        }
        Node* node=it->second;
        moveToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity<=0){
            return;
        }
        auto it=mp.find(key);
        //existing key
        if(it!=mp.end()){
            Node* node=it->second;
            node->value=value;
            moveToFront(node);
            return;
        }
        //new key
        Node* node=new Node(key, value);
        mp[key]=node;
        addFront(node);
        //evict LRU if capacity exceeded
        if(mp.size()>capacity){
            Node* lru=tail.prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
