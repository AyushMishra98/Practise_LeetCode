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
    int totalSum(TreeNode* root, int low, int high){
        if(root == nullptr)
            return 0;
        int sum=totalSum(root->left,low,high)+totalSum(root->right,low,high);
        if(low<=root->val && root->val<=high)
            sum+=root->val;
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return totalSum(root,low,high);
    }
};