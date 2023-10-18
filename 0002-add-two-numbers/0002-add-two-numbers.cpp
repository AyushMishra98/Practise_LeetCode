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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        int carry=0;
        while(l1!=NULL ||l2!=NULL||carry){
            int curr_sum=0;
            if(l1!=NULL){
                curr_sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                curr_sum+=l2->val;
                l2=l2->next;
            }

            curr_sum+=carry;
            carry=curr_sum/10;
            curr_sum%=10;
            curr->next=new ListNode(curr_sum);
            curr=curr->next;
            
        }
        return dummy->next;
    }
};