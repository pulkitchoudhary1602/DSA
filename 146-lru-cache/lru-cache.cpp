class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int _key,int _val){
                key=_key;
                val=_val;
            }
        };
    Node* head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertnode(Node* node){
        Node*temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    void deletenode(Node* node){
        Node* prevdel=node->prev;
        Node* nextdel=node->next;
        prevdel->next=nextdel;
        nextdel->prev=prevdel;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node* node=mpp[key];
        deletenode(node);
        insertnode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deletenode(node);
            insertnode(node);
        }
        else{
            if(mpp.size()==cap){
                Node* node=tail->prev;
                deletenode(node);
                mpp.erase(node->key);
            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertnode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */