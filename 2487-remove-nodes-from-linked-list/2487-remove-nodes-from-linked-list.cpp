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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp=nullptr;
        while(head!=nullptr){
            ListNode *next_node=head->next;
            head->next=temp;
            temp=head;
            head=next_node;
        }
        return temp;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverseList(head);
        
        ListNode* curr=new ListNode(head->val);
        ListNode* res=curr;
        head=head->next;
        
        while(head!=nullptr){
            if(head->val >= curr->val){
                ListNode* temp=head->next;
                head->next=nullptr;
                curr->next=head;
                curr=curr->next;
                head=temp;
            }else{
                head=head->next;
            }
        }
        return reverseList(res);
    }
};