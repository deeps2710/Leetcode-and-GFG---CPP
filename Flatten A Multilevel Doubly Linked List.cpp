/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node* head){
        Node* curr=head;
        Node* tail=head;
        while(curr!=nullptr){
            Node* next=curr->next;
            if(curr->child!=nullptr){
                //flatten child list recursively
                Node* childHead=curr->child;
                Node* childTail=dfs(childHead);

                curr->next=childHead;
                childHead->prev=curr;
                curr->child=nullptr;

                if(next!=nullptr){
                    childTail->next=next;
                    next->prev=childTail;
                }
                tail=childTail;
            }else{
                tail=curr;
            }
            curr=next;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        dfs(head);
        return head;
    }
};
