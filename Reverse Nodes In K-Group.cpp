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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* groupPrev=&dummy;
        while(true){
            //step 1: find the kth node of current group
            ListNode* kth=groupPrev;
            for(int i=0; i<k && kth!=nullptr; i++){
                kth=kth->next;
            }
            //not enough nodes for another group
            if(kth==nullptr){
                break;
            }
            //step 2: save start of next group
            ListNode* groupNext=kth->next;
            //step 3: reverse k current nodes
            ListNode* prev=groupNext;
            ListNode* curr=groupPrev->next;
            while(curr!=groupNext){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            //step 4: reconnect the reversed group
            ListNode* oldHead=groupPrev->next;
            groupPrev->next=kth;
            //old head is now tail of the group
            groupPrev=oldHead;
        }
        return dummy.next;
    }
};
