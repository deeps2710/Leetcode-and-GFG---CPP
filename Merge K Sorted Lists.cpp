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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* temp=&dummy;
        while(a!=nullptr && b!=nullptr){
            if(a->val<=b->val){
                temp->next=a;
                a=a->next;
            }else{
                temp->next=b;
                b=b->next;
            }
            temp=temp->next;
        }

        temp->next=a!=nullptr?a:b;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr;
        for(ListNode* list:lists){
            head=mergeTwoLists(head,list);
        }
        return head;
    }
};
