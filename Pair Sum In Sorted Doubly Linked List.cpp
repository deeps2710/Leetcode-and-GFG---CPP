/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        vector<vector<int>> ans;
        if(head==nullptr){
            return ans;
        }
        Node* p1=head;
        Node* p2=head;
        
        while(p2->next!=nullptr){
            p2=p2->next;
        }
        
        while(p1!=p2 &&  p1->prev!=p2){
            int sum=p1->data+p2->data;
            if(sum==target){
                ans.push_back({p1->data, p2->data});
                p1=p1->next;
                p2=p2->prev;
            }else if(sum<target){
                p1=p1->next;
            }else{
                p2=p2->prev;
            }
        }
        return ans;
    }
};
