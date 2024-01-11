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
    int res=INT_MIN;
    void maxDiff(TreeNode* root,int maxi,int mini){
        if(root->left == nullptr  && root->right == nullptr){
            maxi=max(maxi,root->val);
            mini=min(mini,root->val);
            res=max(res,maxi-mini);
            return;
        }
        if(root->left != nullptr)
            maxDiff(root->left,max(maxi,root->val),min(mini,root->val));
        if(root->right != nullptr)
            maxDiff(root->right,max(maxi,root->val),min(mini,root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr)
            return 0;
        maxDiff(root,root->val,root->val);
        return res;
    }
};