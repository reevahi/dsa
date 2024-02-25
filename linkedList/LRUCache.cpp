/*
@author github.com/iitzmahi
*/
struct DListNode {
    pair<int, int> val;
    DListNode* next;
    DListNode* prev;
    DListNode() {
        val = make_pair(0, 0);
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    int size;
    int counter;
    unordered_map<int, DListNode*> mp;
    DListNode* headDummy;
    DListNode* tailDummy;

public:
    LRUCache(int capacity) {
        headDummy = new DListNode();
        tailDummy = new DListNode();
        headDummy->next = tailDummy;
        tailDummy->prev = headDummy;
        size = capacity;
        counter = 0;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            DListNode* res = mp[key];
            res->prev->next = res->next;
            res->next->prev = res->prev;
            res->next = headDummy->next;
            res->prev = headDummy;
            headDummy->next = res;
            res->next->prev = res;
            return res->val.second;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            counter++;
            DListNode* temp = new DListNode();
            temp->val = make_pair(key, value);
            temp->next = headDummy->next;
            temp->prev = headDummy;
            headDummy->next->prev = temp;
            headDummy->next = temp;
            mp[key] = temp;
            if (counter > size) {
                mp.erase(tailDummy->prev->val.first);
                tailDummy->prev->prev->next = tailDummy;
                tailDummy->prev = tailDummy->prev->prev;
                counter--;
            }
        } else {
            DListNode* temp = mp[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->val.second = value;
            temp->next = headDummy->next;
            temp->prev = headDummy;
            headDummy->next->prev = temp;
            headDummy->next = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */