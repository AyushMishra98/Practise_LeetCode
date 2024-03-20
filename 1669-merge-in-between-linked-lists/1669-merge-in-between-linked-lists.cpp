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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *res=list1;
        b=b-a;
        
        while(a>1){
            list1=list1->next;
            a--;
        }
        ListNode* temp=list1->next;
        list1->next=list2;
        while(list1->next != nullptr){
            list1=list1->next;
        }
        while(b>=0){
            temp=temp->next;
            b--;
        }
        list1->next=temp;
        return res;
    }
};