/*  Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0);
        Node* tail=&dummy;
        while(head1!=nullptr && head2!=nullptr){
            if(head1->data<=head2->data){
                tail->next=head1;
                head1=head1->next;
            }else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        //attach whichever list remains
        if(head1!=nullptr){
            tail->next=head1;
        }else{
            tail->next=head2;
        }
        return dummy.next;
    }
};
