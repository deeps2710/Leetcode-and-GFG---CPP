/* Structure of a doubly link list node
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node* temp=head;
        for(int i=1; i<k; i++){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            return head;
        }
        Node* newHead=temp->next;
        Node* tail=newHead;
        while(tail->next!=nullptr){
            tail=tail->next;
        }
        temp->next=nullptr;
        newHead->prev=nullptr;
        tail->next=head;
        head->prev=tail;
        
        return newHead;
    }
};
