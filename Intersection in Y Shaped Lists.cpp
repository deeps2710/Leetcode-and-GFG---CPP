/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* a=head1;
        Node* b=head2;
        while(a!=b){
            if(a==nullptr){
                a=head2;
            }else{
                a=a->next;
            }
            if(b==nullptr){
                b=head1;
            }else{
                b=b->next;
            }
        }
        return a;
    }
};
