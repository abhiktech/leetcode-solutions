class AllOne {
    
private:
    
    struct Node {
        int val;
        unordered_set<string> keys;
        Node* next;
        Node* prev;
    };
    
    Node* front;
    Node* back;
    
    // Stores the key-value pairs of keys and nodes corresponding to their values
    unordered_map<string, Node*> keyNode;
    
    // Stores key-value pairs of values and nodes storing that value
    unordered_map<int, Node*> valNode;
    
    void insertFront(Node* cur) {
        
        if(!front) {
            back = cur;
        } else {
            cur->next = front;
            front->prev = cur;
        }
        
        front = cur;
    }
    
    void insertAfter(Node* before, Node* n) {
        
        n->prev = before;
        n->next = before->next;
        
        if(before->next) {
            before->next->prev = n;
        } else {
            back = n;
        }
        
        before->next = n;
    }
    
    void insertBefore(Node* after, Node* n) {
        
        n->next = after;
        n->prev = after->prev;
        
        if(after->prev) {
            after->prev->next = n;
        } else {
            front = n;
        }
        
        after->prev = n;
    }
    
    void remove(Node* cur) {
        
        if(cur->prev && cur->next) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        } else if(cur->prev) {
            cur->prev->next = nullptr;
            back = cur->prev;
        } else if(cur->next) {
            cur->next->prev = nullptr;
            front = cur->next;
        } else {
            front = nullptr;
            back = nullptr;
        }
           
        cur->prev = nullptr;
        cur->next = nullptr;
        
    }
    
    string getOneElement(Node* cur) {
        
        for(auto& i : cur->keys) {
            return i;
        }
        
        return "";
    }
    
    
public:
    /** Initialize your data structure here. */
    AllOne() : front(nullptr), back(nullptr) {}
    
    ~AllOne() {
        for(auto& i : valNode) {
            delete i.second;
        }
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        
        if(keyNode.find(key) != keyNode.end()) {
            
            Node* oldNode = keyNode[key];
            oldNode->keys.erase(key);
            
            if(valNode.find(oldNode->val + 1) == valNode.end()) {
                valNode[oldNode->val + 1] = new Node{oldNode->val + 1, unordered_set<string>(), nullptr, nullptr};
                insertAfter(oldNode, valNode[oldNode->val + 1]);
            }
            
            valNode[oldNode->val + 1]->keys.insert(key);
            
            keyNode[key] = valNode[oldNode->val + 1];
            
            if(oldNode->keys.empty()) {
                valNode.erase(oldNode->val);
                remove(oldNode);
            }
        } else {
            
            if(valNode.find(1) == valNode.end()) {
                
                valNode[1] = new Node{1, unordered_set<string>(), nullptr, nullptr};
                
                insertFront(valNode[1]);
            }
            
            valNode[1]->keys.insert(key);
            keyNode[key] = valNode[1];
        }
        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        
        if(keyNode.find(key) == keyNode.end()) {
            return;
        }
        
        Node* oldNode = keyNode[key];
        oldNode->keys.erase(key);
        
        if(oldNode->val == 1) {
            keyNode.erase(key);
        } else {
        
            if(valNode.find(oldNode->val - 1) == valNode.end()) {
                valNode[oldNode->val - 1] = new Node{oldNode->val - 1, unordered_set<string>(), nullptr, nullptr};
                insertBefore(oldNode, valNode[oldNode->val - 1]); // TODO
            }
        
            valNode[oldNode->val - 1]->keys.insert(key);
            keyNode[key] = valNode[oldNode->val - 1];
        }
        if(oldNode->keys.empty()) {
            valNode.erase(oldNode->val);
            remove(oldNode);
        }
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
    
        if(!back) {
            return "";
        }
        
        return getOneElement(back); // TODO
        
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        
        if(!front) {
            return "";
        }
        
        return getOneElement(front);
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */