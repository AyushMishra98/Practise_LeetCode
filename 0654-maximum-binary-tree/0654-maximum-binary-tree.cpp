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
    TreeNode* newNode(vector<int>& nums,int low,int high){
        if(low>high)
            return nullptr;
        int idx=low;
        for(int i=low+1;i<=high;i++)
            if(nums[i]>nums[idx])
                idx=i;
        TreeNode* node=new TreeNode(nums[idx]);
        if(idx-1>=low)
            node->left=newNode(nums,low,idx-1);
        if(idx+1<=high)
            node->right=newNode(nums,idx+1,high);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int idx=0;
        for(int i=1;i<nums.size();i++)
            if(nums[i]>nums[idx])
                idx=i;
        TreeNode* node=new TreeNode(nums[idx]);
        node->left=newNode(nums,0,idx-1);
        node->right=newNode(nums,idx+1,nums.size()-1);
        return node;
    }
};