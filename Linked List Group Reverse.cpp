/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node dummy(0);
        dummy.next=head;
        Node* groupPrev=&dummy;
        while(groupPrev->next!=nullptr){
            Node* groupHead=groupPrev->next;
            Node* curr=groupHead;
            Node* prev=nullptr;
            int count=0;
            while(curr!=nullptr && count<k){
                Node* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                count++;
            }
            groupPrev->next=prev;
            groupHead->next=curr;
            groupPrev=groupHead;
        }
        return dummy.next;
    }
};
