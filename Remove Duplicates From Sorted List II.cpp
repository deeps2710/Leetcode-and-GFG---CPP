/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //method 1: two pointers
        
        ListNode dummy(0);
        ListNode* curr=&dummy;
        dummy.next=head;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(temp->next!=nullptr && temp->val==temp->next->val){
                while(temp->next!=nullptr && temp->val==temp->next->val){
                    temp=temp->next;
                }
                curr->next=temp->next;
                temp=temp->next;
            }else{
                curr=temp;
                temp=temp->next;
            }
        }
        return dummy.next;
        
        //method 2: hashmap
        unordered_map<int, int> mp;
        ListNode* curr=head;
        while(curr){
            mp[curr->val]++;
            curr=curr->next;
        }
        ListNode dummy(0);
        curr=&dummy;
        ListNode* temp=head;

        while(temp){
            if(mp[temp->val]==1){
                curr->next=temp;
                curr=curr->next;
            }
            temp=temp->next;
        }
        curr->next=nullptr;
        return dummy.next;
    }
};
