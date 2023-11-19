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
    ListNode* doubleIt(ListNode* head) {
        head=reverseList(head);
        int carry=0;
        ListNode *curr=head;
        while(head!=nullptr){
            int temp=head->val*2+carry;
            head->val=temp%10;
            carry=temp/10;
            if(head->next == nullptr)
                break;
            head=head->next;
        }
        if(carry != 0)
            head->next=new ListNode(carry);
        return reverseList(curr);
    }
};