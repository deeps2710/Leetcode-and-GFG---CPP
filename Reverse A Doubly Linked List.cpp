/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* curr=head;
        Node* temp;
        while(temp!=nullptr){
            temp=curr->next;
            curr->next=curr->prev;
            curr->prev=temp;
            head=curr;
            curr=curr->prev;
            
        }
        return head;
    }
};
