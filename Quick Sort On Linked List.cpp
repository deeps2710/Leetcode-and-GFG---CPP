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
    pair<Node*, Node*> solve(Node* head){
        if(head==nullptr){
            return {nullptr, nullptr};
        }
        if(head->next==nullptr){
            return {head, head};
        }
        //choose middle element as pivot
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        int pivot=slow->data;
        
        Node lessdummy(0);
        Node equaldummy(0);
        Node greatdummy(0);
        
        Node* lesstail=&lessdummy;
        Node* equaltail=&equaldummy;
        Node* greattail=&greatdummy;
        Node* curr=head;
        
        while(curr!=nullptr){
            Node* nextnode=curr->next;
            curr->next=nullptr;
            if(curr->data<pivot){
                lesstail->next=curr;
                lesstail=curr;
            }else if(curr->data==pivot){
                equaltail->next=curr;
                equaltail=curr;
            }else{
                greattail->next=curr;
                greattail=curr;
            }
            curr=nextnode;
        }
        auto left=solve(lessdummy.next);
        auto right=solve(greatdummy.next);
        
        Node* newHead=equaldummy.next;
        Node* newTail=equaltail;
        
        if(left.first!=nullptr){
            newHead=left.first;
            left.second->next=equaldummy.next;
        }
        if(right.first!=nullptr){
            equaltail->next=right.first;
            newTail=right.second;
        }
        return {newHead, newTail};
    }
    Node* quickSort(Node* head) {
        return solve(head).first;
    }
};
