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
    int GCD(int a, int b){
        if(b==0){
            return a;
        }
        return GCD(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            ListNode* next=temp->next;
            int g=GCD(temp->val, next->val);
            ListNode* newNode= new ListNode(g);
            temp->next=newNode;
            newNode->next=next;
            temp=next;
        }
        return head;
    }
};
