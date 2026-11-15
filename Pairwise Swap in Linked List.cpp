/* Structure of linked list Node
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
    Node* pairwiseSwap(Node* head) {
        Node dummy(0);
        dummy.next=head;
        Node* prev=&dummy;
        while(prev->next!=nullptr && prev->next->next!=nullptr){
            Node* first=prev->next;
            Node* second=first->next;
            //swap the pair
            first->next=second->next;
            second->next=first;
            prev->next=second;
            //move to the next pair
            prev=first;
        }
        return dummy.next;
    }
};
