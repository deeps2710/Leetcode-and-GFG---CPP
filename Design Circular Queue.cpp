class MyCircularQueue {
private:
    struct Node{
        int val;
        Node* next;

        Node(int x){
            val=x;
            next=nullptr;
        }
    };
    Node* tail;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        tail=nullptr;
        size=0;
        capacity=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        Node* newnode=new Node(value);
        if(tail==nullptr){
            tail=newnode;
            tail->next=tail;
        }else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        Node* head=tail->next;
        if(size==1){
            tail=nullptr;
        }else{
            tail->next=head->next;
        }
        delete head;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return tail->next->val;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return tail->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
