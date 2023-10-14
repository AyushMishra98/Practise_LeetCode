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
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        int even,odd,i;
        while(!q.empty()){
            int sz=q.size();
            even=-1,odd=-1;
            for(i=0;i<sz;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(flag){
                    if(curr->val%2 == 0)
                        return false;
                    else if(even == -1)
                        even=curr->val;
                    else if( even < curr->val)
                        even=curr->val;
                    else
                        return false;
                }else{
                    if(curr->val%2 != 0)
                        return false;
                    else if(odd == -1)
                        odd=curr->val;
                    else if( odd > curr->val)
                        odd=curr->val;
                    else
                        return false;
                }
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
            flag=!flag;
        }
        return true;
    }
};