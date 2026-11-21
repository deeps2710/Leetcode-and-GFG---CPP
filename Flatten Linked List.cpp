/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
    Node* mergeBottom(Node* a, Node* b){
        Node dummy(0);
        Node* tail=&dummy;
        while(a!=nullptr && b!=nullptr){
            Node* chosen;
            if(a->data<=b->data){
                chosen=a;
                a=a->bottom;
            }else{
                chosen=b;
                b=b->bottom;
            }
            chosen->next=nullptr;
            tail->bottom=chosen;
            tail=chosen;
        }
        Node* rem= a? a:b;
        while(rem!=nullptr){
            Node* nextNode=rem->bottom;
            rem->next=nullptr;
            tail->bottom=rem;
            tail=rem;
            rem=nextNode;
        }
        tail->bottom=nullptr;
        return dummy.bottom;
    }
    Node* flatten(Node* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node* right=flatten(head->next);
        head->next=nullptr;
        return mergeBottom(head, right);
    }
};
