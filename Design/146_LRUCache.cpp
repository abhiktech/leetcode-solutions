class LRUCache {
    
private:
    
    struct Node {
        int key;
        Node* prev;
        Node* next;
    };
    
    int capacity;
    int curNum;
    Node* front;
    Node* back;
    unordered_map<int, pair<int, Node*>> umap;
    
    void insertFront(Node* n) {
        if(!front) {
            back = n;
        } else {
            n->next = front;
            front->prev = n;
        }
        front = n;
    }
    
    void deleteBack() {
        if(front == back) {
            front = nullptr;
            back = nullptr;
        } else {
            back->prev->next = nullptr;
            Node* del = back;
            back = back->prev;
            delete del;
        }
    }
    
    void remove(Node* n) {
        
        if(n->prev && n->next) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        } else if(n->prev) {
            n->prev->next = nullptr;
            back = n->prev;
        } else if(n->next) {
            n->next->prev = nullptr;
            front = n->next;
        } else {
            front = nullptr;
            back = nullptr;
        }
        
        n->prev = nullptr;
        n->next = nullptr;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity), curNum(0), front(nullptr), back(nullptr){}
    
    ~LRUCache() {
        for(auto& i : umap) {
            delete i.second.second;
        }
    }
    
    int get(int key) {
        if(umap.find(key) != umap.end()) {
            Node* cur = umap[key].second;
            remove(cur);
            insertFront(cur);
            return umap[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()) {
            umap[key].first = value;
            Node* cur = umap[key].second;
            remove(cur);
            insertFront(cur);
        } else if(curNum < capacity) {
            Node* n = new Node{key, nullptr, nullptr};
            insertFront(n);
            umap[key] = make_pair(value, n);
            ++curNum;
        } else {
            umap.erase(back->key);
            deleteBack();
            Node* n = new Node{key, nullptr, nullptr};
            insertFront(n);
            umap[key] = make_pair(value, n);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */