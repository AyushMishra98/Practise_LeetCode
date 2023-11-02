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
    int count=0;
    pair<int,int> calAverage(TreeNode* root){
    if(root == nullptr)
        return {0,0};
    pair<int,int> l=calAverage(root->left);
    pair<int,int> r=calAverage(root->right);
    
    int sum=root->val+l.first+r.first;
    int n=1+l.second+r.second;
    
    if(sum/n == root->val)
        count++;
    return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        calAverage(root);
        return count;
    }
};