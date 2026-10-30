/* Structure of Linked List Node
 struct Node {
    int data;
    struct Node* next;
}; */
struct Node* reverseList(struct Node* head) {
    struct Node* rev=NULL;
    struct Node* curr=head;
    struct Node* temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=rev;
        rev=curr;
        curr=temp;
    }
    return rev;
}
