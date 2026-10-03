struct Node{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List{
    int size;
    Node *head;
    Node *tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node){
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void removeNode(Node *delnode){
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int,Node*>keynode;
    map<int,List*>freqListMap;
    int maxsizeCache, minfreq, currsize;
public:
    LFUCache(int capacity) {
        maxsizeCache = capacity;
        minfreq = 0, currsize = 0;
    }
    void updateFreqListMap(Node *node){
        keynode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minfreq && freqListMap[node->cnt]->size == 0)minfreq++;

        List *nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()) 
            nextHigherFreqList = freqListMap[node->cnt+1];
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keynode[node->key] = node;
    }

    int get(int key) {
        if(keynode.find(key) != keynode.end()){
            Node *node = keynode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsizeCache == 0) return;
        if(keynode.find(key) != keynode.end()){
            Node *node = keynode[key];
            node->value = value;
            updateFreqListMap(node);
        }else{
            if(currsize == maxsizeCache){
                List *list = freqListMap[minfreq];
                keynode.erase(list->tail->prev->key);
                freqListMap[minfreq]->removeNode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq = 1;
            List *listfreq = new List();
            if(freqListMap.find(minfreq) != freqListMap.end()) listfreq = freqListMap[minfreq];
            Node *node = new Node(key,value);
            listfreq->addFront(node);
            keynode[key] = node;
            freqListMap[minfreq] = listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */