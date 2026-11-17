/* Structure of Doubly Linked List Node
class Node {
	public:
	int data;
	Node *next;
	Node *prev;
	
	Node(int val) {
		data = val;
		this->next = this->prev = nullptr;
	}
};*/

class Solution {
  public:
    Node* delPos(Node* head, int k) {
        if(head==nullptr || k<0){
            return head;
        }
        Node* curr=head;
        for(int i=1; i<k && curr!=nullptr; i++){
            curr=curr->next;
        }
        if(curr==nullptr){
            return head;
        }
        if(curr->prev!=nullptr){
            curr->prev->next=curr->next;
        }else{
            head=curr->next;
        }
        if(curr->next!=nullptr){
            curr->next->prev=curr->prev;
        }
        delete curr;
        return head;
    }
};
