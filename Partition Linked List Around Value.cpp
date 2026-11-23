/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* partition(Node* head, int x) {
        Node lessdummy(0);
        Node equaldummy(0);
        Node greaterdummy(0);
        Node* lessTail=&lessdummy;
        Node* equalTail=&equaldummy;
        Node* greaterTail=&greaterdummy;
        Node* curr=head;
        
        while(curr!=nullptr){
            Node* nextnode=curr->next;
            curr->next=nullptr;
            if(curr->data<x){
                lessTail->next=curr;
                lessTail=curr;
            }else if(curr->data==x){
                equalTail->next=curr;
                equalTail=curr;
            }else{
                greaterTail->next=curr;
                greaterTail=curr;
            }
            curr=nextnode;
        }
        
        equalTail->next=greaterdummy.next;
        lessTail->next=equaldummy.next!=nullptr?equaldummy.next:greaterdummy.next;
        return lessdummy.next;
    }
};
