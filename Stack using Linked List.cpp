/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class myStack {
  private:
    struct Node{
        int data;
        Node* next;
        Node(int x): data(x), next(nullptr){}
    };
    Node* top;
    int count;
  public:
    myStack() {
        top=nullptr;
        count=0;
    }

    bool isEmpty() {
        return top==nullptr;
    }

    void push(int x) {
        Node* node=new Node(x);
        node->next=top;
        top=node;
        count++;
    }

    void pop() {
        if(top==nullptr){
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
        count--;
    }

    int peek() {
        if(top==nullptr){
            return -1;
        }
        return top->data;
    }

    int size() {
        return count;
    }
};
