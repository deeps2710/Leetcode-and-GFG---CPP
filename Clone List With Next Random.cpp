/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* curr=head;
        //pass 1:insert copies after originals
        while(curr!=nullptr){
            Node* copy=new Node(curr->data);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        //pass 2:set random pointers
        curr=head;
        while(curr!=nullptr){
            Node* copy=curr->next;
            if(curr->random!=nullptr){
                copy->random=curr->random->next;
            }
            curr=copy->next;
        }
        
        //pass 3: separate original and copy
        Node* copyHead=head->next;
        curr=head;
        while(curr!=nullptr){
            Node* copy=curr->next;
            Node* originalNext=copy->next;
            
            //restore original list
            curr->next=originalNext;
            //build copied list
            copy->next=originalNext? originalNext->next:nullptr;
            curr=originalNext;
        }
        return copyHead;
    }
};
