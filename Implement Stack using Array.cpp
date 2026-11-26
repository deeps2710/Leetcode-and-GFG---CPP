class myStack {
  private:
    vector<int> arr;
    int capacity;
    int top;
  public:
    myStack(int n) {
        capacity=max(0, n);
        arr.resize(capacity);
        top=-1;
    }

    bool isEmpty() {
        return top==-1;
    }

    bool isFull() {
        return top==capacity-1;
    }

    void push(int x) {
        if(top==capacity-1){
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop() {
        if(top==-1){
            return;
        }
        top--;
    }

    int peek() {
        if(top==-1){
            return -1;
        }
        return arr[top];
    }
};
