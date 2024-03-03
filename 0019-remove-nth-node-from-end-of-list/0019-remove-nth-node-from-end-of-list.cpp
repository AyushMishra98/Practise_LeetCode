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
    ListNode* reverse(ListNode* head) {
        ListNode *temp=nullptr;
        while(head!=nullptr){
            ListNode *next_node=head->next;
            head->next=temp;
            temp=head;
            head=next_node;
        }
        return temp;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverse(head);
        ListNode *ans=head;
        while(n>2){
            head=head->next;
            n--;
        }
        if(n == 1)
            ans=head->next;
        else
            head->next=head->next->next;
        ans=reverse(ans);
        return ans;
    }
};