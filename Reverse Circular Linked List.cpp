/* Linked List Node Structure
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverseCircular(Node* head) {
        if(head==nullptr || head->next==head){
            return head;
        }
        Node* prev=head;
        Node* curr=head->next;
        while(curr!=head){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head->next=prev;
        return prev;
    }
};
