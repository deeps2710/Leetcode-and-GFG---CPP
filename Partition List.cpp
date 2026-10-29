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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode(0);
        ListNode* great=new ListNode(0);
        ListNode* lessHead=less;
        ListNode* greatHead=great;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(temp->val<x){
                less->next=temp;
                less=less->next;
            }else{
                great->next=temp;
                great=great->next;
            }
            temp=temp->next;
        }
        great->next=nullptr;
        less->next=greatHead->next;
        ListNode* ansHead=lessHead->next;
        delete lessHead;
        delete greatHead;
        return ansHead;
    }
};
