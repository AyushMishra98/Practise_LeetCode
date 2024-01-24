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
    bool isPalindrome(unordered_map<int,int>& m){
        bool flag=true;
        for(auto x:m){
            if(x.second%2 != 0){
                if(flag)
                    flag=false;
                else
                    return false;
            }
        }
        return true;
    }
    int traverse(TreeNode* root,unordered_map<int,int>& m){
        if(root->left == nullptr && root->right == nullptr){
            if(isPalindrome(m))
                return 1;
            return 0;
        }
        
        int temp=0;
        if(root->left != nullptr){
            m[root->left->val]++;
            temp+=traverse(root->left,m);
            m[root->left->val]--;
        }
        if(root->right != nullptr){
            m[root->right->val]++;
            temp+=traverse(root->right,m);
            m[root->right->val]--;
        }
        
        return temp;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == nullptr)
            return 0;
        unordered_map<int,int> m;
        m[root->val]++;
        return traverse(root,m);
    }
};