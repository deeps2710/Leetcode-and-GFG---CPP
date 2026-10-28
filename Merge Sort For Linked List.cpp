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
    Node* merge(Node* a, Node* b){
        if(!a){
            return b;
        }
        if(!b){
            return a;
        }
        if(a->data<=b->data){
            a->next=merge(a->next,b);
            return a;
        }else{
            b->next=merge(a,b->next);
            return b;
        }
    }
    
    Node* mergeSort(Node* head) {
        if(!head || !head->next){
            return head;
        }
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        Node* right=slow->next;
        slow->next=NULL;
        
        Node* left=mergeSort(head);
        right=mergeSort(right);
        return merge(left, right);
    }
};
