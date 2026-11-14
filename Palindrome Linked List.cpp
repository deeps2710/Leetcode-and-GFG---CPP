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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        //find end of first half
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the second half
        ListNode* second=reverseList(slow->next);
        //compare both halves
        ListNode* p1=head;
        ListNode* p2=second;
        bool palindrome=true;
        while(p2!=nullptr){
            if(p1->val!=p2->val){
                palindrome=false;
                break;
            }
            p1=p1->next;
            p2=p2->next;
        }
        //restore original list
        slow->next=reverseList(second);
        return palindrome;
    }
};
