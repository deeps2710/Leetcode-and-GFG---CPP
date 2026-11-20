/* Structure of Circular DLL node
class Node{
  public:
    int data;
    Node *next, *prev;

    Node(int x){
        data = x;
        next = prev = nullptr;
    }
};*/

class Solution {
  public:
    int findMiddle(Node* head) {
        if(head==nullptr){
            return -1;
        }
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=head && fast->next->next!=head){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};
