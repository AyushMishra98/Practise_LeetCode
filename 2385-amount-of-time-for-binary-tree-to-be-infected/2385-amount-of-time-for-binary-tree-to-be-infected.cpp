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
    void convert(TreeNode *root,unordered_map<int,vector<int>>& m){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left != nullptr){
                m[node->val].push_back(node->left->val);
                m[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right != nullptr){
                m[node->val].push_back(node->right->val);
                m[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
    }
    int dfsRec(unordered_map<int,vector<int>>& m,unordered_set<int>& vis,int s){
        vis.insert(s);
        int res=0;
        for(auto x:m[s])
            if(vis.find(x) == vis.end())
                res=max(res,1+dfsRec(m,vis,x));
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int,vector<int>> m;
        convert(root,m);
        
        unordered_set<int> vis;
        return dfsRec(m,vis,start);
    }
};