/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node ==  nullptr)
            return nullptr;
        bool vis[105]={false};
        
        Node* res=new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        vis[node->val]=true;
        
        unordered_map<Node*,Node*> m;
        m[node]=res;
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            for(auto x:temp->neighbors){
                if(vis[x->val] == false){
                    Node* curr=new Node(x->val);
                    m[x]=curr;
                    
                    vis[x->val]=true;
                    q.push(x);
                }
                 m[temp]->neighbors.push_back(m[x]);
            }
        }
        return res;
    }
};