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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        int size=len/k;
        int extra=len%k;
        
        vector<ListNode*> ans(k,nullptr);
        temp=head;
        ListNode* prev=nullptr;
        for(int i=0; i<k; i++){
            ans[i]=temp;
            int currsize;
            if(extra>0){
                currsize=size+1;
                extra--;
            }else{
                currsize=size;
            }
            for(int j=0; j<currsize; j++){
                prev=temp;
                if(temp!=nullptr){
                    temp=temp->next;
                }
            }
            if(prev!=nullptr){
                prev->next=nullptr;
            }
        }
        return ans;
    }
};
