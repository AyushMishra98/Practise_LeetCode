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
    ListNode *temp;
    int n;
    Solution(ListNode* head) {
        temp=head;
        n=0;
        while(head!=nullptr){
            n++;
            head=head->next;
        }
    }
    int getRandom() {
        int x=rand()%n;
        ListNode *curr=temp;
        while(x >0){
            curr=curr->next;
            x--;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */