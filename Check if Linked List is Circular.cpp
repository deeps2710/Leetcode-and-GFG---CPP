/* Linked List Node Structure
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
    bool isCircular(Node *head) {
        if(head==nullptr){
            return false;
        }
        Node* curr=head->next;
        while(curr!=nullptr && curr!=head){
            curr=curr->next;
        }
        return(curr==head);
    }
};
