/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        if(head==nullptr || head->next==nullptr){
            return;
        }
        Node* slow=head;
        Node* fast=head;
        bool loop=false;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                loop=true;
                break;
            }
        }
        
        if(!loop){
            return;
        }
        //move slow back to head 
        slow=head;
        //special case: if loop starts right at the head
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=nullptr;
            return;
        }
        //general case: move slow and fast both 1 step together so that they meet at the starting point of the loop
        //we keep track of the node before the starting point
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=nullptr;
    }
};
