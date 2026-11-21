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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(a!=nullptr && b!=nullptr){
            if(a->val<=b->val){
                tail->next=a;
                a=a->next;
            }else{
                tail->next=b;
                b=b->next;
            }
            tail=tail->next;
        }
        tail->next=a? a:b;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        //empty list or one node
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        //find end of left half
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //split
        ListNode* right=slow->next;
        slow->next=nullptr;
        //sort both halves
        ListNode* leftsorted=sortList(head);
        ListNode* rightsorted=sortList(right);
        //merge sorted halves
        return merge(leftsorted, rightsorted);
    }
};
