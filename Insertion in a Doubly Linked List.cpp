/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        if(p<0){
            return head;
        }
        
        Node* temp=head;
        for(int i=0; i<p && temp!=nullptr; i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            return head;
        }
        Node* node = new Node(x);
        Node* Next=temp->next;
        node->prev=temp;
        node->next=Next;
        temp->next=node;
        if(Next!=nullptr){
            Next->prev=node;
        }
        return head;
    }
};
