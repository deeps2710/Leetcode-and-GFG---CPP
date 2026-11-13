/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x<1 || head==nullptr){
            return head;
        }
        if(x==1){
            Node* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        Node* temp=head;
        for(int i=1; i<x-1 && temp!=nullptr; i++){
            temp=temp->next;
        }
        if(temp==nullptr || temp->next==nullptr){
            return head;
        }
        Node* toDelete=temp->next;
        temp->next=toDelete->next;
        delete toDelete;
        return head;
    }
};
