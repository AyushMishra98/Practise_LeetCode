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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *res=new ListNode(0);
        ListNode *ans=res;
        while(head!=nullptr){
            int sum=head->val;
            ListNode *temp=head->next;
            while(sum!=0 && temp!=nullptr){
                sum+=temp->val;
                temp=temp->next;
            }
            if(sum == 0){
                head=temp;
            }else{
                ListNode *curr=head->next;
                head->next=nullptr;
                res->next=head;
                res=res->next;
                head=curr;
            }
        }
        return ans->next;
    }
};