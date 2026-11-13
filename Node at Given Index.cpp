/* Node Structure
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    int getNode(Node* head, int k) {
        Node* temp=head;
        for(int i=1; i<k && temp!=nullptr; i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            return -1;
        }else{
            return temp->data;
        }
    }
};
