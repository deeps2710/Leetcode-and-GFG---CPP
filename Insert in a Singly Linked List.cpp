/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
}; */

class Solution {
  public:
    Node* insertPos(Node* head, int pos, int val) {
        if(pos<1){
            return head;
        }
        if(pos==1){
            Node* newnode=new Node(val);
            newnode->next=head;
            return newnode;
        }
        Node* temp=head;
        for(int i=1; i<pos-1 && temp!=nullptr; i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            return head;
        }
        Node* newnode=new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
    }
};
