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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res=head;
        while(head!=nullptr && head->next != nullptr){
            ListNode *temp=head;
            while(head->next!=nullptr && temp->val==head->next->val){
                head=head->next;
            }
            head=head->next;
            temp->next=head;
        }
        return res;
    }
};