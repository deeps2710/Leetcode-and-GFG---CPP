//METHOD 1: HASHMAP
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        Node* curr=head;
        //pass 1: copy every node
        while(curr!=nullptr){
            mp[curr]=new Node(curr->val);
            curr=curr->next;
        }
        //pass 2: copy pointer relationships
        curr=head;
        while(curr!=nullptr){
            mp[curr]->next=curr->next? mp[curr->next]:nullptr;
            mp[curr]->random=curr->random? mp[curr->random]:nullptr;
            curr=curr->next;
        }
        return mp[head];
    }
};




//METHOD 2: OPTIMAL NODE INTERLEAVING: insert each copy immediately after every original node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* curr=head;
        //pass 1: insert copies after originals
        while(curr!=nullptr){
            Node* copy=new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        //pass 2: set random pointers
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
