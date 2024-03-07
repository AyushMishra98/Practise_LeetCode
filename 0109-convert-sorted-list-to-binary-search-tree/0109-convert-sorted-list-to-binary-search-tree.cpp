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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return new TreeNode(head->val);
        
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *mid=slow;
        
        while(fast!=nullptr && fast->next!=nullptr){
            mid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        mid->next=nullptr;
        
        TreeNode *res=new TreeNode(slow->val);
        
        res->left=sortedListToBST(head);
        res->right=sortedListToBST(slow->next);
        
        return res;
    }
};