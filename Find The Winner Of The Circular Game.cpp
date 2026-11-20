class Solution {
private:
    struct Node{
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr){}
    };
public:
    int findTheWinner(int n, int k) {
        if(n<=0 || k<=0){
            return -1;
        }
        //create circular linked list of 1 to n
        Node* head= new Node(1);
        Node* tail=head;
        for(int i=2; i<=n; i++){
            tail->next=new Node(i);
            tail=tail->next;
        }
        tail->next=head;
        Node* curr=head;
        Node* prev=tail;
        while(curr->next!=curr){
            //move to kth person
            for(int i=1; i<k; i++){
                prev=curr;
                curr=curr->next;
            }
            //remove kth person
            prev->next=curr->next;
            Node* toDelete=curr;
            curr=curr->next;
            delete toDelete;
        }
        int winner=curr->val;
        delete curr;
        return winner;
    }
};
