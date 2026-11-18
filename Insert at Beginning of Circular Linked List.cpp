/* Structure of a Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/ 

class Solution {
  public:
    Node* insertAtBeginning(Node* tail, int key) {
        Node* node=new Node(key);
        if(tail==nullptr){
            node->next=node;
            return node;
        }
        node->next=tail->next;
        tail->next=node;
        return tail;
    }
};
