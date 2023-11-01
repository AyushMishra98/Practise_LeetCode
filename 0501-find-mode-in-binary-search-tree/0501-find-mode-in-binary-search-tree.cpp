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
    vector<int> res;
    int maxStreak=0;
    int currStreak=0;
    int currNum=0;
    void inorder(TreeNode* root){
        if(root == nullptr)
            return;
        inorder(root->left);
        
        int x=root->val;
        if(x == currNum)
                currStreak++;
            else{
                currStreak=1;
                currNum=x;
            }
            if(currStreak > maxStreak){
                res={};
                maxStreak=currStreak;
            }
            if(currStreak == maxStreak)
                res.push_back(x);
        
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};